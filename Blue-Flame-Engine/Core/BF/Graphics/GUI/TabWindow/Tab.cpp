#include "Tab.h"
#include "BF/Graphics/GUI/TabWindow/TabWindow.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace TabWindow
			{
				using namespace std;
				using namespace BF::Graphics::Renderers;

				Tab::Tab()
				{
				}

				Tab::~Tab()
				{
				}

				void Tab::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
				}

				void Tab::Load(const StyleSheet& styleSheet, const string& widgetName)
				{
					Widget::Load(styleSheet, widgetName);
				}

				void Tab::Update()
				{
					Widget::Update();

					if (hovered && pressed)
					{

					}
				}

				void Tab::Render()
				{
					Widget::Render();
				}
			}
		}
	}
}