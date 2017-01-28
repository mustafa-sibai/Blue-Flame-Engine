#include "ImageLoader.h"

namespace BF
{
	namespace IO
	{
		uint8_t* ImageLoader::Load(const std::string& filename, unsigned int* width, unsigned int* height)
		{
			FreeImage_Initialise();

			FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;

			FIBITMAP* dib = nullptr;
			uint8_t* bits = nullptr;
			
			fif = FreeImage_GetFileType(filename.c_str(), 0);

			if (fif == FIF_UNKNOWN)
				fif = FreeImage_GetFIFFromFilename(filename.c_str());

			if (fif == FIF_UNKNOWN)
				std::cout << "FIF_UNKNOWN" << std::endl;

			if (FreeImage_FIFSupportsReading(fif))
				dib = FreeImage_Load(fif, filename.c_str());

			if (!dib)
				std::cout << "file not found" << std::endl;

			if(!FreeImage_FlipVertical(dib))
				std::cout << "failed to flip image" << std::endl;

			FIBITMAP* bitmap = FreeImage_ConvertTo32Bits(dib);

			bits = FreeImage_GetBits(bitmap);
			*width = FreeImage_GetWidth(bitmap);
			*height = FreeImage_GetHeight(bitmap);

			if ((bits == 0) || (*width == 0) || (*height == 0))
				std::cout << "file courrpted" << std::endl;

			if (FreeImage_GetRedMask(bitmap) == 0xff0000)
				SwapRedBlue32(bitmap);

			FreeImage_Unload(dib);
			//FreeImage_Unload(bitmap);
			FreeImage_DeInitialise();
			return bits;
		}
	}
}