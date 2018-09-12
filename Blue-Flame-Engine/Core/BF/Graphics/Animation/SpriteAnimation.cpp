#include "SpriteAnimation.h"
#include "BF/IO/BFALoader.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			using namespace std;
			using namespace BF::IO;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Math;

			SpriteAnimation::SpriteAnimation(SpriteRenderer& spriteRenderer) :
				spriteRenderer(spriteRenderer)
			{
			}

			SpriteAnimation::~SpriteAnimation()
			{
			}

			void SpriteAnimation::Initialize()
			{
			}

			void SpriteAnimation::Load(const string& filename)
			{
				data = BFALoader::Load(filename);
				texture.Load(data->textureName);

				//sprite = Sprite(&texture, Rectangle(0, 350, 32 * 10, 48 * 10), 0, data->sequences[0].keyFrames[0].scissorRectangle, Color(1.0f));
				timer.Reset();
			}

			void SpriteAnimation::Update()
			{
				if (timer.GetElapsedTimeInMilliseconds() >= data->sequences[0].keyFrames[keyFrameIndex].time)
				{
					keyFrameIndex++;
					if (keyFrameIndex >= data->sequences[0].keyFrames.size())
						keyFrameIndex = 0;

					//sprite.SetScissorRectangle(data->sequences[0].keyFrames[keyFrameIndex].scissorRectangle);
					timer.Reset();
				}
			}

			void SpriteAnimation::Render()
			{
				//spriteRenderer.Render(sprite);
			}
		}
	}
}