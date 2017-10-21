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
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API SpriteRenderer
			{
				public:
					enum class SubmitType { StaticSubmit, DynamicSubmit };
					enum class SortingOrder { Null, BackToFront, FrontToBack };

				private:
					API::Shader shader;
					API::VertexBuffer vertexBuffer;
					API::IndexBuffer indexBuffer;
					API::VertexBufferLayout vertexBufferLayout;

					SpriteBuffer* spriteBuffer;
					unsigned int indexCount;

					std::vector<const Renderable*> renderables;

					SubmitType submitType;
					SortingOrder sortingOrder;
					bool submitSprite, newDrawCall;

					static const BF::Graphics::API::Texture2D* currentBoundTexture;

				public:
					SpriteRenderer();
					~SpriteRenderer();

					void Initialize();
					void Begin(SubmitType submitType, SortingOrder sortingOrder);
					void Render(const Renderable& renderable);
					void Render(Renderable&&) = delete;
					void End();

					void SetScissor(const Math::Rectangle& rectangle);

					inline const API::Shader& GetShader() const { return shader; }

					SpriteRenderer& operator=(const SpriteRenderer& spriteRenderer);

				private:
					void MapLineBuffer(const LineShape& lineShape);
					void MapPolygonBuffer(const RegularPolygon& regularPolygon);
					void MapSpriteBuffer(const Sprite& sprite);
					void MapTextBuffer(const Text& text);
					void MapBuffer();
					void CalculateUV(const API::Texture2D* texture, const Math::Rectangle& scissorRectangle, Math::Vector2* topLeft, Math::Vector2* topRight, Math::Vector2* bottomRight, Math::Vector2* bottomLeft);
			};
		}
	}
}