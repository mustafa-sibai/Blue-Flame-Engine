#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXTexture2D.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
	#include "BF/Platform/API/OpenGL/GLTexture2D.h"
#endif

#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API Texture2D
			{
				private:
					Context* context;

#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXTexture2D* dxTexture2D;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
					Platform::API::OpenGL::GLTexture2D* glTexture2D;
#endif
				public:
					Texture2D(Context* context);
					~Texture2D();

					void Load(const char* fileName);

					void Bind() const;
					void Unbind() const;
			};
		}
	}
}