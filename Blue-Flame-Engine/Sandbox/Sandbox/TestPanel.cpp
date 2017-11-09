#include "TestPanel.h"

using namespace std;
using namespace BF;
using namespace BF::Graphics;
using namespace BF::Graphics::Renderers;
using namespace BF::Graphics::GUI;
using namespace BF::Graphics::API;
using namespace BF::Application;
using namespace BF::Math;

TestPanel::TestPanel(Scene& scene) :
	Panel(scene)
{
	t = new Texture2D();
}

TestPanel::~TestPanel()
{
}

void TestPanel::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
{
	Panel::Initialize(spriteRenderer, zLayer);
}

void TestPanel::Load(const StyleSheet& StyleSheet, const string& widgetName)
{
	Panel::Load(StyleSheet, widgetName);

	SetPosition(Vector2f(900, 200));
	SetContentRectangle(Math::Rectangle(900, 200, 1000, 1000));
	t->Load("Assets/Textures/tilea5.png");
	s = Sprite(t, GetContentRectangle(), 0, Color(1.0f));
}

void TestPanel::Update()
{
	Panel::Update();
	s.SetPosition(GetContentPosition());
}

void TestPanel::Render()
{
	Panel::Render();
	spriteRenderer->Render(s);
}