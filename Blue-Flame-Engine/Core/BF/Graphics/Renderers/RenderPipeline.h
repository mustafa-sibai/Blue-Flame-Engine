#pragma once
#include <vector>
#include "BF/ECS/Component.h"
#include "BF/Graphics/ConstantBufferManager.h"
#include "BF/Graphics/CameraManager.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/Renderers/ForwardRenderer.h"
#include "BF/Graphics/Renderers/SkyboxRenderer.h"
#include "BF/Graphics/Renderers/PostProcessing.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API RenderPipeline
			{
				friend class BF::Application::App;
				friend class BF::ECS::GameObject;

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
				void Initialize();
				void Load();
				void PostLoad();
				void Update();
				void Render();

				void AddRenderable(BF::ECS::IComponent* component);
				void RemoveRenderable(BF::ECS::IComponent* component);
			};
		}
	}
}