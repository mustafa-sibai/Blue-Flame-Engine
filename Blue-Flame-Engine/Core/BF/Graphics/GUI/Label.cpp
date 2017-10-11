#include "Label.h"
#include "BF/Graphics/GUI/WidgetManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Fonts;

			Label::Label(Application::Scene& scene)
			{
				scene.GetWidgetManager().AddWidget(this);
			}

			Label::~Label()
			{
			}

			void Label::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
			}

			void Label::Load(const StyleSheet& StyleSheet, const std::string& widgetName)
			{
				Widget::Load(StyleSheet, "Label");
			}

			void Label::Update()
			{
				Widget::Update();
			}

			void Label::Render()
			{
				Widget::Render();
			}
		}
	}
}