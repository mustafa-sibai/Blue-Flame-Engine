#include "TileMap.h"
#include "BF/IO/BFMLoader.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Graphics::API;
		//using namespace BF::Graphics::Renderers;
		using namespace BF::IO;

		TileMap::TileMap()
		{
		}

		TileMap::~TileMap()
		{
		}

		void TileMap::Initialize()
		{
			//spriteRenderer.Initialize();
		}

		void TileMap::Load(const string& filename)
		{
			/*tileMapData = BFMLoader::Load(filename);

			for (size_t i = 0; i < tileMapData->textures.size(); i++)
			{
				Texture2D* texture = new Texture2D();
				texture->Load(tileMapData->textures[i]);
				textures.push_back(texture);
			}

			for (size_t i = 0; i < tileMapData->tilesData.size(); i++)
				sprites.push_back(Sprite(textures[tileMapData->tilesData[i].textureID], tileMapData->tilesData[i].rectangle, 0, tileMapData->tilesData[i].scissorRectangle, Color(1.0f)));*/
		}

		void TileMap::Update()
		{
		}

		void TileMap::Render()
		{
			/*spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);

			for (size_t i = 0; i < sprites.size(); i++)
				spriteRenderer.Render(sprites[i]);

			spriteRenderer.End();*/
		}
	}
}