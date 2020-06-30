#pragma once
#include "BF/Graphics/API/BufferMode.h"
#include "BF/Graphics/API/Shader.h"

#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXVertexBuffer.h"
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/GLVertexBuffer.h"
#endif

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

				void Create();
				void Allocate(unsigned int size, const void* data, BF::Graphics::API::BufferMode mode);

				void SetLayout(const Shader& shader, const VertexBufferLayout* vertexBufferLayout);

				void* Map() const;
				void Unmap() const;

				void* MapPersistentStream() const;
				void UnmapPersistentStream() const;

				void Bind() const;
				void Unbind() const;
			};
		}
	}
}