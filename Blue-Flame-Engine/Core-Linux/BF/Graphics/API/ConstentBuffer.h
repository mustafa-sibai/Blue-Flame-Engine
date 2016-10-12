#pragma once
#include "Shader.h"
#include "../../Platform/API/DirectX/DXConstentBuffer.h"
#include "../../Platform/API/OpenGL/GLConstentBuffer.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API ConstentBuffer
			{
				private:
					Context *context;
					Shader *shader;
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXConstentBuffer *dxConstentBuffer;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
					Platform::API::OpenGL::GLConstentBuffer *glConstentBuffer;
#endif
				public:
					ConstentBuffer(Context *context, Shader *shader);
					~ConstentBuffer();

					void Create(void *data, unsigned int size, const unsigned int bindingIndex);
					void Update(void *data, unsigned int size);
			};
		}
	}
}