#pragma once
#include <vector>
#include "BF/ECS/Component.h"
#include "BF/Graphics/CameraManager.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/Renderers/ForwardRenderer.h"
#include "BF/Graphics/Renderers/SkyboxRenderer.h"
#include "BF/Graphics/Renderers/PostProcessing.h"
#include "Renderer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API RenderPipeline
			{
			private:
				CameraManager& cameraManager;
				SpriteRenderer*  spriteRenderer;
				ForwardRenderer* forwardRenderer;
				SkyboxRenderer*  skyboxRenderer;
				PostProcessing*  postProcessing;

			public:
				RenderPipeline(CameraManager& cameraManager);
				~RenderPipeline();

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