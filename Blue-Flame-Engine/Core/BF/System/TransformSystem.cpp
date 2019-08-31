#include "TransformSystem.h"
#include "BF/Math/Matrix4.h"
#include "BF/ECS/GameObject.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/IRenderable.h"
#include "BF/System/Debug.h"
#include "BF/Math/Math.h"
#include "BF/Application/App.h"

#define THREAD_MAX_TRANSFORMS 100000

namespace BF
{
	namespace System
	{
		using namespace BF::Application;
		using namespace BF::Math;
		using namespace BF::Graphics::Renderers::SpriteRendererComponents;

		TransformSystem::TransformSystem(App& app) :
			app(app), newTransformAdded(false)
		{
		}

		TransformSystem::TransformSystem(TransformSystem& other)
		{
		}

		TransformSystem::~TransformSystem()
		{
		}

		void TransformSystem::Initialize()
		{
		}

		void TransformSystem::Load()
		{
		}

		void TransformSystem::PostLoad()
		{
		}

		void TransformSystem::Update(double deltaTime)
		{
			//			enum class FrameState { None, StartUpdating, WaitingToFinishUpdating, FinishedUpdating, StartRendering };

			for (size_t i = 0; i < transformThreadWorkers.size(); i++)
			{
				if (transformThreadWorkers[i]->state == TransformThreadWorker::State::FinishedUpdatingTransforms)
					app.frameState = App::FrameState::StartRendering;
				else
				{
					app.frameState = App::FrameState::WaitingToFinishUpdating;
					break;
				}
			}

			if (app.frameState == App::FrameState::StartUpdating)
			{
				if (newTransformAdded)
				{
					UpdateThreadCount();
					newTransformAdded = false;
				}

				for (size_t i = 0; i < transformThreadWorkers.size(); i++)
					transformThreadWorkers[i]->state = TransformThreadWorker::State::UpdatingTransformsInProgress;
			}
		}

		void TransformSystem::Render()
		{
		}

		void TransformSystem::AddTransform(Transform* transform)
		{
			transforms->emplace_back(transform);
			newTransformAdded = true;
		}

		void TransformSystem::RemoveTransform(Transform* transform)
		{
		}

		TransformSystem& TransformSystem::operator=(TransformSystem& right)
		{
			return right;
		}

		void TransformSystem::UpdateThreadCount()
		{
			int totalThreadsNeeded = ceil((double)transforms->size() / (double)THREAD_MAX_TRANSFORMS);
			int currentThread = 0;

			for (size_t i = 0; i < totalThreadsNeeded; i++)
			{
				int minRange = currentThread++ * THREAD_MAX_TRANSFORMS;
				int maxRange = Min((int)transforms->size(), currentThread * THREAD_MAX_TRANSFORMS);

				if (totalThreadsNeeded > transformThreadWorkers.size())
				{
					transformThreadWorkers.emplace_back(new TransformThreadWorker(minRange, maxRange, TransformThreadWorker::State::FrameInProgress));
					threads.emplace_back(std::thread(TransformThreadWorker::Execute, transforms, transformThreadWorkers[i]));
				}

				(*transformThreadWorkers[currentThread - 1]).beginning = minRange;
				(*transformThreadWorkers[currentThread - 1]).end = maxRange;
			}
		}
	}
}