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
	t = new Texture2D(spriteRenderer->GetShader());
}

TestPanel::~TestPanel()
{
}

void TestPanel::Initialize(SpriteRenderer& spriteRenderer)
{
	Panel::Initialize(spriteRenderer);
}

void TestPanel::Load(const StyleSheet& StyleSheet, const string& widgetName)
{
	Panel::Load(StyleSheet, widgetName);

	t->Load("Assets/Textures/tilea5.png");
	SetPosition(Vector2(200, 200));
	s = Sprite(t, Math::Rectangle(Panel::GetPosition().x, Panel::GetPosition().y, 800, 600), 0, Color(1.0f));
}

void TestPanel::Update()
{
	Panel::Update();
}

void TestPanel::Render()
{
	Panel::Render();
	spriteRenderer->Render(s);
}