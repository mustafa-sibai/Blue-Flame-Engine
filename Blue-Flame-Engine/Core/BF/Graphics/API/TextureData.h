#pragma once
#include "BF/IO/Resource.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			struct BFE_API TextureData : public BF::IO::Resource
			{
				int width;
				int height;
				uint8_t* buffer;
				void* freeImage_bitmap;

				TextureData() :
					width(0), height(0), buffer(nullptr), freeImage_bitmap(nullptr), Resource(BF::IO::Resource::Type::Texture)
				{
				}

				TextureData(int width, int height, uint8_t* buffer) :
					width(width), height(height), buffer(buffer), freeImage_bitmap(nullptr), Resource(BF::IO::Resource::Type::Texture)
				{
				}
			};
		}
	}
}