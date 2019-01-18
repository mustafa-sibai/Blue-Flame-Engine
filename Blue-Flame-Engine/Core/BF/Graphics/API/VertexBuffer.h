#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXVertexBuffer.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
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
			class BFE_API VertexBuffer
			{
				private:
#ifdef BFE_PLATFORM_WINDOWS
					BF::Platform::API::DirectX::DXVertexBuffer dxVertexBuffer;
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
					BF::Platform::API::OpenGL::GLVertexBuffer glVertexBuffer;
#endif	
				public:
					VertexBuffer();
					~VertexBuffer();

					void Create(unsigned int size, void* data);
					void SetLayout(const Shader& shader, const VertexBufferLayout* vertexBufferLayout);
					
					void* Map() const;
					void Unmap() const;
					
					void Bind() const;
					void Unbind() const;
			};
		}
	}
}