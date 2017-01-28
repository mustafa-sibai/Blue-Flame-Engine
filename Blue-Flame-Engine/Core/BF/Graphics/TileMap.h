#pragma once
#include <vector>
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/TileData.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Math/Math.h"
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

		class BF_API TileMap
		{
		private:
			Renderers::SpriteRenderer spriteRenderer;
			std::vector<API::Texture2D*> textures;
			std::vector<Renderers::Sprite> sprites;

			TileMapData* tileMapData;

			int tileWidth, tileHeight, mapWidth, mapHeight;

		public:
			TileMap();
			~TileMap();

			void Load(const std::string& filename);
			void Update();
			void Draw();
		};
	}
}