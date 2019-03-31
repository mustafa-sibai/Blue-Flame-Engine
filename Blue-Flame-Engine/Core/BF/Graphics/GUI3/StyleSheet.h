#pragma once
#include <string>
#include <unordered_map>
#include "DependencyHeaders/TinyXML-2/tinyxml2.h"
#include "BF/Graphics/GUI3/Widget.h"
#include "BF/Graphics/Renderers/RenderLayer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BFE_API StyleSheet
			{
			private:
				std::unordered_map<std::string, BF::Graphics::GUI::IWidget*> widgets;
				BF::Graphics::API::Texture2D* texture;
				BF::Graphics::Renderers::RenderLayer& GUIRenderLayer;

			public:
				StyleSheet(BF::Graphics::Renderers::RenderLayer& GUIRenderLayer);
				~StyleSheet();

				void Load(const std::string& filename);

				inline BF::Graphics::GUI::IWidget& GetWidget(const std::string& name) const { return *widgets.at(name); }

			private:
				BF::Math::Rectangle ReadWidgetData(tinyxml2::XMLElement* widgetNode, const std::string& state, const std::string& type);
				BF::Math::Rectangle ReadWidgetDimensions(tinyxml2::XMLElement* widgetNode);
				//void SetText(tinyxml2::XMLElement* widgetNode, WidgetData& widgetData);
				bool DoesStateExist(tinyxml2::XMLElement* widgetNode, const std::string& state);
				bool DoesTypeExist(tinyxml2::XMLElement* widgetNode, const std::string& state, const std::string& type);
				bool HasText(tinyxml2::XMLElement* widgetNode);

				void LoadWidget(tinyxml2::XMLElement* widgetNode, const std::string& widgetName);
				tinyxml2::XMLElement* GetXMLNode(tinyxml2::XMLElement* root, const std::string& widgetName);
			};
		}
	}
}