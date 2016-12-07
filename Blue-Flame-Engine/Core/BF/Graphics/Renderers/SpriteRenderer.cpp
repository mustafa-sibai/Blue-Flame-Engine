#include "SpriteRenderer.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{

#define MAX_SPRITES		60000
#define SPRITE_VERTICES 4
#define	SPRITE_INDICES	6
#define VERTICES_SIZE	MAX_SPRITES * SPRITE_VERTICES
#define INDICES_SIZE	MAX_SPRITES * SPRITE_INDICES
#define MAX_TEXTURES	32 - 1
			
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Math;

			SpriteRenderer::SpriteRenderer(const Context* context, const Shader* shader) :
				context(context), shader(shader), indexCount(0), submitSprite(true)
			{
				vertexBuffer = new VertexBuffer(context, shader);
				indexBuffer = new IndexBuffer(context);
				vertexBufferLayout = new VertexBufferLayout();

				vertexBufferLayout->Push(0, "POSITION",		BF::Graphics::API::DataType::Float3, sizeof(SpriteBuffer), 0);
				vertexBufferLayout->Push(1, "COLOR",		BF::Graphics::API::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector3));
				vertexBufferLayout->Push(2, "TEXCOORD",		BF::Graphics::API::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4));
				vertexBufferLayout->Push(3, "TEXTUREID",	BF::Graphics::API::DataType::Float,	 sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2));

				shader->Bind();

				vertexBuffer->Create(nullptr, VERTICES_SIZE * sizeof(SpriteBuffer));
				vertexBuffer->SetLayout(vertexBufferLayout);

				unsigned int* indecies = new unsigned int[INDICES_SIZE];
				int index = 0;

				for (unsigned int i = 0; i < INDICES_SIZE; i += SPRITE_INDICES)
				{
					indecies[i + 0] = index + 0;
					indecies[i + 1] = index + 1;
					indecies[i + 2] = index + 2;

					indecies[i + 3] = index + 2;
					indecies[i + 4] = index + 3;
					indecies[i + 5] = index + 0;

					index += SPRITE_VERTICES;
				}

				indexBuffer->Create(indecies, INDICES_SIZE);

				context->EnableDepthBuffer(false);
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Begin(SubmitType submitType)
			{
				this->submitType = submitType;

				if (submitSprite)
					spriteBuffer = (SpriteBuffer*)vertexBuffer->Map();
			}

			void SpriteRenderer::Submit(const Sprite* sprite)
			{
				if (submitSprite)
				{
					float textureID = FindTexture(sprite->texture2D);

					if ((int)textureID > MAX_TEXTURES)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						End();
						Begin(submitType);
						textureID = FindTexture(sprite->texture2D);
					}

					sprite->texture2D->Bind("textures[" + std::to_string((int)textureID) + std::string("]"), textureID);

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

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::End()
			{
				if (submitSprite)
					vertexBuffer->Unmap();

				vertexBuffer->Bind();
				indexBuffer->Bind();
				context->Draw(indexCount);
				indexBuffer->Unbind();
				vertexBuffer->Unbind();

				if (submitType == SubmitType::StaticSubmit)
				{
					submitSprite = false;
					textures.clear();
				}
				else if (submitType == SubmitType::DynamicSubmit)
				{
					for (unsigned int i = 0; i < textures.size(); i++)
						textures[i]->Unbind();

					textures.clear();
					indexCount = 0;
				}
			}

			void SpriteRenderer::CalculateUV(const Sprite* sprite, Vector2* topLeft, Vector2* topRight, Vector2* bottomRight, Vector2* bottomLeft)
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

			float SpriteRenderer::FindTexture(const Texture2D* texture)
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