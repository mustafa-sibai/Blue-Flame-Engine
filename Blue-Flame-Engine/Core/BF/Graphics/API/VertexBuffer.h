#pragma once
#include "../API/Context.h"
#include "../API/Shader.h"
#include "../../Platform/API/DirectX/DXVertexBuffer.h"
#include "../../Platform/API/OpenGL/GLVertexBuffer.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API VertexBuffer
			{
				private:
					Context *context;

#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXVertexBuffer *dxVertexBuffer;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					Platform::API::OpenGL::GLVertexBuffer *glVertexBuffer;
#endif	
				public:
					VertexBuffer(Context *context, Shader *shader);
					~VertexBuffer();

					void Create(void* data, const unsigned int size);
					void SetLayout(BufferLayout *bufferLayout);
					void Bind();
					void Unbind();
			};
		}
	}
}