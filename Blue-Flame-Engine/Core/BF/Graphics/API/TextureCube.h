#pragma once
#ifdef BF_PLATFORM_WINDOWS
	//#include "BF/Platform/API/DirectX/DXTexture2D.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLTextureCube.h"
#endif

#include <string>
#include <vector>
#include "Shader.h"
#include "Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API TextureCube : public Texture
			{
			private:
				const Shader& shader;
				std::vector<TextureData> textureCubes;

#ifdef BF_PLATFORM_WINDOWS
				//Platform::API::DirectX::GLTextureCube dxTexture2D;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				Platform::API::OpenGL::GLTextureCube glTextureCube;
#endif
			public:
				TextureCube(const Shader& shader);
				~TextureCube();

				void Load(const std::vector<std::string>& fileNames);
				void Load(const std::vector<std::string>& fileNames, Wrap wrap, Filter filter);

				void Bind() const;
				void Unbind() const;
			};
		}
	}
}