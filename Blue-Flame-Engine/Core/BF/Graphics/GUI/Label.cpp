#include "Label.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Fonts;

			Label::Label()
			{
			}

			Label::~Label()
			{
			}

			void Label::Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer)
			{
				Widget::Initialize(spriteRenderer, zLayer);
			}

			void Label::Load(const StyleSheet& styleSheet, const std::string& widgetName)
			{
				Widget::Load(styleSheet, "Label");
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