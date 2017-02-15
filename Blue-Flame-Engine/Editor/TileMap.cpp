#include "TileMap.h"

namespace Editor
{
	using namespace std;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::IO;

	TileMap::TileMap()
	{
	}

	TileMap::~TileMap()
	{
	}

	void TileMap::AddSprite(Sprite sprite, int index)
	{
		map.insert({ index, sprite });
	}

	void TileMap::Initialize()
	{
		spriteRenderer.Initialize();
	}

	void TileMap::Update()
	{

	}

	void TileMap::Render()
	{
		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);

		for (auto& sprite : map)
			spriteRenderer.Render(sprite.second);

		spriteRenderer.End();
	}
}