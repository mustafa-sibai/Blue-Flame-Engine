#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/VertexArray.h"
#include "BF/Math/Math.h"
#include "BF/Graphics/Renderers/Sprite.h"

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
					API::VertexArray* vertexArray;

					SpriteData* spriteData;
					unsigned int indexCount;

					SubmitType submitType;
					bool firstSubmission;

				public:
					SpriteRenderer(API::Context* context, API::Shader* shader);
					~SpriteRenderer();

					void Begin(SubmitType submitType);
					void Submit(Sprite* sprite);
					void End();
					void Draw();
			};
		}
	}
}