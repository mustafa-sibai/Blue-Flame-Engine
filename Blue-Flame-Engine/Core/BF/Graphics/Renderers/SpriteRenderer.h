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

				public:
					//enum class SubmitType { StaticSubmit, DynamicSubmit };
					enum class SortingOrder { BackToFront };

				private:
					//BF::Application::Scene& scene;

					BF::Graphics::API::Shader shader;
					BF::Graphics::API::VertexBuffer vertexBuffer;
					BF::Graphics::API::IndexBuffer indexBuffer;
					BF::Graphics::API::VertexBufferLayout vertexBufferLayout;

					SpriteBuffer* spriteBuffer;
					unsigned int indexCount;

					std::vector<Renderable*> renderables;
					//std::vector<Renderable*> removeList;
					//int nullCount;

					//SubmitType submitType;
					SortingOrder sortingOrder;
					bool submitSprite, newDrawCall;

					static const BF::Graphics::API::Texture2D* currentBoundTexture;

				public:
					SpriteRenderer();
					~SpriteRenderer();

					void Initialize() override;

					//void Submit(Renderable& renderable);
					//void Remove(Renderable& renderable);

					void SetSortingOrder(SortingOrder sortingOrder);
					void Render() override;

					//void Begin(SubmitType submitType, SortingOrder sortingOrder);
					//void Render(const Renderable& renderable);
					//void Render(Renderable&&) = delete;
					//void End();

					void SetScissor(const BF::Math::Rectangle& rectangle);

					inline SortingOrder GetSortingOrder() const { return sortingOrder; }
					inline const BF::Graphics::API::Shader& GetShader() const { return shader; }

					//SpriteRenderer& operator=(const SpriteRenderer& spriteRenderer);

				private:
					void MapLineBuffer(const LineShape* lineShape);
					void MapPolygonBuffer(const RegularPolygon* regularPolygon);
					void MapSpriteBuffer(const Sprite* sprite);
					void MapTextBuffer(const Text* text);
					void MapBuffer();
					void CalculateUV(const BF::Graphics::API::Texture2D* texture, const BF::Math::Rectangle& scissorRectangle, BF::Math::Vector2f* topLeft, BF::Math::Vector2f* topRight, BF::Math::Vector2f* bottomRight, BF::Math::Vector2f* bottomLeft);
			};
		}
	}
}