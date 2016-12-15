#pragma once
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "StyleSheet.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API Button
			{
				private:
					Renderers::SpriteRenderer& spriteRenderer;
					Component component;

				public:
					Button(Renderers::SpriteRenderer& spriteRenderer);
					~Button();

					void Load(const StyleSheet& StyleSheet);
					void Update();
					void Render();

					inline bool IsHovered() { return true; }
					inline bool IsPressed() { return true; }
					inline bool IsReleased() { return true; }
			};
		}
	}
}