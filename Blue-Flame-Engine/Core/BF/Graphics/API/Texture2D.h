#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXTexture2D.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
	#include "BF/Platform/API/OpenGL/GLTexture2D.h"
#endif

#include "Context.h"
#include "Shader.h"
#include "BF/IO/ImageLoader.h"


namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API Texture2D
			{
				private:
					Shader* shader;
					Context* context;

#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXTexture2D* dxTexture2D;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
					Platform::API::OpenGL::GLTexture2D* glTexture2D;
#endif
					uint8_t* data;
					unsigned int width, height;

				public:
					Texture2D(Context* context, Shader* shader);
					~Texture2D();

					void Load(const char* fileName);
					void Bind() const;
					void Bind(const char* samplerName, unsigned int index) const;
					void Unbind() const;

					inline const uint8_t* GetData() const { return data; }
					inline const unsigned int& GetWidth() const { return width; }
					inline const unsigned int& GetHeight() const { return height; }
			};
		}
	}
}