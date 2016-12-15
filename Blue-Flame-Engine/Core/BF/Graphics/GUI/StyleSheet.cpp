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

				AddButtonComponent(xmlDocument);
			}

			Math::Rectangle StyleSheet::ReadComponent(const tinyxml2::XMLDocument& xmlDocument, const std::string& name, const std::string& type)
			{
				const char* x = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("X");
				const char* y = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Y");
				const char* width = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Width");
				const char* height = xmlDocument.FirstChildElement(styleSheetNode.c_str())->FirstChildElement(name.c_str())->FirstChildElement(type.c_str())->Attribute("Height");

				return Rectangle(atoi(x), atoi(y), atoi(width), atoi(height));
			}

			void StyleSheet::AddButtonComponent(const tinyxml2::XMLDocument& xmlDocument)
			{
				Component component;
				Rectangle scissorRectangle;

				component.name = "Button";

				scissorRectangle = ReadComponent(xmlDocument, "Button", "Hovered");
				component.hoveredSprite = Sprite(texture, Vector3(0.0f), scissorRectangle, Vector4(1.0f));

				scissorRectangle = ReadComponent(xmlDocument, "Button", "Pressed");
				component.pressedSprite = Sprite(texture, Vector3(0.0f), scissorRectangle, Vector4(1.0f));

				scissorRectangle = ReadComponent(xmlDocument, "Button", "Released");
				component.releasedSprite = Sprite(texture, Vector3(0.0f), scissorRectangle, Vector4(1.0f));

				GUIComponents.push_back(component);
			}
		}
	}
}