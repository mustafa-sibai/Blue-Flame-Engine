#pragma once
#include <string>
#include <unordered_map>
#include "DependencyHeaders/TinyXML-2/tinyxml2.h"
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Graphics/Renderers/SpriteRenderer/Sprite.h"
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
					std::unordered_map<std::string, WidgetData> widgetsData;
					API::Texture2D* texture;

				public:
					StyleSheet();
					~StyleSheet();

					void Load(const std::string& filename);

					inline const WidgetData& GetWidget(const std::string& name) const { return widgetsData.at(name); }

				private:
					Math::Rectangle ReadWidgetData(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName, const std::string& state, const std::string& type);
					Math::Rectangle ReadWidgetDimensions(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName, const std::string& type);
					void SetText(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName, const std::string& type, WidgetData& widgetData);
					bool DoesStateExist(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName, const std::string& state);
					bool DoesTypeExist(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName, const std::string& state, const std::string& type);
					bool HasText(const tinyxml2::XMLDocument& xmlDocument, const std::string& name);

					void LoadWidget(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName);
			};
		}
	}
}