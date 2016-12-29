#pragma once
#include <vector>
#include "BF/Math/Math.h"
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			struct KeyFrame
			{
				float time;
				Math::Rectangle scissorRectangle;

				KeyFrame() = default;
				KeyFrame(float time, const Math::Rectangle& scissorRectangle) :
					time(time), scissorRectangle(scissorRectangle)
				{
				}
			};

			struct Sequence
			{
				std::vector<KeyFrame> keyFrames;
			};

			struct SpriteAnimationData
			{
				std::string textureName;
				std::vector<Sequence> sequences;
			};

			class BF_API SpriteAnimation
			{
			private:
				SpriteAnimationData* data;
				Renderers::SpriteRenderer& spriteRenderer;
				API::Shader& shader;
				API::Texture2D texture;
				Renderers::Sprite sprite;

				System::Timer timer;
				int keyFrameIndex = 0;

			public:
				SpriteAnimation(Renderers::SpriteRenderer& spriteRenderer, API::Shader& shader);
				~SpriteAnimation();

				void Initialize();
				void Load(const std::string& filename);
				void Update();
				void Render();
			};
		}
	}
}