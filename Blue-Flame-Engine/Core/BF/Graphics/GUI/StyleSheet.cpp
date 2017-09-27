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
			using namespace BF::Graphics::Fonts;
			using namespace BF::Math;

			StyleSheet::StyleSheet(const API::Shader& shader) :
				styleSheetNode("GUIStyle")
			{
				texture = new Texture2D(shader);
				font = new Font(shader);
			}

			StyleSheet::~StyleSheet()
			{
			}

			void StyleSheet::Load(const string& filename)
			{
				tinyxml2::XMLDocument xmlDocument;
				xmlDocument.LoadFile(filename.c_str());

				string texturefilename = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement("StyleSheet")->Attribute("Path");
				texture->Load(texturefilename);

				string fontfilename = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement("DefaultFont")->Attribute("Path");
				const char* size = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement("DefaultFont")->Attribute("Size");
				font->Load(fontfilename, atoi(size), FontAtlasFactory::Language::English);

				LoadWidget(xmlDocument, "Label");
				LoadWidget(xmlDocument, "Button");
				LoadWidget(xmlDocument, "Checkbox");
				LoadWidget(xmlDocument, "Panel");
				LoadWidget(xmlDocument, "Scrollbar");
				LoadWidget(xmlDocument, "ScrollbarSlider");
			}

			Math::Rectangle StyleSheet::ReadWidgetData(const tinyxml2::XMLDocument& xmlDocument, const string& widgetName, const string& state, const string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("X");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Y");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			Math::Rectangle StyleSheet::ReadWidgetDimensions(const tinyxml2::XMLDocument& xmlDocument, const string& widgetName, const string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(type.c_str())->Attribute("MinWidth");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(type.c_str())->Attribute("MinHeight");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			void StyleSheet::TextAlignment(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName, const std::string& type, WidgetData& widgetData)
			{
				if (HasText(xmlDocument, widgetName))
				{
					widgetData.text = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(type.c_str())->Attribute("String");
					std::string alignment = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(type.c_str())->Attribute("Alignment");

					if (alignment == "TopLeft")
						widgetData.textAlignment = WidgetData::TextAlignment::TopLeft;
					else if (alignment == "TopCenter")
						widgetData.textAlignment = WidgetData::TextAlignment::TopCenter;
					else if (alignment == "TopRight")
						widgetData.textAlignment = WidgetData::TextAlignment::TopRight;

					else if (alignment == "MiddleLeft")
						widgetData.textAlignment = WidgetData::TextAlignment::MiddleLeft;
					else if (alignment == "MiddleCenter")
						widgetData.textAlignment = WidgetData::TextAlignment::MiddleCenter;
					else if (alignment == "MiddleRight")
						widgetData.textAlignment = WidgetData::TextAlignment::MiddleRight;

					else if (alignment == "BottomLeft")
						widgetData.textAlignment = WidgetData::TextAlignment::BottomLeft;
					else if (alignment == "BottomCenter")
						widgetData.textAlignment = WidgetData::TextAlignment::BottomCenter;
					else if (alignment == "BottomRight")
						widgetData.textAlignment = WidgetData::TextAlignment::BottomRight;
				}
			}

			bool StyleSheet::DoesStateExist(const tinyxml2::XMLDocument& xmlDocument, const string& widgetName, const string& state)
			{
				return xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(state.c_str()) == NULL ? false : true;
			}

			bool StyleSheet::DoesTypeExist(const tinyxml2::XMLDocument& xmlDocument, const string& widgetName, const string& state, const string& type)
			{
				return xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement(state.c_str())->FirstChildElement(type.c_str()) == NULL ? false : true;
			}

			bool StyleSheet::HasText(const tinyxml2::XMLDocument& xmlDocument, const std::string& widgetName)
			{
				return xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(widgetName.c_str())->FirstChildElement("Text") == NULL ? false : true;
			}

			void StyleSheet::LoadWidget(const tinyxml2::XMLDocument& xmlDocument, const string& widgetName)
			{
				WidgetData widgetData;
				Rectangle rectangle, scissorRectangle;

				widgetData.font = font;

				rectangle = ReadWidgetDimensions(xmlDocument, widgetName, "Dimensions");

				TextAlignment(xmlDocument, widgetName, "Text", widgetData);

				widgetData.minWidth = rectangle.x;
				widgetData.minHeight = rectangle.y;

				if (DoesStateExist(xmlDocument, widgetName, "FirstState"))
				{
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