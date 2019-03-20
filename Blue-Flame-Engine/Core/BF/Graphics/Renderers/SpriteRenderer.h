#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/Fonts/Font.h"
#include "BF/Graphics/Color.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/RegularPolygon.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/LineShape.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Text.h"
#include "BF/Graphics/Renderers/Renderer.h"
#include "BF/Graphics/Renderers/RenderLayerManager.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API SpriteRenderer : public Renderer
			{
				friend class BF::Graphics::Renderers::RenderPipeline;

			private:
				//BF::Application::Scene& scene;

				BF::Graphics::API::Shader shader;
				BF::Graphics::API::VertexBuffer vertexBuffer;
				BF::Graphics::API::IndexBuffer indexBuffer;
				BF::Graphics::API::VertexBufferLayout vertexBufferLayout;

				BF::Graphics::Renderers::SpriteRendererComponents::SpriteBuffer* spriteBuffer;
				unsigned int indexCount;

				//std::vector<BF::Graphics::Renderers::SpriteRendererComponents::IRenderable*> renderables;
				//std::vector<Renderable*> removeList;
				//int nullCount;

				//SubmitType submitType;

				bool submitSprite;//, newDrawCall;
				int totalDrawCalls;

				static const BF::Graphics::API::Texture2D* currentBoundTexture;

			public:
				//enum class SubmitType { StaticSubmit, DynamicSubmit };
				BF::Graphics::Renderers::RenderLayerManager renderLayerManager;

			public:
				SpriteRenderer();
				~SpriteRenderer();

				void Initialize() override;

				//void Submit(Renderable& renderable);
				//void Remove(Renderable& renderable);

				void Render() override;

				//void Begin(SubmitType submitType, SortingOrder sortingOrder);
				//void Render(const Renderable& renderable);
				//void Render(Renderable&&) = delete;
				//void End();

				void SetScissor(const BF::Math::Rectangle& rectangle);

				inline const BF::Graphics::API::Shader& GetShader() const { return shader; }

				//SpriteRenderer& operator=(const SpriteRenderer& spriteRenderer);

			private:
				void MapLineBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::LineShape* lineShape);
				void MapPolygonBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::RegularPolygon* regularPolygon);
				void MapSpriteBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::Sprite* sprite);
				void MapTextBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::Text* text);
				void MapBuffer();
				void CalculateUV(const BF::Graphics::API::Texture2D* texture, const BF::Math::Rectangle& scissorRectangle, BF::Math::Vector2f* topLeft, BF::Math::Vector2f* topRight, BF::Math::Vector2f* bottomRight, BF::Math::Vector2f* bottomLeft);
			};
		}
	}
}