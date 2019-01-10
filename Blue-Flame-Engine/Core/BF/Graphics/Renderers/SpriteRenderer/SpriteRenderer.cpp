#include "SpriteRenderer.h"
#include <algorithm>
#include "BF/Engine.h"
#include "BF/System/Debug.h"
#include "BF/ECS/GameObject.h"

//#include "BF/Application/Layers/LayerManager.h"

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
			using namespace BF::Math;
			using namespace BF::Application;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Fonts;
			using namespace BF::Graphics::Renderers;

			const BF::Graphics::API::Texture2D* SpriteRenderer::currentBoundTexture = nullptr;

			SpriteRenderer::SpriteRenderer() :
				indexCount(0), submitSprite(true), newDrawCall(false)/*, nullCount(0)*/
			{
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Initialize()
			{
				BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

				shader.LoadStandardShader(ShaderType::SpriteRenderer);

				vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), 0);
				vertexBufferLayout.Push(1, "COLOR", VertexBufferLayout::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector2f));
				vertexBufferLayout.Push(2, "TEXCOORD", VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector2f) + sizeof(Color));
				vertexBufferLayout.Push(3, "RENDERINGTYPE", VertexBufferLayout::DataType::Float, sizeof(SpriteBuffer), sizeof(Vector2f) + sizeof(Color) + sizeof(Vector2f));

				unsigned int* indices = new unsigned int[INDICES_SIZE];
				int index = 0;

				for (unsigned int i = 0; i < INDICES_SIZE; i += SPRITE_INDICES)
				{
					indices[i + 0] = index + 0;
					indices[i + 1] = index + 1;
					indices[i + 2] = index + 2;

					indices[i + 3] = index + 2;
					indices[i + 4] = index + 3;
					indices[i + 5] = index + 0;

					index += SPRITE_VERTICES;
				}

				vertexBuffer.Create(VERTICES_SIZE * sizeof(SpriteBuffer), nullptr);
				indexBuffer.Create(indices, INDICES_SIZE);
				vertexBuffer.SetLayout(shader, &vertexBufferLayout);

				Engine::GetContext().EnableDepthBuffer(false);
				Engine::GetContext().EnableBlending(true);
				Engine::GetContext().EnableScissor(true);

				delete[] indices;
			}

			/*void SpriteRenderer::Submit(Renderable& renderable)
			{
				renderables.emplace_back(&renderable);
			}*/

			/*void SpriteRenderer::Submit(Renderable& renderable)
			{
				int index = 0;

				if (nullCount <= 0)
				{
					renderables.emplace_back(&renderable);

					index = renderables.size() - 1;
					renderables[index]->index = index;
				}
				else
				{
					index = (renderables.size() - 1) - (nullCount - 1);
					renderables[index] = &renderable;
					renderables[index]->index = index;
					nullCount--;
				}
			}

			void SpriteRenderer::Remove(Renderable& renderable)
			{
				removeList.emplace_back(&renderable);
				//renderables[renderable.index] = nullptr;
				//nullCount++;
			}*/

			void SpriteRenderer::Render(SortingOrder sortingOrder)
			{
				this->sortingOrder = sortingOrder;

				shader.Bind();
				spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();

				if (submitSprite)
				{
					if (!newDrawCall)
					{
						/*for (size_t i = 0; i < removeList.size(); i++)
						{
							int index = removeList[i]->index;
							renderables[index] = nullptr;
							scene.gameNodes.erase(removeList[i]->name);
							delete renderables[index];
							nullCount++;
						}
						removeList.clear();*/

						if (sortingOrder == SortingOrder::BackToFront)
							sort(renderables.begin(), renderables.end(), Renderable::BackToFront());
						
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


				indexCount = 0;

				/*if (!newDrawCall)
					renderables.clear();*/

				newDrawCall = false;
			}

			/*void SpriteRenderer::Begin(SubmitType submitType, SortingOrder sortingOrder)
			{
				this->submitType = submitType;
				this->sortingOrder = sortingOrder;

				shader.Bind();

				if (submitSprite)
					spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();
			}*/

			/*void SpriteRenderer::Render(const Renderable& renderable)
			{
				if (submitSprite)
					renderables.emplace_back(&renderable);
			}*/

			/*SpriteRenderer& SpriteRenderer::operator=(const SpriteRenderer& spriteRenderer)
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
			}*/

			void SpriteRenderer::MapLineBuffer(const LineShape* lineShape)
			{
				Vector2f normal = Vector2f(lineShape->endPoint.y - lineShape->startPoint.y, -(lineShape->endPoint.x - lineShape->startPoint.x)).Normalize() * lineShape->thickness;

				//Top Left
				spriteBuffer->position = lineShape->startPoint + normal;
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2f(lineShape->endPoint.x + normal.x, lineShape->endPoint.y + normal.y);
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2f(lineShape->endPoint.x - normal.x, lineShape->endPoint.y - normal.y);
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = lineShape->startPoint - normal;
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				indexCount += SPRITE_INDICES;
			}

			void SpriteRenderer::MapPolygonBuffer(const RegularPolygon* regularPolygon)
			{
				Vector3f& position = regularPolygon->gameObject->GetTransform()->position;
				Vector3f& scale = regularPolygon->gameObject->GetTransform()->scale;

				//Top Left
				spriteBuffer->position = Vector2f(position.x, position.y);
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2f(position.x + (regularPolygon->size.x * scale.x), position.y);
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2f(position.x + (regularPolygon->size.x * scale.x), position.y + (regularPolygon->size.y * scale.y));
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2f(position.x, position.y + (regularPolygon->size.y * scale.y));
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				indexCount += SPRITE_INDICES;
			}

			void SpriteRenderer::MapSpriteBuffer(const Sprite* sprite)
			{
				/*if (currentBoundTexture != nullptr)
				{
					if (sprite.texture2D != currentBoundTexture)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						newDrawCall = true;

						End();
						Begin(submitType, sortingOrder);
					}
				}*/

				if (currentBoundTexture != sprite->texture2D)
				{
					sprite->texture2D->Bind();
					currentBoundTexture = sprite->texture2D;
				}

				Vector2f topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
				CalculateUV(sprite->texture2D, sprite->scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

				Vector3f& position = sprite->gameObject->GetTransform()->position;
				Vector3f& scale = sprite->gameObject->GetTransform()->scale;

				//Top Left
				spriteBuffer->position = Vector2f(position.x, position.y);
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = topLeftUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2f(position.x + (sprite->size.x * scale.x), position.y);
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = topRightUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2f(position.x + (sprite->size.x * scale.x), position.y + (sprite->size.y * scale.y));
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = bottomRightUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2f(position.x, position.y + (sprite->size.y * scale.y));
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = bottomLeftUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				indexCount += SPRITE_INDICES;
			}

			void SpriteRenderer::MapTextBuffer(const Text* text)
			{
				/*if (currentBoundTexture != nullptr)
				{
					BF_IS_NULL(text.font);

					if (text.font->fontAtlas->texture != currentBoundTexture)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						newDrawCall = true;

						End();
						Begin(submitType, sortingOrder);
					}
				}*/

				if (currentBoundTexture != text->font->fontAtlas->texture)
				{
					text->font->fontAtlas->texture->Bind();
					currentBoundTexture = text->font->fontAtlas->texture;
				}

				for (size_t i = 0; i < text->characters.size(); i++)
				{
					Vector2f topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
					CalculateUV(text->font->fontAtlas->texture, text->characters[i].scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

					//Top Left
					spriteBuffer->position = text->characters[i].position;
					spriteBuffer->color = text->color;
					spriteBuffer->UV = topLeftUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position = Vector2f(text->characters[i].position.x + (float)text->characters[i].scissorRectangle.width, text->characters[i].position.y);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = topRightUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position = Vector2f(text->characters[i].position.x + (float)text->characters[i].scissorRectangle.width, text->characters[i].position.y + (float)text->characters[i].scissorRectangle.height);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = bottomRightUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position = Vector2f((float)text->characters[i].position.x, text->characters[i].position.y + (float)text->characters[i].scissorRectangle.height);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = bottomLeftUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::MapBuffer()
			{
				if (submitSprite)
				{
					for (size_t i = 0; i < renderables.size(); i++)
					{
						switch (renderables[i]->renderableType)
						{
							case Renderable::RenderableType::Line:
							{
								MapLineBuffer((LineShape*)renderables[i]);
								break;
							}
							case Renderable::RenderableType::RegularPolygon:
							{
								MapPolygonBuffer((RegularPolygon*)renderables[i]);
								break;
							}
							case Renderable::RenderableType::Sprite:
							{
								MapSpriteBuffer((Sprite*)renderables[i]);
								break;
							}
							case Renderable::RenderableType::Text:
							{
								MapTextBuffer((Text*)renderables[i]);
								break;
							}
							default:
								break;
						}
					}

					/*for (size_t i = 0; i < layerManager->GetSize(); i++)
					{
						for (size_t j = 0; j < layerManager->GetLayer(i).GetSize(); j++)
						{
							switch (layerManager->GetLayer(i).GetComponent(j).type)
							{
								case BF::Application::Component::Type::Renderable:
								{
									Renderable& renderable = (Renderable&)layerManager->GetLayer(i).GetComponent(j);

									switch (renderable.renderableType)
									{
										case Renderable::RenderableType::Line:
										{
											LineShape& line = (LineShape&)renderable;
											MapLineBuffer(line);
											break;
										}
										case Renderable::RenderableType::RegularPolygon:
										{
											RegularPolygon& regularPolygon = (RegularPolygon&)renderable;
											MapPolygonBuffer(regularPolygon);
											break;
										}
										case Renderable::RenderableType::Sprite:
										{
											Sprite& sprite = (Sprite&)renderable;
											MapSpriteBuffer(sprite);
											break;
										}
										case Renderable::RenderableType::Text:
										{
											Text& text = (Text&)renderable;
											MapTextBuffer(text);
											break;
										}
										default:
											break;
									}
									break;
								}

								case BF::Application::Component::Type::GUI:
								{

									break;
								}

								default:
									break;
							}
						}
					}*/
				}
			}

			/*void SpriteRenderer::End()
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
			}*/

			void SpriteRenderer::SetScissor(const Math::Rectangle& rectangle)
			{
				Render(sortingOrder);
				BF::Engine::GetContext().SetScissor(rectangle);
			}

			void SpriteRenderer::CalculateUV(const Texture2D* texture, const Math::Rectangle& scissorRectangle, Vector2f* topLeft, Vector2f* topRight, Vector2f* bottomRight, Vector2f* bottomLeft)
			{
				*topLeft = Vector2f(1.0f / ((float)texture->GetTextureData()->width / (float)scissorRectangle.x),
									1.0f / ((float)texture->GetTextureData()->height / (float)scissorRectangle.y));

				*topRight = Vector2f(1.0f / ((float)texture->GetTextureData()->width / ((float)scissorRectangle.x + (float)scissorRectangle.width)),
									1.0f / ((float)texture->GetTextureData()->height / (float)scissorRectangle.y));

				*bottomRight = Vector2f(1.0f / ((float)texture->GetTextureData()->width / ((float)scissorRectangle.x + (float)scissorRectangle.width)),
										1.0f / ((float)texture->GetTextureData()->height / ((float)scissorRectangle.y + (float)scissorRectangle.height)));

				*bottomLeft = Vector2f(1.0f / ((float)texture->GetTextureData()->width / (float)scissorRectangle.x),
										1.0f / ((float)texture->GetTextureData()->height / ((float)scissorRectangle.y + (float)scissorRectangle.height)));
			}
		}
	}
}