#include "SpriteRenderer.h"
#include <algorithm>
#include "BF/Engine.h"

#define MAX_SPRITES		60000
#define SPRITE_VERTICES 4
#define	SPRITE_INDICES	6
#define VERTICES_SIZE	MAX_SPRITES * SPRITE_VERTICES
#define INDICES_SIZE	MAX_SPRITES * SPRITE_INDICES

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Graphics::Fonts;
			using namespace BF::Math;

			const BF::Graphics::API::Texture2D* SpriteRenderer::currentBoundTexture = nullptr;

			SpriteRenderer::SpriteRenderer() :
				vertexBuffer(shader), indexCount(0), submitSprite(true), newDrawCall(false)
			{
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Initialize()
			{
				BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

#if BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
					shader.Load("../Sandbox/Assets/Shaders/HLSL/Compiled/SpriteRenderer/VertexShader.cso", "../Sandbox/Assets/Shaders/HLSL/Compiled/SpriteRenderer/PixelShader.cso");
				}
				else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
				{
					shader.Load("../Sandbox/Assets/Shaders/GLSL/SpriteRenderer/VertexShader.glsl", "../Sandbox/Assets/Shaders/GLSL/SpriteRenderer/PixelShader.glsl");
				}
#elif BF_PLATFORM_LINUX
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
				{
					shader->Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
				}
#endif
				shader.Bind();

				vertexBufferLayout.Push(0, "POSITION",		VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), 0);
				vertexBufferLayout.Push(1, "COLOR",			VertexBufferLayout::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector2));
				vertexBufferLayout.Push(2, "TEXCOORD",		VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector2) + sizeof(Color));
				vertexBufferLayout.Push(3, "RENDERINGTYPE", VertexBufferLayout::DataType::Float,  sizeof(SpriteBuffer), sizeof(Vector2) + sizeof(Color) + sizeof(Vector2));
				
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

				vertexBuffer.Create(nullptr, VERTICES_SIZE * sizeof(SpriteBuffer));
				vertexBuffer.SetLayout(vertexBufferLayout);
				indexBuffer.Create(indecies, INDICES_SIZE);

				Engine::GetContext().EnableDepthBuffer(false);
				Engine::GetContext().EnableBlending(true);
				delete[] indecies;
			}

			void SpriteRenderer::Begin(SubmitType submitType, SortingOrder sortingOrder)
			{
				this->submitType = submitType;
				this->sortingOrder = sortingOrder;

				shader.Bind();

				if (submitSprite)
					spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();
			}

			void SpriteRenderer::Render(const Sprite& sprite)
			{
				if (submitSprite)
					sprites.push_back(&sprite);
			}

			void SpriteRenderer::RenderRectangle(const Rectangle& rectangle, const Color& color)
			{
				if (submitSprite)
				{
					//Top Left
					spriteBuffer->position		= Vector2((float)rectangle.x, (float)rectangle.y);
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position		= Vector2((float)(rectangle.x + rectangle.width), (float)rectangle.y);
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position		= Vector2((float)(rectangle.x + rectangle.width), (float)(rectangle.y + rectangle.height));
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position		= Vector2((float)rectangle.x, (float)(rectangle.y + rectangle.height));
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::RenderLine(const Vector2& startPoint, const Vector2& endPoint, float thickness, const Color& color)
			{
				if (submitSprite)
				{
					Vector2 normal = Vector2(endPoint.y - startPoint.y, -(endPoint.x - startPoint.x)).Normalize() * thickness;

					//Top Left
					spriteBuffer->position		= startPoint + normal;
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position		= Vector2(endPoint.x + normal.x, endPoint.y + normal.y);
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position		= Vector2(endPoint.x - normal.x, endPoint.y - normal.y);
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position		= startPoint - normal;
					spriteBuffer->color			= color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::MapBuffer()
			{
				for (size_t i = 0; i < sprites.size(); i++)
				{
					if (currentBoundTexture != nullptr)
					{
						if (sprites[i][0].texture2D != currentBoundTexture)
						{
							if (submitType == SubmitType::StaticSubmit)
								return;

							newDrawCall = true;

							End();
							Begin(submitType, sortingOrder);
						}
					}

					if (currentBoundTexture != sprites[i][0].texture2D)
					{
						sprites[i][0].texture2D->Bind();
						currentBoundTexture = sprites[i][0].texture2D;
					}

					Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
					CalculateUV(sprites[i][0].texture2D, sprites[i][0].scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

					//Top Left
					spriteBuffer->position		= sprites[i][0].position;
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= topLeftUV;
					spriteBuffer->renderingType = 1;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position		= Vector2(sprites[i][0].position.x + sprites[i][0].rectangle.width, sprites[i][0].position.y);
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= topRightUV;
					spriteBuffer->renderingType = 1;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position		= Vector2(sprites[i][0].position.x + sprites[i][0].rectangle.width, sprites[i][0].position.y + sprites[i][0].rectangle.height);
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= bottomRightUV;
					spriteBuffer->renderingType = 1;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position		= Vector2(sprites[i][0].position.x, sprites[i][0].position.y + sprites[i][0].rectangle.height);
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= bottomLeftUV;
					spriteBuffer->renderingType = 1;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::RenderText(const FontAtlas& fontAtlas, const string& text, const Vector2& position, const Color& color)
			{
				Rectangle prevPos;
				Vector2 pos = position;
				const Texture2D* previousTexture = nullptr;

				if (submitSprite)
				{
					if (previousTexture != nullptr)
					{
						if (fontAtlas.texture != previousTexture)
						{
							if (submitType == SubmitType::StaticSubmit)
								return;

							newDrawCall = true;

							End();
							Begin(submitType, sortingOrder);
						}
					}

					fontAtlas.texture->Bind();
					previousTexture = fontAtlas.texture;

					for (size_t i = 0; i < text.length(); i++)
					{
						unsigned int unicode = text[i] - 32;
						Rectangle scissorRectangle = fontAtlas.characters[0][unicode].scissorRectangle;

						Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
						CalculateUV(fontAtlas.texture, scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

						pos += Vector2(prevPos.x + fontAtlas.characters[0][unicode].bearing.x, 0.0f);
						prevPos.x = fontAtlas.characters[0][unicode].scissorRectangle.width;
						pos.y = position.y + (fontAtlas.characters[0][unicode].charPixelSize - fontAtlas.characters[0][unicode].bearing.y);

						//Top Left
						spriteBuffer->position		= pos;
						spriteBuffer->color			= color;
						spriteBuffer->UV			= topLeftUV;
						spriteBuffer->renderingType = 2;
						spriteBuffer++;

						//Top Right
						spriteBuffer->position		= Vector2(pos.x + (float)scissorRectangle.width, pos.y);
						spriteBuffer->color			= color;
						spriteBuffer->UV			= topRightUV;
						spriteBuffer->renderingType = 2;
						spriteBuffer++;

						//Bottom Right
						spriteBuffer->position		= Vector2(pos.x + (float)scissorRectangle.width, pos.y + (float)scissorRectangle.height);
						spriteBuffer->color			= color;
						spriteBuffer->UV			= bottomRightUV;
						spriteBuffer->renderingType = 2;
						spriteBuffer++;

						//Bottom Left
						spriteBuffer->position		= Vector2((float)pos.x, pos.y + (float)scissorRectangle.height);
						spriteBuffer->color			= color;
						spriteBuffer->UV			= bottomLeftUV;
						spriteBuffer->renderingType = 2;
						spriteBuffer++;

						indexCount += SPRITE_INDICES;
					}
				}
			}

			void SpriteRenderer::End()
			{
				if (submitSprite)
				{
					if (!newDrawCall)
					{
						if (sortingOrder == SortingOrder::BackToFront)
							sort(sprites.begin(), sprites.end(), Sprite::BackToFront());
						else if (sortingOrder == SortingOrder::FrontToBack)
							sort(sprites.begin(), sprites.end(), Sprite::FrontToBack());

						MapBuffer();
						vertexBuffer.Unmap();
					}
					else
						vertexBuffer.Unmap();
				}

				vertexBuffer.Bind();
				indexBuffer.Bind();
				Engine::GetContext().Draw(indexCount);
				indexBuffer.Unbind();
				vertexBuffer.Unbind();

				if (submitType == SubmitType::StaticSubmit)
				{
					submitSprite = false;
				}
				else if (submitType == SubmitType::DynamicSubmit)
				{
					indexCount = 0;

					if (!newDrawCall)
						sprites.clear();

					newDrawCall = false;
				}
			}

			void SpriteRenderer::CalculateUV(const Texture2D* texture, const Math::Rectangle& scissorRectangle, Vector2* topLeft, Vector2* topRight, Vector2* bottomRight, Vector2* bottomLeft)
			{
				*topLeft = Vector2(1.0f / ((float)texture->GetTextureData().width / (float)scissorRectangle.x),
									1.0f / ((float)texture->GetTextureData().height / (float)scissorRectangle.y));

				*topRight = Vector2(1.0f / ((float)texture->GetTextureData().width / ((float)scissorRectangle.x + (float)scissorRectangle.width)),
									1.0f / ((float)texture->GetTextureData().height / (float)scissorRectangle.y));

				*bottomRight = Vector2(1.0f / ((float)texture->GetTextureData().width / ((float)scissorRectangle.x + (float)scissorRectangle.width)),
									1.0f / ((float)texture->GetTextureData().height / ((float)scissorRectangle.y + (float)scissorRectangle.height)));

				*bottomLeft = Vector2(1.0f / ((float)texture->GetTextureData().width / (float)scissorRectangle.x),
									1.0f / ((float)texture->GetTextureData().height / ((float)scissorRectangle.y + (float)scissorRectangle.height)));
			}
		}
	}
}