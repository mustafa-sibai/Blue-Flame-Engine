#include "Checkbox.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;

			Checkbox::Checkbox(Application::Scene& scene) :
				checked(false)
			{
				scene.GetWidgetManager().AddWidget(this);
			}

			Checkbox::~Checkbox()
			{
			}

			void Checkbox::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
			}

			void Checkbox::Load(const StyleSheet& StyleSheet, const string& widgetName)
			{
				Widget::Load(StyleSheet, "Checkbox");
			}

			void Checkbox::Update()
			{
				Widget::Update();

				if (IsPressedAndReleased())
				{
					SwitchState();
					checked == false ? checked = true : checked = false;
				}
			}

			void Checkbox::Render()
			{
				Widget::Render();
			}
		}
	}
}