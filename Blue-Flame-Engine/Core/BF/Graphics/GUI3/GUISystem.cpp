#include "GUISystem.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/GUI3/Button.h"
#include "BF/Input/Mouse.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::ECS;
			using namespace BF::Math;

			GUISystem::GUISystem(BF::Graphics::Renderers::RenderPipeline& renderPipeline) :
				renderPipeline(renderPipeline), styleSheet(*renderPipeline.spriteRenderer->renderLayerManager.GetGUIRenderLayer())
			{
			}

			GUISystem::~GUISystem()
			{
			}

			void GUISystem::Initialize()
			{
			}

			void GUISystem::Load()
			{
				styleSheet.Load("../Sandbox/Assets/GUI/StyleSheet.xml");
			}

			void GUISystem::PostLoad()
			{
			}

			void GUISystem::Update(double deltaTime)
			{
				for (size_t i = 0; i < widgets.size(); i++)
				{
					if (widgets[i]->IsSameType<Button>())
					{
						BF::Math::Vector2f mousePosition = BF::Input::Mouse::GetPosition();
						BF::Math::Vector3f spritePosition = widgets[i]->currentSprite->gameObject->GetTransform()->GetPosition();
						BF::Math::Vector2i spriteSize = widgets[i]->currentSprite->size;

						BF::Math::Vector3f newPos = Camera::ScreenToWorldPoint(Vector3f(mousePosition.x, mousePosition.y, 0), Vector2f(0.5f, 0.5f));

						BF::Math::Rectangle rect = BF::Math::Rectangle(spritePosition.x, spritePosition.y, spriteSize.x, spriteSize.y, widgets[i]->currentSprite->pivot);
						BF::Math::Rectangle mouseRect = BF::Math::Rectangle(newPos.x, newPos.y, 1, 1);
												
						//Change button sprites
						if (rect.Intersect(mouseRect))
						{
							//Pressed
							if (BF::Input::Mouse::IsButtonPressed(BF::Input::Mouse::Button::Code::Left))
							{
								//BF::System::Debug::Log("Pressed", BF::System::Debug::LogLevel::Info);
								widgets[i]->currentSprite = &widgets[i]->states[0].pressed;
							}
							else
							{
								//Hovered
								//BF::System::Debug::Log("Hovering", BF::System::Debug::LogLevel::Info);
								widgets[i]->currentSprite = &widgets[i]->states[0].hovered;
							}
						}
						else
						{
							//Normal
							//BF::System::Debug::Log("Normal", BF::System::Debug::LogLevel::Info);
							widgets[i]->currentSprite = &widgets[i]->states[0].normal;
						}
						//widgets[i] is a button. cast it to a button pointer ((Button*)widgets[i]) and now you can
						//access the button class and do whatever
						//check if button is clicked or hovered or released
						//You can get mouse stuff by doing
						//BF::Input::Mouse:: etc......
					}
				}
			}

			void GUISystem::Render()
			{
			}

			void GUISystem::AddWidget(IWidget* iWidget)
			{
				if (iWidget->IsSameType<Button>())
				{
					*iWidget = styleSheet.GetWidget("Button");
				}

				renderPipeline.AddRenderable((IComponent*)iWidget->currentSprite);
				widgets.emplace_back(iWidget);
			}

			void GUISystem::RemoveWidget(IWidget* iWidget)
			{
			}
		}
	}
}