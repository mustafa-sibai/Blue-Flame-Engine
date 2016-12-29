#pragma once
#include <string>
#include <vector>
#include <tinyxml2.h>
#include "Widget.h"
#include "BF/Graphics/Renderers/Sprite.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API StyleSheet
			{
				private:
					std::string styleSheetNode;
					std::vector<WidgetData> widgetsData;
					API::Texture2D* texture;

				public:
					StyleSheet(const API::Shader& shader);
					~StyleSheet();

					void Load(const std::string& filename);

					inline WidgetData GetWidgetData(const std::string& name) const
					{
						for (size_t i = 0; i < widgetsData.size(); i++)
							if (widgetsData[i].name == name)
								return widgetsData[i];

						return WidgetData();
					}

				private:
					Math::Rectangle ReadWidgetData(const tinyxml2::XMLDocument& xmlDocument, const std::string& name, const std::string& type);
					void AddButtonWidget(const tinyxml2::XMLDocument& xmlDocument);
			};
		}
	}
}