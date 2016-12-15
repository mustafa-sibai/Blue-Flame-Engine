#include "SpriteRenderer.h"
#include "BF/Engine.h"

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

			SpriteRenderer::SpriteRenderer(const Shader& shader) :
				shader(shader), vertexBuffer(shader), indexCount(0), submitSprite(true)
			{
				indexBuffer = new IndexBuffer();
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Initialize()
			{
				vertexBufferLayout.Push(0, "POSITION",	VertexBufferLayout::DataType::Float3, sizeof(SpriteBuffer), 0);
				vertexBufferLayout.Push(1, "COLOR",		VertexBufferLayout::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector3));
				vertexBufferLayout.Push(2, "TEXCOORD",	VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4));
				vertexBufferLayout.Push(3, "TEXTUREID", VertexBufferLayout::DataType::Float,  sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2));

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

				shader.Bind();

				vertexBuffer.Create(nullptr, VERTICES_SIZE * sizeof(SpriteBuffer));
				vertexBuffer.SetLayout(vertexBufferLayout);
				indexBuffer->Create(indecies, INDICES_SIZE);

				Engine::GetContext().EnableDepthBuffer(false);

				delete indecies;
			}

			void SpriteRenderer::Begin(SubmitType submitType)
			{
				this->submitType = submitType;

				if (submitSprite)
					spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();
			}

			void SpriteRenderer::Submit(const Sprite& sprite)
			{
				if (submitSprite)
				{
					float textureID = FindTexture(sprite.GetTexture());

					if ((int)textureID > MAX_TEXTURES)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						End();
						Begin(submitType);
						textureID = FindTexture(sprite.GetTexture());
					}

					sprite.GetTexture()->Bind("textures[" + std::to_string((unsigned int)textureID) + std::string("]"), (unsigned int)textureID);

					Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
					CalculateUV(sprite, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

					//Top Left
					spriteBuffer->position	= Vector3(sprite.GetPosition().x + sprite.GetRectangle().x, sprite.GetPosition().y + sprite.GetRectangle().y, 0.0f);
					spriteBuffer->color		= sprite.GetColor();
					spriteBuffer->UV		= topLeftUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position	= Vector3(sprite.GetPosition().x + sprite.GetRectangle().x + sprite.GetRectangle().width, sprite.GetPosition().y + sprite.GetRectangle().y, 0.0f);
					spriteBuffer->color		= sprite.GetColor();
					spriteBuffer->UV		= topRightUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position	= Vector3(sprite.GetPosition().x + sprite.GetRectangle().x + sprite.GetRectangle().width, sprite.GetPosition().y + sprite.GetRectangle().y + sprite.GetRectangle().height, 0.0f);
					spriteBuffer->color		= sprite.GetColor();
					spriteBuffer->UV		= bottomRightUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position	= Vector3(sprite.GetPosition().x + sprite.GetRectangle().x, sprite.GetPosition().y + sprite.GetRectangle().y + sprite.GetRectangle().height, 0.0f);
					spriteBuffer->color		= sprite.GetColor();
					spriteBuffer->UV		= bottomLeftUV;
					spriteBuffer->textureID = textureID;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::End()
			{
				if (submitSprite)
					vertexBuffer.Unmap();

				vertexBuffer.Bind();
				indexBuffer->Bind();
				Engine::GetContext().Draw(indexCount);
				indexBuffer->Unbind();
				vertexBuffer.Unbind();

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

			void SpriteRenderer::CalculateUV(const Sprite& sprite, Vector2* topLeft, Vector2* topRight, Vector2* bottomRight, Vector2* bottomLeft)
			{
				*topLeft = Vector2(1.0f / ((float)sprite.GetTexture()->GetWidth() / (float)sprite.GetScissorRectangle().x),
									1.0f / ((float)sprite.GetTexture()->GetHeight() / (float)sprite.GetScissorRectangle().y));

				*topRight = Vector2(1.0f / ((float)sprite.GetTexture()->GetWidth() / ((float)sprite.GetScissorRectangle().x + (float)sprite.GetScissorRectangle().width)),
									1.0f / ((float)sprite.GetTexture()->GetHeight() / (float)sprite.GetScissorRectangle().y));

				*bottomRight = Vector2(1.0f / ((float)sprite.GetTexture()->GetWidth() / ((float)sprite.GetScissorRectangle().x + (float)sprite.GetScissorRectangle().width)),
										1.0f / ((float)sprite.GetTexture()->GetHeight() / ((float)sprite.GetScissorRectangle().y + (float)sprite.GetScissorRectangle().height)));

				*bottomLeft = Vector2(1.0f / ((float)sprite.GetTexture()->GetWidth() / (float)sprite.GetScissorRectangle().x),
										1.0f / ((float)sprite.GetTexture()->GetHeight() / ((float)sprite.GetScissorRectangle().y + (float)sprite.GetScissorRectangle().height)));
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