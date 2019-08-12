#include "SpriteRenderer.h"
#include <algorithm>
#include "BF/Engine.h"
#include "BF/System/Debug.h"
#include "BF/ECS/GameObject.h"

#define BFE_MAX_SPRITES     60000
#define BFE_SPRITE_VERTICES 4
#define	BFE_SPRITE_INDICES  6
#define BFE_VERTICES_SIZE	BFE_MAX_SPRITES * BFE_SPRITE_VERTICES
#define BFE_INDICES_SIZE	BFE_MAX_SPRITES * BFE_SPRITE_INDICES

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;
			using namespace BF::ECS;
			using namespace BF::Math;
			using namespace BF::Application;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Fonts;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			const BF::Graphics::API::Texture2D* SpriteRenderer::currentBoundTexture = nullptr;

			SpriteRenderer::SpriteRenderer() :
				IRenderer(RendererType::SpriteRenderer),
				spriteBuffer(nullptr), indexCount(0), submitSprite(true), totalDrawCalls(0)
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

				unsigned int* indices = new unsigned int[BFE_INDICES_SIZE];
				int index = 0;

				/*
				Winding order is clock-wise.
				0 -> 1 -> 2 ---> 2 -> 3 -> 0

					0      1
					 ______
					|\     |
					| \    |
					|  \   |
					|   \  |
					|    \ |
					|_____\|
					3      2
				*/

				for (unsigned int i = 0; i < BFE_INDICES_SIZE; i += BFE_SPRITE_INDICES)
				{
					indices[i + 0] = index + 0;
					indices[i + 1] = index + 1;
					indices[i + 2] = index + 2;

					indices[i + 3] = index + 2;
					indices[i + 4] = index + 3;
					indices[i + 5] = index + 0;

					index += BFE_SPRITE_VERTICES;
				}

				vertexBuffer.Create(BFE_VERTICES_SIZE * sizeof(SpriteBuffer), nullptr);
				indexBuffer.Create(indices, BFE_INDICES_SIZE);
				vertexBuffer.SetLayout(shader, &vertexBufferLayout);

				Engine::GetContext().EnableDepthBuffer(false);
				Engine::GetContext().EnableBlending(true);
				Engine::GetContext().EnableScissor(true);

				delete[] indices;
			}

			void SpriteRenderer::Load()
			{
			}

			void SpriteRenderer::PostLoad()
			{
			}

			void SpriteRenderer::Update(double deltaTime)
			{
			}

			void SpriteRenderer::Render()
			{
				totalDrawCalls = 0;
				shader.Bind();
				spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();

				if (submitSprite)
				{
					/*if (!once)
					{
						std::random_shuffle(renderables.begin(), renderables.end());
						once = true;
					}*/

					MapBuffer();
					vertexBuffer.Unmap();
				}

				vertexBuffer.Bind();
				indexBuffer.Bind();
				Engine::GetContext().Draw(indexCount);
				indexBuffer.Unbind();
				vertexBuffer.Unbind();
				totalDrawCalls++;

				indexCount = 0;
				currentBoundTexture = nullptr;

				//BFE_LOG_INFO("Draw calls " + std::to_string(totalDrawCalls), "");
			}

			void SpriteRenderer::MapLineBuffer(const LineShape* lineShape)
			{
				Vector2f normal = Vector2f(lineShape->endPoint.y - lineShape->startPoint.y, lineShape->endPoint.x - lineShape->startPoint.x).Normalize() * lineShape->thickness;

				//Top Left
				spriteBuffer->position = lineShape->startPoint;
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2f(lineShape->startPoint.x - normal.x, lineShape->startPoint.y + normal.y);
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2f(lineShape->endPoint.x - normal.x, lineShape->endPoint.y + normal.y);
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2f(lineShape->endPoint.x, lineShape->endPoint.y);
				spriteBuffer->color = lineShape->color;
				spriteBuffer->UV = Vector2f(0.0f);
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				indexCount += BFE_SPRITE_INDICES;
			}

			void SpriteRenderer::MapPolygonBuffer(const RegularPolygon* regularPolygon)
			{
				Vector3f position = regularPolygon->gameObject->GetTransform()->GetPosition();
				Vector3f scale = regularPolygon->gameObject->GetTransform()->GetScale();

				Vector2i scaledSprite = Vector2i(regularPolygon->size.x * scale.x, regularPolygon->size.y * scale.y);

				/*
				x = left position
				y = top position
				width = right position
				hgiht = bottom position

				   x, y      width, y
					 ----------
					 |        |
					 | sprite |
					 |        |
					 ---------- width, height
				  x, height

				  if we have an odd number of pixels and we want to center the image in the middle of the screen
				  the extra pixels will always be at the bottom right.
				  Meaning more of the image will be on the bottom right side rather than top left side.

				  --------------------
				  |       Screen     |
				  |                  |
				  |     -----------  |
				  |     |---------|  |
				  |     |--image--|  |
				  |     -----------  |
				  --------------------

				  as you can see, the image is close to the bottom right of the screen.
				*/
				vector<Vector2i> corners = BF::Math::Rectangle(position.x, position.y, scaledSprite.x, scaledSprite.y, regularPolygon->pivot).GetCorners();

				//Top Left
				spriteBuffer->position = Vector2f(corners[0].x, corners[0].y);
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);;
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2f(corners[1].x, corners[1].y);
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);;
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2f(corners[2].x, corners[2].y);
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);;
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2f(corners[3].x, corners[3].y);
				spriteBuffer->color = regularPolygon->color;
				spriteBuffer->UV = Vector2f(0.0f);;
				spriteBuffer->renderingType = 0;
				spriteBuffer++;

				indexCount += BFE_SPRITE_INDICES;
			}

			void SpriteRenderer::MapSpriteBuffer(const Sprite* sprite)
			{
				if (currentBoundTexture != nullptr)
				{
					if (currentBoundTexture != sprite->texture2D)
					{
						vertexBuffer.Unmap();

						vertexBuffer.Bind();
						indexBuffer.Bind();
						Engine::GetContext().Draw(indexCount);
						indexBuffer.Unbind();
						vertexBuffer.Unbind();

						indexCount = 0;
						totalDrawCalls++;

						spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();
					}
				}

				if (currentBoundTexture != sprite->texture2D)
				{
					sprite->texture2D->Bind();
					currentBoundTexture = sprite->texture2D;
				}

				Vector2f topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
				CalculateUV(sprite->texture2D, sprite->scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

				Vector3f position = sprite->gameObject->GetTransform()->GetPosition();
				Vector3f scale = sprite->gameObject->GetTransform()->GetScale();

				Vector2i scaledSprite = Vector2i(sprite->size.x * scale.x, sprite->size.y * scale.y);

				/*
				x = left position
				y = top position
				width = right position
				hgiht = bottom position

				   x, y      width, y
					 ----------
					 |        |
					 | sprite |
					 |        |
					 ---------- width, height
				  x, height

				  if we have an odd number of pixels and we want to center the image in the middle of the screen
				  the extra pixels will always be at the bottom right.
				  Meaning more of the image will be on the bottom right side rather than top left side.

				  --------------------
				  |       Screen     |
				  |                  |
				  |     -----------  |
				  |     |---------|  |
				  |     |--image--|  |
				  |     -----------  |
				  --------------------

				  as you can see, the image is close to the bottom right of the screen.
				*/
				vector<Vector2i> corners = BF::Math::Rectangle(position.x, position.y, scaledSprite.x, scaledSprite.y, sprite->pivot).GetCorners();

				//Top Left
				spriteBuffer->position = Vector2f(corners[0].x, corners[0].y);
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = topLeftUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Top Right
				spriteBuffer->position = Vector2f(corners[1].x, corners[1].y);
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = topRightUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Bottom Right
				spriteBuffer->position = Vector2f(corners[2].x, corners[2].y);
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = bottomRightUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				//Bottom Left
				spriteBuffer->position = Vector2f(corners[3].x, corners[3].y);
				spriteBuffer->color = sprite->color;
				spriteBuffer->UV = bottomLeftUV;
				spriteBuffer->renderingType = 1;
				spriteBuffer++;

				indexCount += BFE_SPRITE_INDICES;
			}

			void SpriteRenderer::MapTextBuffer(Text* text)
			{
				if (currentBoundTexture != nullptr)
				{
					if (currentBoundTexture != text->font->texture)
					{
						vertexBuffer.Unmap();

						vertexBuffer.Bind();
						indexBuffer.Bind();
						Engine::GetContext().Draw(indexCount);
						indexBuffer.Unbind();
						vertexBuffer.Unbind();

						indexCount = 0;
						totalDrawCalls++;

						spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();
					}
				}

				if (currentBoundTexture != text->font->texture)
				{
					text->font->texture->Bind();
					currentBoundTexture = text->font->texture;
				}

				text->size = Vector2i();
				int biggestUnderLine = 0;
				vector<Vector2i> corners;
				Vector2f topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
				text->characterPositions.clear();
				
				Vector2i cursorPosition;
				Vector3f position = text->gameObject->GetTransform()->GetPosition();
				Vector3f scale = text->gameObject->GetTransform()->GetScale();

				for (size_t i = 0; i < text->text.size(); i++)
				{
					int unicode = text->text[i] - 32;
					cursorPosition.y = ((*text->font->characters)[unicode].bearing.y - text->font->fontMaxYBearing) * scale.y;

					//UnderLine is a variable that stores the hight of that character that is under a line. For example, the letter "g" bottom half is under the line
					int underLine = ((*text->font->characters)[unicode].scissorRectangle.height - (*text->font->characters)[unicode].bearing.y) * scale.y;
					biggestUnderLine = biggestUnderLine < underLine ? biggestUnderLine = underLine : biggestUnderLine;

					if (i > 0)
						cursorPosition.x += (int)(*text->font->characters)[unicode].bearing.x * scale.x;

					text->characterPositions.push_back(cursorPosition);

					if (i > 0)
						cursorPosition.x -= (*text->font->characters)[unicode].bearing.x * scale.x;

					cursorPosition.x += (*text->font->characters)[unicode].advance.x * scale.x;

					text->size.x += (*text->font->characters)[unicode].advance.x;
					text->size.y = (text->font->fontMaxYBearing + biggestUnderLine);
				}

				text->size *= Vector2i(scale.x, scale.y);

				BF::Math::Rectangle offset = BF::Math::Rectangle(position.x, position.y, text->size.x, text->size.y, text->pivot).GetEdgeOffsetByPivot();

				for (size_t i = 0; i < text->text.size(); i++)
				{
					int unicode = text->text[i] - 32;
					CalculateUV(text->font->texture, (*text->font->characters)[unicode].scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

					Vector2i scaledCharacter = Vector2i((*text->font->characters)[unicode].scissorRectangle.width * scale.x,
														(*text->font->characters)[unicode].scissorRectangle.height * scale.y);

					/*
					x = left position
					y = top position
					width = right position
					hgiht = bottom position

					   x, y      width, y
						 ----------
						 |        |
						 | sprite |
						 |        |
						 ---------- width, height
					  x, height

					  if we have an odd number of pixels, the extra pixels will always be at the bottom right.
					  Meaning more of the image will be on the bottom right side rather than top left side.

					  --------------------
					  |      Screen      |
					  |    -----------   |
					  |    |---------|   |
					  |    |--image--|   |
					  |    -----------   |
					  --------------------

					  as you can see, the image is close to the top left center of the screen.
					*/

					corners = BF::Math::Rectangle(text->characterPositions[i].x, text->characterPositions[i].y,
												  scaledCharacter.x, scaledCharacter.y, Vector2f()).GetCorners();

					//Top Left
					spriteBuffer->position = Vector2f(corners[0].x + offset.x, corners[0].y + offset.y);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = topLeftUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position = Vector2f(corners[1].x + offset.x, corners[1].y + offset.y);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = topRightUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position = Vector2f(corners[2].x + offset.x, corners[2].y + offset.y);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = bottomRightUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position = Vector2f(corners[3].x + offset.x, corners[3].y + offset.y);
					spriteBuffer->color = text->color;
					spriteBuffer->UV = bottomLeftUV;
					spriteBuffer->renderingType = 2;
					spriteBuffer++;

					indexCount += BFE_SPRITE_INDICES;
				}
			}

			void SpriteRenderer::MapBuffer()
			{
				if (submitSprite)
				{
					for (size_t i = 0; i < renderLayerManager.renderLayers.size(); i++)
					{
						renderLayerManager.renderLayers[i]->Sort();

						for (size_t j = 0; j < renderLayerManager.renderLayers[i]->renderables.size(); j++)
						{
							IRenderable* iRenderable = renderLayerManager.renderLayers[i]->renderables[j];

							if (iRenderable->type == IRenderable::Type::Sprite)
								MapSpriteBuffer((Sprite*)iRenderable);
							else if (iRenderable->type == IRenderable::Type::RegularPolygon)
								MapPolygonBuffer((RegularPolygon*)iRenderable);
							else if (iRenderable->type == IRenderable::Type::LineShape)
								MapLineBuffer((LineShape*)iRenderable);
							else if (iRenderable->type == IRenderable::Type::Text)
								MapTextBuffer((Text*)iRenderable);
						}
					}
				}
			}

			void SpriteRenderer::SetScissor(const Math::Rectangle& rectangle)
			{
				Render();
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