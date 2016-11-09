#include "ImageLoader.h"

namespace BF
{
	namespace IO
	{
		uint8_t* ImageLoader::Load(const char* filename, unsigned int* width, unsigned int* height)
		{
			FreeImage_Initialise();

			FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

			FIBITMAP* dib = nullptr;
			uint8_t* bits = nullptr;
			
			fif = FreeImage_GetFileType(filename, 0);

			if (fif == FIF_UNKNOWN)
				fif = FreeImage_GetFIFFromFilename(filename);

			if (fif == FIF_UNKNOWN)
				std::cout << "FIF_UNKNOWN" << std::endl;

			if (FreeImage_FIFSupportsReading(fif))
				dib = FreeImage_Load(fif, filename);

			if (!dib)
				std::cout << "file not found" << std::endl;

			FIBITMAP* bitmap = FreeImage_ConvertTo32Bits(dib);
			FreeImage_Unload(dib);

			bits = FreeImage_GetBits(bitmap);
			*width = FreeImage_GetWidth(bitmap);
			*height = FreeImage_GetHeight(bitmap);

			if ((bits == 0) || (*width == 0) || (*height == 0))
				std::cout << "file courrpted" << std::endl;

			if (FreeImage_GetRedMask(bitmap) == 0xff0000)
				SwapRedBlue32(bitmap);

			FreeImage_DeInitialise();
			
			return bits;
		}
	}
}