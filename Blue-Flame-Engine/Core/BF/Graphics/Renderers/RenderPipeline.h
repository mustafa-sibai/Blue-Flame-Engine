#pragma once
#include <vector>
#include "BF/ECS/Component.h"
#include "BF/ECS/ISystem.h"
#include "BF/Graphics/ConstantBufferManager.h"
#include "BF/Graphics/CameraManager.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/Renderers/ForwardRenderer.h"
#include "BF/Graphics/Renderers/SkyboxRenderer.h"
#include "BF/Graphics/Renderers/PostProcessing.h"
#include "BF/Debug/Debug.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class GUISystem;
		}

		namespace Animation
		{
			class AnimationSystem;
		}

		namespace Renderers
		{
			class BFE_API RenderPipeline : public BF::ECS::ISystem
			{
				friend class BF::Application::App;
				friend class BF::ECS::GameObject;
				friend class BF::Graphics::GUI::GUISystem;
				friend class BF::Graphics::Animation::AnimationSystem;

			private:
				BF::Graphics::CameraManager& cameraManager;
				BF::Graphics::ConstantBufferManager& constantBufferManager;
				
				BF::Graphics::Renderers::ForwardRenderer* forwardRenderer;
				BF::Graphics::Renderers::SkyboxRenderer*  skyboxRenderer;
				BF::Graphics::Renderers::PostProcessing*  postProcessing;

			public:
				BF::Graphics::Renderers::SpriteRenderer*  spriteRenderer;

			public:
				RenderPipeline(BF::Graphics::ConstantBufferManager& constantBufferManager, BF::Graphics::CameraManager& cameraManager);
				~RenderPipeline();

			private:
				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void AddRenderable(BF::ECS::IComponent* component);
				void RemoveRenderable(BF::ECS::IComponent* component);
			};
		}
	}
}