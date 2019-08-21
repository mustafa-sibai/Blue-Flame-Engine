#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXConstantBuffer.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLConstantBuffer.h"
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BFE_API ConstantBuffer
			{
			private:
#ifdef BFE_PLATFORM_WINDOWS
				BF::Platform::API::DirectX::DXConstantBuffer dxConstantBuffer;
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				BF::Platform::API::OpenGL::GLConstantBuffer glConstantBuffer;
#endif
			public:
				ConstantBuffer();
				~ConstantBuffer();

				void Create(unsigned int bindingIndex, unsigned int size, const void* data);
				void Update(unsigned int offset, unsigned int size, const void* data);
			};
		}
	}
}