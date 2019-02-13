#include "TabWindow.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			namespace TabWindow
			{
				using namespace std;
				using namespace BF::Math;
				using namespace BF::Graphics::Renderers;

				TabWindow::TabWindow()
				{
				}

				TabWindow::~TabWindow()
				{
				}

				void TabWindow::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
				{
					Widget::Initialize(spriteRenderer, zLayer);
					tab.Initialize(spriteRenderer, zLayer);
				}

				void TabWindow::Load(const StyleSheet& styleSheet, const string& widgetName)
				{
					Widget::Load(styleSheet, "TabWindow");
					tab.Load(styleSheet, "TabWindow/Tab");			
				}

				void TabWindow::Update()
				{
					Widget::Update();

					tab.SetPosition(Vector2f(GetPosition().x, GetPosition().y - tab.GetRectangle().height));
					tab.Update();
				}

				void TabWindow::Render()
				{
					Widget::Render();
					tab.Render();
				}
			}
		}
	}
}