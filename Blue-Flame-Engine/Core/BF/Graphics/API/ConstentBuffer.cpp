#include "ConstentBuffer.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			ConstentBuffer::ConstentBuffer(Context *context, Shader *shader) :
				context(context), shader(shader)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstentBuffer = new BF::Platform::API::DirectX::DXConstentBuffer(context->GetDXContext(), shader->GetDXShader());
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstentBuffer = new BF::Platform::API::OpenGL::GLConstentBuffer();
#endif
			}

			ConstentBuffer::~ConstentBuffer()
			{
			}

			void ConstentBuffer::Create(void *data, unsigned int size, const unsigned int bindingIndex)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstentBuffer->Create(data, size);
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstentBuffer->Create(data, size, bindingIndex);
#endif
			}

			void ConstentBuffer::Update(void *data, const unsigned int size)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstentBuffer->Update(data);
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstentBuffer->Update(data, size);
#endif
			}
		}
	}
}