#include "GUISystem.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Graphics/GUI3/Button.h"
#include "BF/Graphics/GUI3/CheckBox.h"
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
				/*for (size_t i = 0; i < widgets.size(); i++)
				{
					Vector2f mousePosition = Mouse::GetPosition();
					Vector3f spritePosition = widgets[i]->currentSprite->gameObject->GetTransform()->GetPosition();
					Vector2i spriteSize = widgets[i]->currentSprite->size;

					Vector3f worldMousePosition = Camera::ScreenToWorldPoint(Vector3f(mousePosition.x, mousePosition.y, 0), Vector2f(0.5f, 0.5f));

					Rectangle spriteRectangle = Rectangle(spritePosition.x, spritePosition.y, spriteSize.x, spriteSize.y, widgets[i]->currentSprite->pivot);
					Rectangle mouseRect = Rectangle(worldMousePosition.x, worldMousePosition.y, 1, 1);

					if (widgets[i]->type == IWidget::Type::Button)
					{
						if (spriteRectangle.Intersect(mouseRect))
						{
							if (Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
							{
								*widgets[i]->currentSprite = widgets[i]->states[0].pressed;
								widgets[i]->internalState = Button::InternalState::Pressed;
								((Button*)widgets[i])->state = Button::State::Pressed;
							}
							else if (Mouse::IsButtonUp(Mouse::Button::Code::Left))
							{
								widgets[i]->internalState = Button::InternalState::Released;
								((Button*)widgets[i])->state = Button::State::Released;
							}
							else
							{
								*widgets[i]->currentSprite = widgets[i]->states[0].hovered;
								widgets[i]->internalState = Button::InternalState::Hovered;
								((Button*)widgets[i])->state = Button::State::Hovered;
							}
						}
						else
						{
							*widgets[i]->currentSprite = widgets[i]->states[0].normal;
							widgets[i]->internalState = Button::InternalState::Normal;
							((Button*)widgets[i])->state = Button::State::Normal;
						}
					}
					else if (widgets[i]->type == IWidget::Type::Checkbox)
					{
						if (spriteRectangle.Intersect(mouseRect))
						{
							if (Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
							{
								if (widgets[i]->currentState == 0)
									*widgets[i]->currentSprite = widgets[i]->states[0].pressed;
								else if (widgets[i]->currentState == 1)
									*widgets[i]->currentSprite = widgets[i]->states[1].pressed;

								widgets[i]->internalState = Checkbox::InternalState::Pressed;
							}
							else if (Mouse::IsButtonUp(Mouse::Button::Code::Left))
							{
								if (widgets[i]->currentState == 0)
								{
									*widgets[i]->currentSprite = widgets[i]->states[1].pressed;
									((Checkbox*)widgets[i])->state = Checkbox::State::Checked;

									widgets[i]->currentState = 1;
								}
								else if (widgets[i]->currentState == 1)
								{
									*widgets[i]->currentSprite = widgets[i]->states[0].pressed;
									((Checkbox*)widgets[i])->state = Checkbox::State::Unchecked;

									widgets[i]->currentState = 0;
								}

								widgets[i]->internalState = Checkbox::InternalState::Released;
							}
							else
							{
								if (widgets[i]->currentState == 0)
									*widgets[i]->currentSprite = widgets[i]->states[0].hovered;
								else if (widgets[i]->currentState == 1)
									*widgets[i]->currentSprite = widgets[i]->states[1].hovered;

								widgets[i]->internalState = Checkbox::InternalState::Hovered;
							}
						}
						else
						{
							if (widgets[i]->currentState == 0)
								*widgets[i]->currentSprite = widgets[i]->states[0].normal;
							else if (widgets[i]->currentState == 1)
								*widgets[i]->currentSprite = widgets[i]->states[1].normal;

							widgets[i]->internalState = Checkbox::InternalState::Normal;
						}
					}
				}*/
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
				else if (iWidget->type == IWidget::Type::Checkbox)
				{
					*iWidget = styleSheet.GetWidget("Checkbox");
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