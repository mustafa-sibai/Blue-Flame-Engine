#include "StyleSheet.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Math;

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
				LoadWidget(xmlDocument, "Checkbox");
				LoadWidget(xmlDocument, "Panel");
				LoadWidget(xmlDocument, "Scrollbar");
				LoadWidget(xmlDocument, "ScrollbarSlider");
			}

			Math::Rectangle StyleSheet::ReadWidgetData(const tinyxml2::XMLDocument& xmlDocument, const string& name, const string& state, const string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("X");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Y");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			Math::Rectangle StyleSheet::ReadWidgetDimensions(const tinyxml2::XMLDocument& xmlDocument, const string& name, const string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("MinWidth");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("MinHeight");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			bool StyleSheet::DoesStateExist(const tinyxml2::XMLDocument& xmlDocument, const string& name, const string& state)
			{
				return xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(state.c_str()) == NULL ? false : true;
			}

			bool StyleSheet::DoesTypeExist(const tinyxml2::XMLDocument& xmlDocument, const string& name, const string& state, const string& type)
			{
				return xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str()) == NULL ? false : true;
			}

			void StyleSheet::LoadWidget(const tinyxml2::XMLDocument& xmlDocument, const string& widgetName)
			{
				WidgetData widgetData;
				Rectangle rectangle, scissorRectangle;

				rectangle = ReadWidgetDimensions(xmlDocument, widgetName, "Dimensions");

				widgetData.minWidth = rectangle.x;
				widgetData.minHeight = rectangle.y;

				scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "FirstState", "Normal");
				widgetData.sprites[0] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

				scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "FirstState", "Hovered");
				widgetData.sprites[1] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

				scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "FirstState", "Pressed");
				widgetData.sprites[2] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

				if (DoesTypeExist(xmlDocument, widgetName, "FirstState", "Disabled"))
				{
					scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "FirstState", "Disabled");
					widgetData.sprites[3] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));
				}

				if (DoesStateExist(xmlDocument, widgetName, "SecondState"))
				{
					scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "SecondState", "Normal");
					widgetData.sprites[4] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "SecondState", "Hovered");
					widgetData.sprites[5] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "SecondState", "Pressed");
					widgetData.sprites[6] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					if (DoesTypeExist(xmlDocument, widgetName, "SecondState", "Disabled"))
					{
						scissorRectangle = ReadWidgetData(xmlDocument, widgetName, "SecondState", "Disabled");
						widgetData.sprites[7] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));
					}
				}

				widgetsData.insert({ widgetName, widgetData });
			}
		}
	}
}