#include "Slider.h"

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

				Slider::Slider()
				{
				}

				Slider::~Slider()
				{
				}

				void Slider::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
				}

				void Slider::Load(const StyleSheet& styleSheet, const string& widgetName)
				{
					Widget::Load(styleSheet, widgetName);
				}

				void Slider::Update()
				{
					Widget::Update();
				}

				void Slider::Render()
				{
					Widget::Render();
				}
			}
		}
	}
}