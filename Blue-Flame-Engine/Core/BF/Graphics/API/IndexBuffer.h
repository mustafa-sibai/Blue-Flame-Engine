#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXIndexBuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
	#include "BF/Platform/API/OpenGL/GLIndexBuffer.h"
#endif

#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API IndexBuffer
			{
				private:
					Context* context;

#ifdef BF_PLATFORM_WINDOWS
				Platform::API::DirectX::DXIndexBuffer* dxIndexBuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				Platform::API::OpenGL::GLIndexBuffer* glIndexBuffer;
#endif	
				public:
					IndexBuffer(Context* context);
					~IndexBuffer();

					void Create(const unsigned int* const indices, unsigned int count);

					void Bind() const;
					void Unbind() const;
					unsigned int GetIndicesCount() const;
			};
		}
	}
}