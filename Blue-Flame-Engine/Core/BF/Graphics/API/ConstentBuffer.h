#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXConstentBuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLConstentBuffer.h"
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API ConstentBuffer
			{
				private:
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXConstentBuffer dxConstentBuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
					Platform::API::OpenGL::GLConstentBuffer glConstentBuffer;
#endif
				public:
					ConstentBuffer();
					~ConstentBuffer();

					void Create(unsigned int size, unsigned int bindingIndex);
					void Update(void* data, unsigned int size);
			};
		}
	}
}