#pragma once
#include <BF/BlueFlame.h>
#include "Grid.h"

namespace Editor
{
	class TileSheetPanel : public BF::Graphics::GUI::Panel
	{
	private:
		BF::Math::Rectangle rectangle;
		BF::Math::Rectangle gridRectangle;
		Grid grid;

		BF::Graphics::Renderers::Sprite tilesheet;

	public:
		BF::Graphics::API::Texture2D texture;

	public:
		TileSheetPanel(BF::Application::Scene& scene);
		~TileSheetPanel();

	protected:
		void Initialize(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer) override;
		void Load(const BF::Graphics::GUI::StyleSheet& StyleSheet, const std::string& widgetName) override;
		void Update() override;
		void Render() override;
	};
}