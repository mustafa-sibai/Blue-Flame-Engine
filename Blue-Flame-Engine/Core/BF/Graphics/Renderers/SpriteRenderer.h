#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/Fonts/Font.h"
#include "BF/Graphics/Color.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/RegularPolygon.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/RectangleShape.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/LineShape.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Text.h"
#include "BF/Graphics/Renderers/IRenderer.h"
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
			class BFE_API SpriteRenderer : public BF::Graphics::Renderers::IRenderer
			{
				friend class BF::Graphics::Renderers::RenderPipeline;

			private:
				BF::Graphics::API::Shader shader;
				BF::Graphics::API::VertexBuffer vertexBuffer;
				BF::Graphics::API::IndexBuffer indexBuffer;
				BF::Graphics::API::VertexBufferLayout vertexBufferLayout;

				BF::Graphics::Renderers::SpriteRendererComponents::SpriteBuffer* spriteBuffer;
				unsigned int indexCount;

				bool submitSprite;
				int totalDrawCalls;

				std::vector<BF::Math::Vector2i> corners;

				static const BF::Graphics::API::Texture2D* currentBoundTexture;

			public:
				BF::Graphics::Renderers::RenderLayerManager renderLayerManager;

			public:
				SpriteRenderer();
				~SpriteRenderer();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void SetScissor(const BF::Math::Rectangle& rectangle);

				inline const BF::Graphics::API::Shader& GetShader() const { return shader; }

			private:
				void MapLineBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::LineShape* lineShape);
				void MapRectangleShapeBuffer(BF::Graphics::Renderers::SpriteRendererComponents::RectangleShape* rectangleShape);
				void MapRegularPolygonBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::RegularPolygon* regularPolygon);
				void MapSpriteBuffer(const BF::Graphics::Renderers::SpriteRendererComponents::Sprite* sprite);
				void MapTextBuffer(BF::Graphics::Renderers::SpriteRendererComponents::Text* text);
				void MapBuffer();
				void CalculateUV(const BF::Graphics::API::Texture2D* texture, const BF::Math::Rectangle& scissorRectangle, BF::Math::Vector2f* topLeft, BF::Math::Vector2f* topRight, BF::Math::Vector2f* bottomRight, BF::Math::Vector2f* bottomLeft);
			};
		}
	}
}