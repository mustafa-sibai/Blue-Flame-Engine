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

				AddButtonWidget(xmlDocument);
			}

			Math::Rectangle StyleSheet::ReadWidgetData(const tinyxml2::XMLDocument& xmlDocument, const std::string& name, const std::string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("X");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Y");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			void StyleSheet::AddButtonWidget(const tinyxml2::XMLDocument& xmlDocument)
			{
				WidgetData widgetData;
				Rectangle scissorRectangle;

				widgetData.name = "Button";

				scissorRectangle = ReadWidgetData(xmlDocument, "Button", "Normal");
				widgetData.normalSprite = Sprite(texture, Vector3(0.0f), scissorRectangle, Vector4(1.0f));

				scissorRectangle = ReadWidgetData(xmlDocument, "Button", "Hovered");
				widgetData.hoveredSprite = Sprite(texture, Vector3(0.0f), scissorRectangle, Vector4(1.0f));

				scissorRectangle = ReadWidgetData(xmlDocument, "Button", "Pressed");
				widgetData.pressedSprite = Sprite(texture, Vector3(0.0f), scissorRectangle, Vector4(1.0f));

				widgetsData.push_back(widgetData);
			}
		}
	}
}