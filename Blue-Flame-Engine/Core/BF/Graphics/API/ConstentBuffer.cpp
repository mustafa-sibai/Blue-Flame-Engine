#include "ConstentBuffer.h"
#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			ConstentBuffer::ConstentBuffer()
			{
			}

			ConstentBuffer::~ConstentBuffer()
			{
			}

			void ConstentBuffer::Create(unsigned int size, unsigned int bindingIndex)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstentBuffer.Create(size);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstentBuffer.Create(size, bindingIndex);
#endif
			}

			void ConstentBuffer::Update(void* data, unsigned int size)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstentBuffer.Update(data);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstentBuffer.Update(data, size);
#endif
			}
		}
	}
}