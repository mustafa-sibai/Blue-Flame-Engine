#pragma once
#include <string>
#include <vector>
#include <tinyxml2.h>
#include "BF/Graphics/Renderers/Sprite.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			struct Component
			{
				std::string name;
				Renderers::Sprite hoveredSprite;
				Renderers::Sprite pressedSprite;
				Renderers::Sprite releasedSprite;
			};

			class BF_API StyleSheet
			{
				private:
					std::string styleSheetNode;
					std::vector<Component> GUIComponents;
					API::Texture2D* texture;

				public:
					StyleSheet() = default;
					StyleSheet(const API::Shader& shader);
					~StyleSheet();

					void Load(const std::string& filename);

					inline Component GetComponent(const std::string& name) const
					{
						for (size_t i = 0; i < GUIComponents.size(); i++)
							if (GUIComponents[i].name == name)
								return GUIComponents[i];

						return Component();
					}

				private:
					Math::Rectangle ReadComponent(const tinyxml2::XMLDocument& xmlDocument, const std::string& name, const std::string& type);
					void AddButtonComponent(const tinyxml2::XMLDocument& xmlDocument);
			};
		}
	}
}