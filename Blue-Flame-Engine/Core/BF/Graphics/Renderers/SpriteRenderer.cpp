#include "SpriteRenderer.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Math;

			SpriteRenderer::SpriteRenderer(Context* context, Shader* shader) :
				context(context), shader(shader), indexCount(0), firstSubmission(true)
			{
				vertexBuffer = new VertexBuffer(context, shader);
				indexBuffer = new IndexBuffer(context);
				vertexBufferLayout = new VertexBufferLayout();
				vertexArray = new VertexArray(context, shader);

				vertexBufferLayout->Push(0, "POSITION", BF::Graphics::API::DataType::Float3, 0, 0);

				const int numberOfObjects = 50000;
				
				vertexArray->Create();
				vertexBuffer->Create(0, (4 * numberOfObjects) * sizeof(Vector3));

				vertexArray->Push(vertexBuffer);
				vertexArray->Push(vertexBuffer);
				vertexArray->SetVertexBufferLayout(vertexBufferLayout);

				
				unsigned int* indecies = new unsigned int[(6 * numberOfObjects)];
				
				for (size_t i = 0; i < (6 * numberOfObjects); i++)
					indecies[i] = 0;

				int index = 0;

				for (size_t i = 0; i < (6 * numberOfObjects); i += 6)
				{
					indecies[i + 0] = index + 0;
					indecies[i + 1] = index + 1;
					indecies[i + 2] = index + 2;

					indecies[i + 3] = index + 2;
					indecies[i + 4] = index + 3;
					indecies[i + 5] = index + 0;

					index += 4;
				}

				indexBuffer->Create(indecies, (6 * numberOfObjects));
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Begin(SubmitType submitType)
			{
				this->submitType = submitType;

				if (firstSubmission)
				{
					indexCount = 0;
					spriteData = (SpriteData*)vertexBuffer->Map();
				}
			}

			void SpriteRenderer::Submit(Sprite* sprite)
			{
				if (firstSubmission)
				{
					//Bottom Left
					spriteData->position = Vector3(sprite->position.x, sprite->position.y + sprite->size.y, 0.0f);
					spriteData++;

					//Top Left
					spriteData->position = Vector3(sprite->position.x, sprite->position.y, 0.0f);
					spriteData++;

					//Top Right
					spriteData->position = Vector3(sprite->position.x + sprite->size.x, sprite->position.y, 0.0f);
					spriteData++;

					//Bottom Right
					spriteData->position = Vector3(sprite->position.x + sprite->size.x, sprite->position.y + sprite->size.y, 0.0f);
					spriteData++;

					indexCount += 6;
				}
			}

			void SpriteRenderer::End()
			{
				if (firstSubmission)
					vertexBuffer->Unmap();

				if (submitType == SubmitType::StaticSubmit)
					firstSubmission = false;
			}

			void SpriteRenderer::Draw()
			{
				vertexArray->Bind();
				indexBuffer->Bind();
				context->Draw(indexCount);
				indexBuffer->Unbind();
				vertexArray->Unbind();
			}
		}
	}
}