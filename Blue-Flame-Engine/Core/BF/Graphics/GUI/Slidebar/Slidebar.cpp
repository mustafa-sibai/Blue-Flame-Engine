#include "Slidebar.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace Slidebar
			{
				using namespace std;
				using namespace BF::Math;
				using namespace BF::Graphics::Renderers;

				Slidebar::Slidebar()
				{
				}

				Slidebar::~Slidebar()
				{
				}

				void Slidebar::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
				}

				void Slidebar::Load(const StyleSheet& styleSheet, const string& widgetName)
				{
					Widget::Load(styleSheet, "Slidebar");
				}

				void Slidebar::Update()
				{
					Widget::Update();
				}

				void Slidebar::Render()
				{
					Widget::Render();
				}
			}
		}
	}
}