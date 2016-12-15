#include "Button.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Renderers;

			Button::Button(Renderers::SpriteRenderer& spriteRenderer) :
				spriteRenderer(spriteRenderer)
			{
			}

			Button::~Button()
			{
			}

			void Button::Load(const StyleSheet& StyleSheet)
			{
				component = StyleSheet.GetComponent("Button");
			}

			void Button::Update()
			{
			}

			void Button::Render()
			{
				spriteRenderer.Submit(component.releasedSprite);
			}
		}
	}
}