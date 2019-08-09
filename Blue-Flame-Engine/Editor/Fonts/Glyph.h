#pragma once
#include "BF/Math/Math.h"

namespace Editor
{
	namespace Fonts
	{
		struct Glyph
		{
			unsigned int unicode;
			unsigned int width, height;
			unsigned int bufferSize;
			uint8_t* buffer;

			BF::Math::Vector2i bearing;
			BF::Math::Vector2i advance;

			Glyph() = default;
			Glyph(int unicode, int width, int height, const BF::Math::Vector2i& bearing, const BF::Math::Vector2i& advance, uint8_t* data) :
				unicode(unicode), width(width), height(height), bearing(bearing), advance(advance)
			{
				bufferSize = width * height;
				buffer = new uint8_t[bufferSize];
				memcpy(buffer, data, sizeof(uint8_t) * bufferSize);
			}
		};
	}
}