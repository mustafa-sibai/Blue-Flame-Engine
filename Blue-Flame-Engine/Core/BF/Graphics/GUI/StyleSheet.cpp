#include "StyleSheet.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Math;
			using namespace std;

			StyleSheet::StyleSheet(const API::Shader& shader) :
				styleSheetNode("GUIStyle")
			{
				texture = new Texture2D(shader);
			}

			StyleSheet::~StyleSheet()
			{
			}

			void StyleSheet::Load(const string& filename)
			{
				tinyxml2::XMLDocument xmlDocument;
				xmlDocument.LoadFile(filename.c_str());

				const char* title = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement("StyleSheet")->Attribute("Path");
				string textureFilename = string(title);
				texture->Load(textureFilename);

				LoadWidget(xmlDocument, "Button");
				LoadWidget(xmlDocument, "Panel");
			}

			Math::Rectangle StyleSheet::ReadWidgetData(const tinyxml2::XMLDocument& xmlDocument, const std::string& name, const std::string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("X");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Y");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			Math::Rectangle StyleSheet::ReadWidgetDimensions(const tinyxml2::XMLDocument& xmlDocument, const std::string& name, const std::string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("MinWidth");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("MinHeight");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			void StyleSheet::LoadWidget(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName)
			{
				WidgetData widgetData;
				Rectangle rectangle, scissorRectangle;

				rectangle = ReadWidgetDimensions(xmlDocument, widgetName, "Dimensions");

				widgetData.minWidth = rectangle.x;
				widgetData.minHeight = rectangle.y;

				scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "Normal");
				widgetData.normalSprite = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

				scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "Hovered");
				widgetData.hoveredSprite = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

				scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "Pressed");
				widgetData.pressedSprite = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

				widgetsData.insert({ widgetName, widgetData });
			}
		}
	}
}