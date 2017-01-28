#include "SpriteRenderer.h"
#include <algorithm>
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

			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Graphics::Fonts;
			using namespace BF::Math;

			SpriteRenderer::SpriteRenderer() :
				vertexBuffer(shader), constentBuffer(shader), indexCount(0), submitSprite(true)
			{
				indexBuffer = new IndexBuffer();
			}

			SpriteRenderer::~SpriteRenderer()
			{
			}

			void SpriteRenderer::Initialize()
			{
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
				systemBuffer.modelMatrix = Matrix4::Identity();
				systemBuffer.viewMatrix = Matrix4::Identity();
				systemBuffer.projectionMatrix = Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f);

				vertexBufferLayout.Push(0, "POSITION",		VertexBufferLayout::DataType::Float3, sizeof(SpriteBuffer), 0);
				vertexBufferLayout.Push(1, "COLOR",			VertexBufferLayout::DataType::Float4, sizeof(SpriteBuffer), sizeof(Vector3));
				vertexBufferLayout.Push(2, "TEXCOORD",		VertexBufferLayout::DataType::Float2, sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4));
				vertexBufferLayout.Push(3, "TEXTUREID",		VertexBufferLayout::DataType::Float,  sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2));
				vertexBufferLayout.Push(4, "RENDERINGTYPE", VertexBufferLayout::DataType::Float,  sizeof(SpriteBuffer), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2) + sizeof(float));
				
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
				indexBuffer->Create(indecies, INDICES_SIZE);
				constentBuffer.Create(sizeof(SystemBuffer), 0);

				Engine::GetContext().EnableDepthBuffer(false);
				Engine::GetContext().EnableBlending(true);
				delete indecies;
			}

			void SpriteRenderer::Begin(SubmitType submitType, SortingOrder sortingOrder)
			{
				this->submitType = submitType;
				this->sortingOrder = sortingOrder;

				shader.Bind();
				constentBuffer.Update(&systemBuffer, sizeof(systemBuffer));

				if (submitSprite)
					spriteBuffer = (SpriteBuffer*)vertexBuffer.Map();
			}

			void SpriteRenderer::Render(Sprite& sprite)
			{
				if (submitSprite)
				{
					if (!sprite.submitted)
					{
						sprites.push_back(&sprite);
						sprites[sprites.size() - 1][0].indexInVector = (unsigned int)sprites.size() - 1;
						sprite.submitted = true;
					}
					sprite.recentlySubmitted = true;
				}
			}

			void SpriteRenderer::RenderRectangle(const Rectangle& rectangle, const Vector4& Color)
			{
				if (submitSprite)
				{
					//Top Left
					spriteBuffer->position		= Vector3((float)rectangle.x, (float)rectangle.y, 0.0f);
					spriteBuffer->color			= Color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->textureID		= -1.0f;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position		= Vector3((float)(rectangle.x + rectangle.width), (float)rectangle.y, 0.0f);
					spriteBuffer->color			= Color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->textureID		= -1.0f;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position		= Vector3((float)(rectangle.x + rectangle.width), (float)(rectangle.y + rectangle.height), 0.0f);
					spriteBuffer->color			= Color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->textureID		= -1.0f;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position		= Vector3((float)rectangle.x, (float)(rectangle.y + rectangle.height), 0.0f);
					spriteBuffer->color			= Color;
					spriteBuffer->UV			= Vector2(0.0f);
					spriteBuffer->textureID		= -1.0f;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::MapBuffer()
			{
				int totalSpritesRemoved = 0;

				for (size_t i = 0; i < sprites.size(); i++)
				{
					if (!sprites[i][0].recentlySubmitted)
					{
						totalSpritesRemoved++;
						sprites[i][0].submitted = false;
						sprites[i][0].recentlySubmitted = false;

						sprites.erase(sprites.begin() + sprites[i][0].indexInVector);
					}

					if(totalSpritesRemoved > 0)
						sprites[i][0].indexInVector -= totalSpritesRemoved;

					float textureID = FindTexture(sprites[i][0].texture2D);

					if ((int)textureID > MAX_TEXTURES)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						End();
						Begin(submitType, sortingOrder);
						textureID = FindTexture(sprites[i][0].texture2D);
					}

					sprites[i][0].texture2D->Bind("textures[" + to_string((unsigned int)textureID) + string("]"), (unsigned int)textureID);

					Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
					CalculateUV(sprites[i][0].texture2D, sprites[i][0].scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

					//Top Left
					spriteBuffer->position		= sprites[i][0].position;
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= topLeftUV;
					spriteBuffer->textureID		= textureID;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Top Right
					spriteBuffer->position		= Vector3(sprites[i][0].position.x + sprites[i][0].rectangle.width, sprites[i][0].position.y, sprites[i][0].position.z);
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= topRightUV;
					spriteBuffer->textureID		= textureID;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Right
					spriteBuffer->position	= Vector3(sprites[i][0].position.x + sprites[i][0].rectangle.width, sprites[i][0].position.y + sprites[i][0].rectangle.height, sprites[i][0].position.z);
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= bottomRightUV;
					spriteBuffer->textureID		= textureID;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					//Bottom Left
					spriteBuffer->position		= Vector3(sprites[i][0].position.x, sprites[i][0].position.y + sprites[i][0].rectangle.height, sprites[i][0].position.z);
					spriteBuffer->color			= sprites[i][0].color;
					spriteBuffer->UV			= bottomLeftUV;
					spriteBuffer->textureID		= textureID;
					spriteBuffer->renderingType = 0;
					spriteBuffer++;

					sprites[i][0].recentlySubmitted = false;
					indexCount += SPRITE_INDICES;
				}
			}

			void SpriteRenderer::RenderText(const FontAtlas& fontAtlas, const string& text, const Vector3& position, const Vector4& color)
			{
				Rectangle prevPos;
				Vector3 pos = position;
				
				if (submitSprite)
				{
					float textureID = FindTexture(fontAtlas.texture);

					if ((int)textureID > MAX_TEXTURES)
					{
						if (submitType == SubmitType::StaticSubmit)
							return;

						End();
						Begin(submitType, sortingOrder);
						textureID = FindTexture(fontAtlas.texture);
					}

					fontAtlas.texture->Bind("textures[" + to_string((unsigned int)textureID) + string("]"), (unsigned int)textureID);

					for (size_t i = 0; i < text.length(); i++)
					{
						unsigned int unicode = text[i] - 32;
						Rectangle scissorRectangle = fontAtlas.characters[0][unicode].scissorRectangle;

						Vector2 topLeftUV, topRightUV, bottomRightUV, bottomLeftUV;
						CalculateUV(fontAtlas.texture, scissorRectangle, &topLeftUV, &topRightUV, &bottomRightUV, &bottomLeftUV);

						pos += Vector3(prevPos.x + fontAtlas.characters[0][unicode].bearing.x, 0, 0);
						prevPos.x = fontAtlas.characters[0][unicode].scissorRectangle.width;
						pos.y = position.y + (fontAtlas.characters[0][unicode].charPixelSize - fontAtlas.characters[0][unicode].bearing.y);

						//Top Left
						spriteBuffer->position		= pos;
						spriteBuffer->color			= color;
						spriteBuffer->UV			= topLeftUV;
						spriteBuffer->textureID		= textureID;
						spriteBuffer->renderingType = 1;
						spriteBuffer++;

						//Top Right
						spriteBuffer->position		= Vector3(pos.x + (float)scissorRectangle.width, pos.y, pos.z);
						spriteBuffer->color			= color;
						spriteBuffer->UV			= topRightUV;
						spriteBuffer->textureID		= textureID;
						spriteBuffer->renderingType = 1;
						spriteBuffer++;

						//Bottom Right
						spriteBuffer->position		= Vector3(pos.x + (float)scissorRectangle.width, pos.y + (float)scissorRectangle.height, pos.z);
						spriteBuffer->color			= color;
						spriteBuffer->UV			= bottomRightUV;
						spriteBuffer->textureID		= textureID;
						spriteBuffer->renderingType = 1;
						spriteBuffer++;

						//Bottom Left
						spriteBuffer->position		= Vector3((float)pos.x, pos.y + (float)scissorRectangle.height, pos.z);
						spriteBuffer->color			= color;
						spriteBuffer->UV			= bottomLeftUV;
						spriteBuffer->textureID		= textureID;
						spriteBuffer->renderingType = 1;
						spriteBuffer++;

						indexCount += SPRITE_INDICES;
					}
				}
			}

			void SpriteRenderer::End()
			{
				if (submitSprite)
				{
					if (sortingOrder == SortingOrder::BackToFront)
						sort(sprites.begin(), sprites.end(), Sprite::BackToFront());
					else if (sortingOrder == SortingOrder::FrontToBack)
						sort(sprites.begin(), sprites.end(), Sprite::FrontToBack());

					MapBuffer();
					vertexBuffer.Unmap();
				}

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