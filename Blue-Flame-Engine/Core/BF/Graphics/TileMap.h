#pragma once
#include <vector>
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/TileData.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct TileMapData
		{
			std::vector<std::string> textures;
			std::vector<TileData> tilesData;
		};

		class BFE_API TileMap
		{
			private:
				//BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
				std::vector<API::Texture2D*> textures;
				std::vector<Renderers::SpriteRendererComponents::Sprite> sprites;

				TileMapData* tileMapData;

				int tileWidth, tileHeight, mapWidth, mapHeight;

			public:
				TileMap();
				~TileMap();

				void Initialize();
				void Load(const std::string& filename);
				void Update();
				void Render();
		};
	}
}