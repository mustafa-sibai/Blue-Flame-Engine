#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	//#include "BF/Platform/API/DirectX/DXTexture2D.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLTextureCube.h"
#endif

#include <string>
#include <vector>
#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/API/Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BFE_API TextureCube : public Texture
			{
			private:
				const Shader& shader;
				std::vector<TextureData*> textureCubes;

#ifdef BFE_PLATFORM_WINDOWS
				//Platform::API::DirectX::GLTextureCube dxTexture2D;
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				Platform::API::OpenGL::GLTextureCube glTextureCube;
#endif
			public:
				TextureCube(const Shader& shader);
				~TextureCube();

				void Load(const std::vector<std::string>& filenames);
				void Load(const std::vector<std::string>& filenames, Wrap wrap, Filter filter);

				void Bind() const;
				void Unbind() const;
			};
		}
	}
}