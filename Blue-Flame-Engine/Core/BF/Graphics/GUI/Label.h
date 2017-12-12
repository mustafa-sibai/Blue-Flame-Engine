#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API Label : public Widget
			{
				private:
					Renderers::Text text;

				public:
					Label();
					~Label();

				private:
					void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
					void Load(const StyleSheet& styleSheet, const std::string& widgetName) override;
					void Update() override;
					void Render() override;
			};
		}
	}
}