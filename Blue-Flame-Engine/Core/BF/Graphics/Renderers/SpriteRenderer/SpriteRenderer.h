#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/Renderers/SpriteRenderer/Sprite.h"
#include "BF/Graphics/Fonts/Font.h"
#include "BF/Graphics/Color.h"
#include "BF/Graphics/Renderers/SpriteRenderer/LineShape.h"
#include "BF/Graphics/Renderers/SpriteRenderer/RegularPolygon.h"
#include "BF/Graphics/Renderers/SpriteRenderer/Text.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class LayerManager;
		}
	}

	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API SpriteRenderer
			{
				/*public:
					enum class SubmitType { StaticSubmit, DynamicSubmit };
					enum class SortingOrder { Null, BackToFront, FrontToBack };*/

				private:
					//BF::Application::Scene& scene;

					BF::Graphics::API::Shader shader;
					BF::Graphics::API::VertexBuffer vertexBuffer;
					BF::Graphics::API::IndexBuffer indexBuffer;
					BF::Graphics::API::VertexBufferLayout vertexBufferLayout;

					SpriteBuffer* spriteBuffer;
					unsigned int indexCount;

					BF::Application::Layers::LayerManager* layerManager;

					//std::vector<BF::Application::Layers::Layer>& layers;

					//std::vector<Renderable*> renderables;
					//std::vector<Renderable*> removeList;
					//int nullCount;

					//SubmitType submitType;
					//SortingOrder sortingOrder;
					bool submitSprite, newDrawCall;

					static const BF::Graphics::API::Texture2D* currentBoundTexture;

				public:
					SpriteRenderer();
					~SpriteRenderer();

					void Initialize(BF::Application::Layers::LayerManager& layerManager);

					//void Submit(Renderable& renderable);
					//void Remove(Renderable& renderable);
					void Render(/*SortingOrder sortingOrder*/);

					//void Begin(SubmitType submitType, SortingOrder sortingOrder);
					//void Render(const Renderable& renderable);
					//void Render(Renderable&&) = delete;
					//void End();

					void SetScissor(const BF::Math::Rectangle& rectangle);

					inline const BF::Graphics::API::Shader& GetShader() const { return shader; }

					//SpriteRenderer& operator=(const SpriteRenderer& spriteRenderer);

				private:
					void MapLineBuffer(const LineShape& lineShape);
					void MapPolygonBuffer(const RegularPolygon& regularPolygon);
					void MapSpriteBuffer(const Sprite& sprite);
					void MapTextBuffer(const Text& text);
					void MapBuffer();
					void CalculateUV(const BF::Graphics::API::Texture2D* texture, const BF::Math::Rectangle& scissorRectangle, BF::Math::Vector2f* topLeft, BF::Math::Vector2f* topRight, BF::Math::Vector2f* bottomRight, BF::Math::Vector2f* bottomLeft);
			};
		}
	}
}