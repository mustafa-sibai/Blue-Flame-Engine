#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXVertexBuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLVertexBuffer.h"
#endif

#include "BF/Graphics/API/Shader.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API VertexBuffer
			{
				private:
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXVertexBuffer dxVertexBuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
					Platform::API::OpenGL::GLVertexBuffer glVertexBuffer;
#endif	
				public:
					VertexBuffer();
					~VertexBuffer();

					void Create(void* data, unsigned int size);
					void SetLayout(const Shader& shader, const VertexBufferLayout& vertexBufferLayout);
					void* Map() const;
					void Unmap() const;
					void Bind() const;
					void Unbind() const;
			};
		}
	}
}