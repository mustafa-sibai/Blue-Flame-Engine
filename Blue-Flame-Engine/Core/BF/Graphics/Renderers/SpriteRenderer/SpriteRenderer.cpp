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

				shader.LoadStandardShader(ShaderType::SpriteRenderer);
				shader.Bind();

				vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), 0);
				vertexBufferLayout.Push(1, "COLOR", VertexBufferLayout::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector2));
				vertexBufferLayout.Push(2, "TEXCOORD", VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector2) + sizeof(Color));
				vertexBufferLayout.Push(3, "RENDERINGTYPE", VertexBufferLayout::DataType::Float, sizeof(SpriteBuffer), sizeof(Vector2) + sizeof(Color) + sizeof(Vector2));

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
				Engine::GetContext().EnableScissor(true);

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

			void SpriteRenderer::Render(const Renderable& renderable)
			{
				if (submitSprite)
					renderables.push_back(&renderable);
			}

			SpriteRenderer& SpriteRenderer::operator=(const SpriteRenderer& spriteRenderer)
			{
				this->shader = spriteRenderer.shader;
				this->vertexBuffer = spriteRenderer.vertexBuffer;
				this->indexBuffer = spriteRenderer.indexBuffer;
				this->vertexBufferLayout = spriteRenderer.vertexBufferLayout;

				this->spriteBuffer = new SpriteBuffer();
				this->spriteBuffer->color = spriteRenderer.spriteBuffer->color;
				this->spriteBuffer->position = spriteRenderer.spriteBuffer->position;
				this->spriteBuffer->renderingType = spriteRenderer.spriteBuffer->renderingType;
				this->spriteBuffer->UV = spriteRenderer.spriteBuffer->UV;

				this->indexCount = spriteRenderer.indexCount;
				this->renderables = spriteRenderer.renderables;

				this->submitType = spriteRenderer.submitType;
				this->sortingOrder = spriteRenderer.sortingOrder;
				this->submitSprite = spriteRenderer.submitSprite;
				this->newDrawCall = spriteRenderer.newDrawCall;

				return *this;
			}

			void SpriteRenderer::MapLineBuffer(const LineShape& lineShape)
			{
				Vector2 normal = Vector2(lineShape.endPoint.y - lineShape.startPoint.y, -(lineShape.endPoint.x - lineShape.startPoint.x)).Normalize() * lineShape.thickness;

				//Top Left
				spriteBuffer->position = lineShape.startPoint + normal;
				spriteBuffer->color = lineShape.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2(lineShape.endPoint.x + normal.x, lineShape.endPoint.y + normal.y);
				spriteBuffer->color = lineShape.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2(lineShape.endPoint.x - normal.x, lineShape.endPoint.y - normal.y);
				spriteBuffer->color = lineShape.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = lineShape.startPoint - normal;
				spriteBuffer->color = lineShape.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				indexCount += SPRITE_INDICES;
			}

			void SpriteRenderer::MapPolygonBuffer(const RegularPolygon& regularPolygon)
			{
				//Top Left
				spriteBuffer->position = Vector2((float)regularPolygon.rectangle.x, (float)regularPolygon.rectangle.y);
				spriteBuffer->color = regularPolygon.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2((float)(regularPolygon.rectangle.x + regularPolygon.rectangle.width), (float)regularPolygon.rectangle.y);
				spriteBuffer->color = regularPolygon.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2((float)(regularPolygon.rectangle.x + regularPolygon.rectangle.width), (float)(regularPolygon.rectangle.y + regularPolygon.rectangle.height));
				spriteBuffer->color = regularPolygon.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2((float)regularPolygon.rectangle.x, (float)(regularPolygon.rectangle.y + regularPolygon.rectangle.height));
				spriteBuffer->color = regularPolygon.color;
				spriteBuffer->UV = Vector2(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				indexCount += SPRITE_INDICES;
			}

			void SpriteRenderer::MapSpriteBuffer(const Sprite& sprite)
			{
				if (currentBoundTexture != nullptr)
				{
					if (sprite.texture2D != currentBoundTexture)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						newDrawCall = true;

						End();
						Begin(submitType, sortingOrder);
					}
				}

				if (currentBoundTexture != sprite.texture2D)
				{
					sprite.texture2D->Bind();
					currentBoundTexture = sprite.texture2D;
				}

				Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
				CalculateUV(sprite.texture2D, sprite.scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

				//Top Left
				spriteBuffer->position = sprite.position;
				spriteBuffer->color = sprite.color;
				spriteBuffer->UV = topLeftUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2(sprite.position.x + sprite.rectangle.width, sprite.position.y);
				spriteBuffer->color = sprite.color;
				spriteBuffer->UV = topRightUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2(sprite.position.x + sprite.rectangle.width, sprite.position.y + sprite.rectangle.height);
				spriteBuffer->color = sprite.color;
				spriteBuffer->UV = bottomRightUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2(sprite.position.x, sprite.position.y + sprite.rectangle.height);
				spriteBuffer->color = sprite.color;
				spriteBuffer->UV = bottomLeftUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				indexCount += SPRITE_INDICES;
			}

			void SpriteRenderer::MapBuffer()
			{
				if (submitSprite)
				{
					for (size_t i = 0; i < renderables.size(); i++)
					{
						switch (renderables[i][0].type)
						{
						case Renderable::Type::Line:
						{
							LineShape& line = (LineShape&)renderables[i][0];
							MapLineBuffer(line);
							break;
						}
						case Renderable::Type::RegularPolygon:
						{
							RegularPolygon& regularPolygon = (RegularPolygon&)renderables[i][0];
							MapPolygonBuffer(regularPolygon);
							break;
						}
						case Renderable::Type::Sprite:
						{
							Sprite& sprite = (Sprite&)renderables[i][0];
							MapSpriteBuffer(sprite);
							break;
						}
						default:
							break;
						}
					}
				}
			}

			void SpriteRenderer::RenderText(const FontAtlas& fontAtlas, const string& text, const Vector2& position, const Color& color)
			{
				Rectangle prevPos;
				Vector2 pos = position;

				if (currentBoundTexture != nullptr)
				{
					if (fontAtlas.texture != currentBoundTexture)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						newDrawCall = true;

						End();
						Begin(submitType, sortingOrder);
					}
				}

				if (currentBoundTexture != fontAtlas.texture)
				{
					fontAtlas.texture->Bind();
					currentBoundTexture = fontAtlas.texture;
				}

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
					spriteBuffer->position = pos;
					spriteBuffer->color = color;
					spriteBuffer->UV = topLeftUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position = Vector2(pos.x + (float)scissorRectangle.width, pos.y);
					spriteBuffer->color = color;
					spriteBuffer->UV = topRightUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position = Vector2(pos.x + (float)scissorRectangle.width, pos.y + (float)scissorRectangle.height);
					spriteBuffer->color = color;
					spriteBuffer->UV = bottomRightUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position = Vector2((float)pos.x, pos.y + (float)scissorRectangle.height);
					spriteBuffer->color = color;
					spriteBuffer->UV = bottomLeftUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::End()
			{
				if (submitSprite)
				{
					if (!newDrawCall)
					{
						if (sortingOrder == SortingOrder::BackToFront)
							sort(renderables.begin(), renderables.end(), Sprite::BackToFront());
						else if (sortingOrder == SortingOrder::FrontToBack)
							sort(renderables.begin(), renderables.end(), Sprite::FrontToBack());

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
						renderables.clear();

					newDrawCall = false;
				}
			}

			void SpriteRenderer::SetScissor(const Math::Rectangle& rectangle)
			{
				End();
				Begin(submitType, sortingOrder);
				BF::Engine::GetContext().SetScissor(rectangle);
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