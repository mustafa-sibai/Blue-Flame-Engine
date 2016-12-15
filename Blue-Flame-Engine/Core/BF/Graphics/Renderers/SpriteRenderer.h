#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/Renderers/Sprite.h"
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
					void Submit(const Sprite& sprite);
					void End();

				private:
					void CalculateUV(const Sprite& sprite, Math::Vector2* topLeft, Math::Vector2* topRight, Math::Vector2* bottomRight, Math::Vector2* bottomLeft);
					float FindTexture(const API::Texture2D* texture);
			};
		}
	}
}