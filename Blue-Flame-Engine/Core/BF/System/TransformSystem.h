#pragma once
#include <vector>
#include <thread>
#include "BF/System/Transform.h"
#include "BF/System/TransformThreadWorker.h"
#include "BF/ECS/ISystem.h"
#include "BF/Common.h"
#include "BF/System/RenderableTransform.h"

namespace BF
{
	namespace Application
	{
		class App;
	}
	namespace ECS
	{
		class GameObject;
	}

	namespace System
	{
		class BFE_API TransformSystem : public BF::ECS::ISystem
		{
			friend class BF::Application::App;
			friend class BF::ECS::GameObject;
			friend class BF::Application::Scene;

		private:
			//std::thread t;
			BF::Application::App& app;
			bool newTransformAdded;
			std::vector<Transform*>* transforms;
			std::vector<TransformThreadWorker*> transformThreadWorkers;
			std::vector<std::thread> threads;
			//std::vector<Transformable*> transformable;

		public:
			TransformSystem(BF::Application::App& app);
			TransformSystem(TransformSystem& other);
			~TransformSystem();

		private:
			void Initialize()			  override;
			void Load()					  override;
			void PostLoad()				  override;
			void Update(double deltaTime) override;
			void Render()				  override;

			void AddTransform(Transform* transform);
			void RemoveTransform(Transform* transform);

			 TransformSystem& operator=(TransformSystem& right);

			 void UpdateThreadCount();
		};
	}
}