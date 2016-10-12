#pragma once
#include "Context.h"
#include "../../Platform/API/DirectX/DXIndexBuffer.h"
#include "../../Platform/API/OpenGL/GLIndexBuffer.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API IndexBuffer
			{
				private:
					Context *context;

#ifdef BF_PLATFORM_WINDOWS
				Platform::API::DirectX::DXIndexBuffer *dxIndexBuffer;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				Platform::API::OpenGL::GLIndexBuffer *glIndexBuffer;
#endif	
				public:
					IndexBuffer(Context *context);
					~IndexBuffer();
					void Create(const unsigned int* const indices, const unsigned int count);

					const void Bind() const;
					const void Unbind() const;
					const unsigned int GetIndicesCount() const;
			};
		}
	}
}