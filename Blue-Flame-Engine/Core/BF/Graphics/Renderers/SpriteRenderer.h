#pragma once
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
				public:
					enum class SubmitType { StaticSubmit, DynamicSubmit };

				private:
					const API::Shader& shader;
					API::VertexBuffer vertexBuffer;
					API::IndexBuffer* indexBuffer;
					API::VertexBufferLayout vertexBufferLayout;

					SpriteBuffer* spriteBuffer;
					unsigned int indexCount;

					SubmitType submitType;
					bool submitSprite;

					std::vector<const API::Texture2D*> textures;

				public:
					SpriteRenderer(const API::Shader& shader);
					~SpriteRenderer();

					void Initialize();
					void Begin(SubmitType submitType);
					void Render(const Sprite& sprite);
					void RenderRectangle(const Math::Rectangle& rectangle, const Math::Vector4& Color);
					void RenderText(const Fonts::FontAtlas& fontAtlas, const std::string& text, Math::Vector3 position, const Math::Vector4& color);
					void End();

				private:
					void CalculateUV(const API::Texture2D* texture, const Math::Rectangle& scissorRectangle, Math::Vector2* topLeft, Math::Vector2* topRight, Math::Vector2* bottomRight, Math::Vector2* bottomLeft);
					float FindTexture(const API::Texture2D* texture);
			};
		}
	}
}