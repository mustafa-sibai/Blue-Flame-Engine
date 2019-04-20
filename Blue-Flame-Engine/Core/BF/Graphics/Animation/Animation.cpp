#include "Animation.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			using namespace BF::Graphics::API;

			Animation::Animation(Texture2D* texture, Sequence* sequence, bool loop) :
				texture(texture), sequence(sequence), play(false), state(State::None), loop(loop), timer(0), currentKeyFrameIndex(0), renderFrame(true)
			{
			}

			Animation::~Animation()
			{
			}

			void Animation::Play()
			{
				play = true;
			}

			void Animation::Pause()
			{
				play = false;
			}
		}
	}
}