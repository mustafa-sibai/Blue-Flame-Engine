#include "SceneLoader.h"
#include "BF/Graphics/GUI/Button.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Application;
		using namespace BF::Graphics::Renderers;
		using namespace BF::Graphics;
		using namespace BF::Graphics::GUI;

		SceneLoader::SceneLoader()
		{
		}

		SceneLoader::~SceneLoader()
		{
		}

		Scene* SceneLoader::Load(const string& filename)
		{
			tinyxml2::XMLDocument xmlDocument;
			xmlDocument.LoadFile(filename.c_str());

			tinyxml2::XMLElement* root = BF_IS_NULL(xmlDocument.FirstChildElement("Scene"));

			Scene* scene = new Scene();
			scene->Initialize();
			scene->Load();

			for (tinyxml2::XMLElement* e = root->FirstChildElement("GameNode"); e != NULL; e = e->NextSiblingElement("GameNode"))
			{
				const char* nodeName	= BF_IS_NULL(e->Attribute("Name"));
				const char* nodeType	= BF_IS_NULL(e->Attribute("Type"));

				if (strcmp(nodeType, "RegularPolygon") == 0)
				{
					const char* x		= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("X"));
					const char* y		= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("Y"));
					const char* width	= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("Width"));
					const char* height	= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("Height"));

					const char* zLayer	= BF_IS_NULL(e->FirstChildElement("zLayer")->Attribute("Value"));
					const char* r		= BF_IS_NULL(e->FirstChildElement("Color")->Attribute("R"));
					const char* g		= BF_IS_NULL(e->FirstChildElement("Color")->Attribute("G"));
					const char* b		= BF_IS_NULL(e->FirstChildElement("Color")->Attribute("B"));
					const char* a		= BF_IS_NULL(e->FirstChildElement("Color")->Attribute("A"));
					
					scene->instantiate(nodeName, new RegularPolygon(Rectangle(atoi(x), atoi(y), atoi(width), atoi(height)), atoi(zLayer), Color(stof(r), stof(g), stof(b), stof(a))));
				}
				else if (strcmp(nodeType, "Button") == 0)
				{
					const char* x			= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("X"));
					const char* y			= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("Y"));
					const char* width		= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("Width"));
					const char* height		= BF_IS_NULL(e->FirstChildElement("Rectangle")->Attribute("Height"));

					const char* text		= BF_IS_NULL(e->FirstChildElement("Text")->FirstChildElement("String")->Attribute("Value"));
					const char* alignment	= BF_IS_NULL(e->FirstChildElement("Text")->FirstChildElement("Alignment")->Attribute("Value"));

					const char* r			= BF_IS_NULL(e->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("R"));
					const char* g			= BF_IS_NULL(e->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("G"));
					const char* b			= BF_IS_NULL(e->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("B"));
					const char* a			= BF_IS_NULL(e->FirstChildElement("Text")->FirstChildElement("Color")->Attribute("A"));

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

					Button* button = (Button*)scene->instantiate(nodeName, new Button());

					button->SetRectangle(Rectangle(atoi(x), atoi(y), atoi(width), atoi(height)));
					button->GetText().SetText(text);
					button->GetText().SetTextAlignment(textAlignment);
					button->GetText().color = Color(stof(r), stof(g), stof(b), stof(a));
				}
			}

			return scene;
		}
	}
}