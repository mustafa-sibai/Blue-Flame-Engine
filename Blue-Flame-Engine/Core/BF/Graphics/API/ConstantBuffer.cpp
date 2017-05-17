#include "ConstantBuffer.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			ConstantBuffer::ConstantBuffer()
			{
			}

			ConstantBuffer::~ConstantBuffer()
			{
			}

			void ConstantBuffer::Create(unsigned int size, unsigned int bindingIndex)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstantBuffer.Create(size);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstantBuffer.Create(size, bindingIndex);
#endif
			}

			void ConstantBuffer::Update(void* data, unsigned int size)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstantBuffer.Update(data);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstantBuffer.Update(data, size);
#endif
			}
		}
	}
}