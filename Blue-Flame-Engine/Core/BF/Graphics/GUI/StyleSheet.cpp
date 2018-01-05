#include "StyleSheet.h"
#include "BF/Engine.h"
#include "BF/System/Debug.h"

#define WIDGET_ARRAY_LENGTH 10

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

			StyleSheet::StyleSheet()
			{
				texture = new Texture2D();
			}

			StyleSheet::~StyleSheet()
			{
			}

			void StyleSheet::Load(const string& filename)
			{
				tinyxml2::XMLDocument xmlDocument;
				xmlDocument.LoadFile(filename.c_str());

				tinyxml2::XMLElement* root = BF_IS_NULL(xmlDocument.FirstChildElement("GUIStyle"));

				const char* texturefilename = BF_IS_NULL(root->FirstChildElement("StyleSheet")->Attribute("Path"));
				texture->Load(texturefilename);

				string widgetNames[WIDGET_ARRAY_LENGTH] = { "Button", "Checkbox", "Panel", "Scrollbar", "ScrollbarSlider", "MenuStrip", "MenuStrip/MenuItem1", "MenuStrip/MenuItem2", "TabWindow", "TabWindow/Tab" };

				for (size_t i = 0; i < WIDGET_ARRAY_LENGTH; i++)
				{
					tinyxml2::XMLElement* widgetNode = GetXMLNode(root, widgetNames[i]);
					LoadWidget(widgetNode, widgetNames[i]);
				}
			}

			Math::Rectangle StyleSheet::ReadWidgetData(tinyxml2::XMLElement* widgetNode, const string& state, const string& type)
			{
				const char* x = BF_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("X"));
				const char* y = BF_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Y"));
				const char* width = BF_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Width"));
				const char* height = BF_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Height"));

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			Math::Rectangle StyleSheet::ReadWidgetDimensions(tinyxml2::XMLElement* widgetNode)
			{
				const char* x = BF_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("MinWidth"));
				const char* y = BF_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("MinHeight"));
				const char* char_width = BF_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("Width"));
				const char* char_height = BF_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("Height"));

				unsigned int width = 0;
				unsigned int height = 0;

				if (strcmp(char_width, "ScreenWidth") == 0)
					width = BF::Engine::GetWindow().GetClientWidth();
				else
					width = atoi(char_width);

				if (strcmp(char_height, "ScreenHeight") == 0)
					height = BF::Engine::GetWindow().GetClientHeight();
				else
					height = atoi(char_height);

				return Rectangle(atoi(x), atoi(y), width, height);
			}

			void StyleSheet::SetText(tinyxml2::XMLElement* widgetNode, WidgetData& widgetData)
			{
				if (HasText(widgetNode))
				{
					const char* fontfilename = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Font")->Attribute("Path"));
					const char* size = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Font")->Attribute("Size"));

					Font* font = new Font();
					font->Load(fontfilename, atoi(size), FontAtlasFactory::Language::English);

					const char* text = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("String")->Attribute("Value"));
					const char* alignment = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Alignment")->Attribute("Value"));

					const char* r = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("R"));
					const char* g = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("G"));
					const char* b = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("B"));
					const char* a = BF_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("A"));

					Text::TextAlignment textAlignment;

					if (strcmp(alignment, "TopLeft") == 0)
						textAlignment = Text::TextAlignment::TopLeft;
					else if (strcmp(alignment, "TopCenter") == 0)
						textAlignment = Text::TextAlignment::TopCenter;
					else if (strcmp(alignment, "TopRight") == 0)
						textAlignment = Text::TextAlignment::TopRight;

					else if (strcmp(alignment, "MiddleLeft") == 0)
						textAlignment = Text::TextAlignment::MiddleLeft;
					else if (strcmp(alignment, "MiddleCenter") == 0)
						textAlignment = Text::TextAlignment::MiddleCenter;
					else if (strcmp(alignment, "MiddleRight") == 0)
						textAlignment = Text::TextAlignment::MiddleRight;

					else if (strcmp(alignment, "BottomLeft") == 0)
						textAlignment = Text::TextAlignment::BottomLeft;
					else if (strcmp(alignment, "BottomCenter") == 0)
						textAlignment = Text::TextAlignment::BottomCenter;
					else if (strcmp(alignment, "BottomRight") == 0)
						textAlignment = Text::TextAlignment::BottomRight;

					widgetData.text = Text(font, text, widgetData.sprites[0].GetRectangle(), textAlignment, 0, Color(stof(r), stof(g), stof(b), stof(a)));
					widgetData.hasText = true;
				}
			}

			bool StyleSheet::DoesStateExist(tinyxml2::XMLElement* widgetNode, const string& state)
			{
				return widgetNode->FirstChildElement(state.c_str()) == NULL ? false : true;
			}

			bool StyleSheet::DoesTypeExist(tinyxml2::XMLElement* widgetNode, const string& state, const string& type)
			{
				return widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str()) == NULL ? false : true;
			}

			bool StyleSheet::HasText(tinyxml2::XMLElement* widgetNode)
			{
				return widgetNode->FirstChildElement("Text") == NULL ? false : true;
			}

			void StyleSheet::LoadWidget(tinyxml2::XMLElement* widgetNode, const std::string& widgetName)
			{
				WidgetData widgetData;
				Rectangle rectangle, scissorRectangle;

				rectangle = ReadWidgetDimensions(widgetNode);

				widgetData.minWidth = rectangle.x;
				widgetData.minHeight = rectangle.y;

				if (DoesStateExist(widgetNode, "FirstState"))
				{
					scissorRectangle = ReadWidgetData(widgetNode, "FirstState", "Normal");
					widgetData.sprites[0] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					scissorRectangle = ReadWidgetData(widgetNode, "FirstState", "Hovered");
					widgetData.sprites[1] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					scissorRectangle = ReadWidgetData(widgetNode, "FirstState", "Pressed");
					widgetData.sprites[2] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					if (DoesTypeExist(widgetNode, "FirstState", "Disabled"))
					{
						scissorRectangle = ReadWidgetData(widgetNode, "FirstState", "Disabled");
						widgetData.sprites[3] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));
					}
				}

				if (DoesStateExist(widgetNode, "SecondState"))
				{
					scissorRectangle = ReadWidgetData(widgetNode, "SecondState", "Normal");
					widgetData.sprites[4] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					scissorRectangle = ReadWidgetData(widgetNode, "SecondState", "Hovered");
					widgetData.sprites[5] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					scissorRectangle = ReadWidgetData(widgetNode, "SecondState", "Pressed");
					widgetData.sprites[6] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));

					if (DoesTypeExist(widgetNode, "SecondState", "Disabled"))
					{
						scissorRectangle = ReadWidgetData(widgetNode, "SecondState", "Disabled");
						widgetData.sprites[7] = Sprite(texture, Rectangle(0, 0, rectangle.width, rectangle.height), 0, scissorRectangle, Color(1.0f));
					}
				}

				SetText(widgetNode, widgetData);
				widgetsData.insert({ widgetName, widgetData });
			}

			tinyxml2::XMLElement* StyleSheet::GetXMLNode(tinyxml2::XMLElement* root, const std::string& widgetName)
			{
				std::string delim = "/";
				unsigned int start = 0;
				size_t end = widgetName.find(delim);

				while (end != std::string::npos)
				{
					root = root->FirstChildElement(widgetName.substr(start, end - start).c_str());
					start = end + delim.length();
					end = widgetName.find(delim, start);
				}

				root = root->FirstChildElement(widgetName.substr(start, end - start).c_str());
				return root;
			}
		}
	}
}