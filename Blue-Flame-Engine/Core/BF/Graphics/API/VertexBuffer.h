#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXVertexBuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
	#include "BF/Platform/API/OpenGL/GLVertexBuffer.h"
#endif

#include "BF/Graphics/API/Context.h"
#include "BF/Graphics/API/Shader.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API VertexBuffer
			{
				private:
					const Context* context;

#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXVertexBuffer* dxVertexBuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
					Platform::API::OpenGL::GLVertexBuffer* glVertexBuffer;
#endif	
				public:
					VertexBuffer(const Context* context, const Shader* shader);
					~VertexBuffer();

					void Create(void* data, unsigned int size);
					void SetLayout(VertexBufferLayout* vertexBufferLayout);
					void* Map() const;
					void Unmap() const;
					void Bind() const;
					void Unbind() const;

#ifdef BF_PLATFORM_WINDOWS
					inline Platform::API::DirectX::DXVertexBuffer* GetDXVertexBuffer() const { return dxVertexBuffer; }
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
					inline Platform::API::OpenGL::GLVertexBuffer* GetGLVertexBuffer() const { return glVertexBuffer; }
#endif
			};
		}
	}
}