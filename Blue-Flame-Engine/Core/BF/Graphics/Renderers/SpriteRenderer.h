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
					enum class SubmitType { None = 0, StaticSubmit, DynamicSubmit };

				private:
					API::Context* context;
					API::Shader* shader;
					API::VertexBuffer* vertexBuffer;
					API::IndexBuffer* indexBuffer;
					API::VertexBufferLayout* vertexBufferLayout;

					SpriteBuffer* spriteBuffer;
					unsigned int indexCount;

					SubmitType submitType;
					bool firstSubmission;

					std::vector<API::Texture2D*> textures;

				public:
					SpriteRenderer(API::Context* context, API::Shader* shader);
					~SpriteRenderer();

					void Begin(SubmitType submitType);
					void Submit(Sprite* sprite);
					void End();
					void Draw();

				private:
					void CalculateUV(Sprite* sprite, Math::Vector2* topLeft, Math::Vector2* topRight, Math::Vector2* bottomRight, Math::Vector2* bottomLeft);
					float FindTexture(API::Texture2D* texture);
			};
		}
	}
}