#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXIndexBuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLIndexBuffer.h"
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API IndexBuffer
			{
				private:
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXIndexBuffer dxIndexBuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
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