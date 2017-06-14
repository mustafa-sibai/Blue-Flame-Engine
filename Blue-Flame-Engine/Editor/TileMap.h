#pragma once
#include <unordered_map>
#include <BF/Graphics/API/Texture2D.h>
#include <BF/Graphics/TileData.h>
#include <BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h>

namespace Editor
{
	class TileMap
	{
		private:
			BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
			std::vector<BF::Graphics::API::Texture2D*> textures;
			std::unordered_map<int, BF::Graphics::Renderers::Sprite> map;
		
		public:
			int tileWidth, tileHeight, mapWidth, mapHeight;

		public:
			TileMap();
			~TileMap();

			void AddSprite(BF::Graphics::Renderers::Sprite sprite, int index);
			
			void Initialize();
			void Update();
			void Render();
	};
}