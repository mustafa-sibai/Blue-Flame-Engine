#include "TileMap.h"
#include "BF/IO/BFMLoader.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Graphics::API;
		using namespace BF::Graphics::Renderers;
		using namespace BF::Math;
		using namespace BF::IO;

		TileMap::TileMap() :
			spriteRenderer(shader)
		{
		}

		TileMap::~TileMap()
		{
		}

		void TileMap::Load(const std::string& filename)
		{
			spriteRenderer.Initialize();

			shader.Load("Assets/Shaders/GLSL/SpriteRenderer/VertexShader.glsl", "Assets/Shaders/GLSL/SpriteRenderer/PixelShader.glsl");
			shader.Bind();

			tileMapData = BFMLoader::Load(filename);

			for (size_t i = 0; i < tileMapData->textures.size(); i++)
			{
				Texture2D* texture = new Texture2D(shader);
				texture->Load(tileMapData->textures[i]);
				textures.push_back(texture);
			}

			for (size_t i = 0; i < tileMapData->tilesData.size(); i++)
				sprites.push_back(Sprite(textures[tileMapData->tilesData[i].textureID], tileMapData->tilesData[i].rectangle, tileMapData->tilesData[i].scissorRectangle, Vector4(1.0f)));
		}

		void TileMap::Update()
		{
		}

		void TileMap::Draw()
		{
			spriteRenderer.Begin(Renderers::SpriteRenderer::SubmitType::DynamicSubmit);

			for (size_t i = 0; i < sprites.size(); i++)
				spriteRenderer.Render(sprites[i]);

			spriteRenderer.End();
		}
	}
}