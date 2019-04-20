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
			using namespace BF::Input;

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
						Vector2f mousePosition = Mouse::GetPosition();
						Vector3f spritePosition = widgets[i]->currentSprite->gameObject->GetTransform()->GetPosition();
						Vector2i spriteSize = widgets[i]->currentSprite->size;

						Vector3f worldMousePosition = Camera::ScreenToWorldPoint(Vector3f(mousePosition.x, mousePosition.y, 0), Vector2f(0.5f, 0.5f));

						Rectangle spriteRectangle = Rectangle(spritePosition.x, spritePosition.y, spriteSize.x, spriteSize.y, widgets[i]->currentSprite->pivot);
						Rectangle mouseRect = Rectangle(worldMousePosition.x, worldMousePosition.y, 1, 1);
												
						if (spriteRectangle.Intersect(mouseRect))
						{
							//Pressed
							if (Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
							{
								*widgets[i]->currentSprite = widgets[i]->states[0].pressed;
								((Button*)widgets[i])->state = Button::State::Pressed;
							}
							else
							{
								//Hovered
								*widgets[i]->currentSprite = widgets[i]->states[0].hovered;
								((Button*)widgets[i])->state = Button::State::Hovered;
							}
							if (Mouse::IsButtonUp(Mouse::Button::Code::Left))
							{
								((Button*)widgets[i])->state = Button::State::Released;
							}
						}
						else
						{
							//Normal
							*widgets[i]->currentSprite = widgets[i]->states[0].normal;
							((Button*)widgets[i])->state = Button::State::None;
						}
					}
				}
			}

			void GUISystem::Render()
			{
			}

			void GUISystem::AddWidget(IWidget* iWidget)
			{
				if (iWidget->type == IWidget::Type::Button)
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