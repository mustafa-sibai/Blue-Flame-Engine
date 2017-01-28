#pragma once
#include "BF/Graphics/API/ConstentBuffer.h"
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/Renderers/Sprite.h"
#include "BF/Graphics/Fonts/FontAtlas.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API SpriteRenderer
			{
				private:
					struct SystemBuffer
					{
						Math::Matrix4 modelMatrix;
						Math::Matrix4 viewMatrix;
						Math::Matrix4 projectionMatrix;
					} systemBuffer;

				public:
					enum class SubmitType { StaticSubmit, DynamicSubmit };
					enum class SortingOrder { None, BackToFront, FrontToBack };

				private:
					API::Shader shader;
					API::ConstentBuffer constentBuffer;
					API::VertexBuffer vertexBuffer;
					API::IndexBuffer* indexBuffer;
					API::VertexBufferLayout vertexBufferLayout;

					SpriteBuffer* spriteBuffer;
					unsigned int indexCount;

					SubmitType submitType;
					SortingOrder sortingOrder;
					bool submitSprite;

					std::vector<Sprite*> sprites;
					std::vector<const API::Texture2D*> textures;

				public:
					SpriteRenderer();
					~SpriteRenderer();

					void Initialize();
					void Begin(SubmitType submitType, SortingOrder sortingOrder);
					void Render(Sprite& sprite);
					void RenderRectangle(const Math::Rectangle& rectangle, const Math::Vector4& Color);
					void RenderText(const Fonts::FontAtlas& fontAtlas, const std::string& text, const Math::Vector3& position, const Math::Vector4& color);
					void End();

					inline const API::Shader& GetShader() const { return shader; }

				private:
					void MapBuffer();
					void CalculateUV(const API::Texture2D* texture, const Math::Rectangle& scissorRectangle, Math::Vector2* topLeft, Math::Vector2* topRight, Math::Vector2* bottomRight, Math::Vector2* bottomLeft);
					float FindTexture(const API::Texture2D* texture);
			};
		}
	}
}