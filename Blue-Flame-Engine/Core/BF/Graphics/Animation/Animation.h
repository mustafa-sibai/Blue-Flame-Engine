#pragma once
#include "BF/Graphics/Animation/Sequence.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class AnimationSystem;

			class BFE_API Animation
			{
				friend class BF::Graphics::Animation::AnimationSystem;

			private:
				Sequence* sequence;
				BF::Graphics::API::Texture2D* texture;

				bool play;
				float timer;
				int currentKeyFrameIndex;
				bool renderFrame;

			public:
				enum class State { None, Started, Ended };
				State state;
				bool loop;

			public:
				Animation(BF::Graphics::API::Texture2D* texture, Sequence* sequence, bool loop);
				~Animation();

				void Play();
				void Pause();
			};
		}
	}
}