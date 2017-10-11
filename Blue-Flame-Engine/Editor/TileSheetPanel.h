#pragma once
#include <BF/BlueFlame.h>
#include "Grid.h"
#include "PaintTile.h"

namespace Editor
{
	class TileSheetPanel : public BF::Graphics::GUI::Panel
	{
		private:
			BF::Math::Rectangle rectangle;
			BF::Math::Rectangle gridRectangle;
			Grid grid;
			PaintTile& paintTile;
			BF::Graphics::Renderers::Sprite tilesheet;
			BF::Graphics::Renderers::RegularPolygon highlighter;

		public:
			BF::Graphics::API::Texture2D texture;

		public:
			TileSheetPanel(BF::Application::Scene& scene, PaintTile& paintTile);
			~TileSheetPanel();

		protected:
			void Initialize(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
			void Load(const BF::Graphics::GUI::StyleSheet& StyleSheet, const std::string& widgetName) override;
			void Update() override;
			void Render() override;
	};
}