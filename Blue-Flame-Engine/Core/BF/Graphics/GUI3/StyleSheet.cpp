#include "StyleSheet.h"
#include "BF/Engine.h"
#include "BF/IO/ResourceManager.h"
#include "BF/System/Debug.h"

#define WIDGET_ARRAY_LENGTH 1

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;
			using namespace BF::Math;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			StyleSheet::StyleSheet(RenderLayer& GUIRenderLayer) :
				GUIRenderLayer(GUIRenderLayer)
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

				tinyxml2::XMLElement* root = BFE_IS_NULL(xmlDocument.FirstChildElement("GUIStyle"));

				const char* texturefilename = BFE_IS_NULL(root->FirstChildElement("StyleSheet")->Attribute("Path"));
				texture->Create(BF::IO::ResourceManager::Load<TextureData>(texturefilename), Texture::Format::R8G8B8A8);

				string widgetNames[WIDGET_ARRAY_LENGTH] = { "Button"/*, "Checkbox", "Panel", "Scrollbar", "ScrollbarSlider", "MenuStrip", "MenuStrip/MenuItem1", "MenuStrip/MenuItem2", "TabWindow", "TabWindow/Tab" */ };

				for (size_t i = 0; i < WIDGET_ARRAY_LENGTH; i++)
				{
					tinyxml2::XMLElement* widgetNode = GetXMLNode(root, widgetNames[i]);
					LoadWidget(widgetNode, widgetNames[i]);
				}
			}

			Math::Rectangle StyleSheet::ReadWidgetData(tinyxml2::XMLElement* widgetNode, const string& state, const string& type)
			{
				const char* x = BFE_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("X"));
				const char* y = BFE_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Y"));
				const char* width = BFE_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Width"));
				const char* height = BFE_IS_NULL(widgetNode->FirstChildElement(state.c_str())->FirstChildElement(type.c_str())->Attribute("Height"));

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			Math::Rectangle StyleSheet::ReadWidgetDimensions(tinyxml2::XMLElement* widgetNode)
			{
				const char* x = BFE_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("MinWidth"));
				const char* y = BFE_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("MinHeight"));
				const char* charWidth = BFE_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("Width"));
				const char* charHeight = BFE_IS_NULL(widgetNode->FirstChildElement("Dimensions")->Attribute("Height"));

				int width = 0;
				int height = 0;

				if (strcmp(charWidth, "ScreenWidth") == 0)
					width = BF::Engine::GetWindow().GetClientSize().x;
				else
					width = atoi(charWidth);

				if (strcmp(charHeight, "ScreenHeight") == 0)
					height = BF::Engine::GetWindow().GetClientSize().x;
				else
					height = atoi(charHeight);

				return Rectangle(atoi(x), atoi(y), width, height);
			}

			/*void StyleSheet::SetText(tinyxml2::XMLElement* widgetNode, WidgetData& widgetData)
			{
				if (HasText(widgetNode))
				{
					const char* fontfilename = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Font")->Attribute("Path"));
					const char* size = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Font")->Attribute("Size"));

					Font* font = new Font();
					font->Load(fontfilename, atoi(size), FontAtlasFactory::Language::English);

					const char* text = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("String")->Attribute("Value"));
					const char* alignment = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Alignment")->Attribute("Value"));

					const char* r = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("R"));
					const char* g = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("G"));
					const char* b = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("B"));
					const char* a = BFE_IS_NULL(widgetNode->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("A"));

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
			}*/

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

			void StyleSheet::LoadWidget(tinyxml2::XMLElement* widgetNode, const string& widgetName)
			{
				IWidget* widget = new IWidget();
				Rectangle rectangle, scissorRectangle;

				rectangle = ReadWidgetDimensions(widgetNode);
				widget->minSize = Vector2i(rectangle.x, rectangle.y);

				string stateNames[] = { "FirstState", "SecondState" };

				for (size_t i = 0; i < 2; i++)
				{
					if (DoesStateExist(widgetNode, stateNames[i]))
					{
						size_t index = widget->states.size() - 1;
						widget->states.emplace_back(WidgetState
						(
							Sprite(texture, Vector2f(0.5f, 0.5f), Vector2i(rectangle.width, rectangle.height), 0, GUIRenderLayer, ReadWidgetData(widgetNode, stateNames[i], "Normal"), Color(1.0f)),
							Sprite(texture, Vector2f(0.5f, 0.5f), Vector2i(rectangle.width, rectangle.height), 0, GUIRenderLayer, ReadWidgetData(widgetNode, stateNames[i], "Hovered"), Color(1.0f)),
							Sprite(texture, Vector2f(0.5f, 0.5f), Vector2i(rectangle.width, rectangle.height), 0, GUIRenderLayer, ReadWidgetData(widgetNode, stateNames[i], "Pressed"), Color(1.0f)),
							Sprite(texture, Vector2f(0.5f, 0.5f), Vector2i(rectangle.width, rectangle.height), 0, GUIRenderLayer, ReadWidgetData(widgetNode, stateNames[i], "Disabled"), Color(1.0f))
						));
					}
				}

				/*SetText(widgetNode, widgetData);*/
				widgets.insert({ widgetName, widget });
			}

			tinyxml2::XMLElement* StyleSheet::GetXMLNode(tinyxml2::XMLElement* root, const string& widgetName)
			{
				string delim = "/";
				size_t start = 0;
				size_t end = widgetName.find(delim);

				while (end != string::npos)
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