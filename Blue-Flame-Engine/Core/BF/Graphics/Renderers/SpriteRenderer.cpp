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

			SpriteRenderer::SpriteRenderer(Context* context, const Shader* shader) :
				context(context), shader(shader), indexCount(0), firstSubmission(true)
			{
				vertexBuffer = new VertexBuffer(context, shader);
				indexBuffer = new IndexBuffer(context);
				vertexBufferLayout = new VertexBufferLayout();

				vertexBufferLayout->Push(0, "POSITION",		BF::Graphics::API::DataType::Float3, sizeof(SpriteBuffer), 0);
				vertexBufferLayout->Push(1, "COLOR",		BF::Graphics::API::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector3));
				vertexBufferLayout->Push(2, "TEXCOORD",		BF::Graphics::API::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4));
				vertexBufferLayout->Push(3, "TEXTUREID",	BF::Graphics::API::DataType::Float,	 sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2));

				shader->Bind();

				const int numberOfObjects = 50000;

				vertexBuffer->Create(nullptr, (4 * numberOfObjects) * sizeof(SpriteBuffer));
				vertexBuffer->SetLayout(vertexBufferLayout);

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

				context->EnableDepthBuffer(false);
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Begin(SubmitType submitType)
			{
				this->submitType = submitType;

				if (firstSubmission)
					spriteBuffer = (SpriteBuffer*)vertexBuffer->Map();
			}

			void SpriteRenderer::Submit(Sprite* sprite)
			{
				if (firstSubmission)
				{
					float textureID = FindTexture(sprite->texture2D);

					if(textureID == 0.0f)
						sprite->texture2D->Bind("textures[0]", textureID);
					else if (textureID == 1.0f)
						sprite->texture2D->Bind("textures[1]", textureID);

					Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
					CalculateUV(sprite, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

					//Top Left
					spriteBuffer->position	= Vector3(sprite->position.x + sprite->rectangle.x, sprite->position.y + sprite->rectangle.y, 0.0f);
					spriteBuffer->color		= sprite->color;
					spriteBuffer->UV		= topLeftUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position	= Vector3(sprite->position.x + sprite->rectangle.x + sprite->rectangle.width, sprite->position.y + sprite->rectangle.y, 0.0f);
					spriteBuffer->color		= sprite->color;
					spriteBuffer->UV		= topRightUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position	= Vector3(sprite->position.x + sprite->rectangle.x + sprite->rectangle.width, sprite->position.y + sprite->rectangle.y + sprite->rectangle.height, 0.0f);
					spriteBuffer->color		= sprite->color;
					spriteBuffer->UV		= bottomRightUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position	= Vector3(sprite->position.x + sprite->rectangle.x, sprite->position.y + sprite->rectangle.y + sprite->rectangle.height, 0.0f);
					spriteBuffer->color		= sprite->color;
					spriteBuffer->UV		= bottomLeftUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

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
				vertexBuffer->Bind();
				indexBuffer->Bind();
				context->Draw(indexCount);
				indexBuffer->Unbind();
				vertexBuffer->Unbind();

				if (firstSubmission)
				{
					for (unsigned int i = 0; i < textures.size(); i++)
						textures[i]->Unbind();

					textures.clear();
					indexCount = 0;
				}
			}

			void SpriteRenderer::CalculateUV(const Sprite* sprite, Math::Vector2* topLeft, Math::Vector2* topRight, Math::Vector2* bottomRight, Math::Vector2* bottomLeft)
			{
				*topLeft = Vector2(1.0f / ((float)sprite->texture2D->GetWidth() / (float)sprite->sourceRectangle.x),
									1.0f / ((float)sprite->texture2D->GetHeight() / (float)sprite->sourceRectangle.y));

				*topRight = Vector2(1.0f / ((float)sprite->texture2D->GetWidth() / ((float)sprite->sourceRectangle.x + (float)sprite->sourceRectangle.width)),
									1.0f / ((float)sprite->texture2D->GetHeight() / (float)sprite->sourceRectangle.y));

				*bottomRight = Vector2(1.0f / ((float)sprite->texture2D->GetWidth() / ((float)sprite->sourceRectangle.x + (float)sprite->sourceRectangle.width)),
										1.0f / ((float)sprite->texture2D->GetHeight() / ((float)sprite->sourceRectangle.y + (float)sprite->sourceRectangle.height)));

				*bottomLeft = Vector2(1.0f / ((float)sprite->texture2D->GetWidth() / (float)sprite->sourceRectangle.x),
										1.0f / ((float)sprite->texture2D->GetHeight() / ((float)sprite->sourceRectangle.y + (float)sprite->sourceRectangle.height)));
			}

			float SpriteRenderer::FindTexture(API::Texture2D* texture)
			{
				for (unsigned int i = 0; i < textures.size(); i++)
				{
					if (textures[i] == texture)
						return (float)i;
				}

				textures.push_back(texture);
				return (float)(textures.size() - 1);
			}
		}
	}
}