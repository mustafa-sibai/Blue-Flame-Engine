#pragma once
#include <iostream>
#include <BF/IO/FileFormats/BFAFormat.h>
#include <BF/Graphics/Animation/SpriteAnimation.h>

namespace Editor
{
	namespace IO
	{
		class BFAWriter
		{
			private:
				BF::IO::FileFormats::BFAFormat bfaFormat;

			public:
				BFAWriter();
				~BFAWriter();

				void WriteToFile(const std::string& filename, const BF::Graphics::Animation::SpriteAnimationData& spriteAnimationData);
		};
	}
}