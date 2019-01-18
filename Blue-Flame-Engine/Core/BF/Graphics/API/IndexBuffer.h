#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXIndexBuffer.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLIndexBuffer.h"
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BFE_API IndexBuffer
			{
				private:
#ifdef BFE_PLATFORM_WINDOWS
					Platform::API::DirectX::DXIndexBuffer dxIndexBuffer;
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
					Platform::API::OpenGL::GLIndexBuffer glIndexBuffer;
#endif	
				public:
					IndexBuffer();
					~IndexBuffer();

					void Create(const unsigned int* indices, unsigned int count);

					void Bind() const;
					void Unbind() const;
					unsigned int GetIndicesCount() const;
			};
		}
	}
}