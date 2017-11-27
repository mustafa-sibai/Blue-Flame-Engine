#include "Button.h"
#include "BF/Graphics/GUI/WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;
			using namespace BF::Graphics::Renderers;

			Button::Button()
			{
			}

			Button::~Button()
			{
			}

			void Button::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
			}

			void Button::Load(const StyleSheet& StyleSheet, const string& widgetName)
			{
				Widget::Load(StyleSheet, "Button");
			}

			void Button::Update()
			{
				Widget::Update();
			}

			void Button::Render()
			{
				Widget::Render();
			}
		}
	}
}