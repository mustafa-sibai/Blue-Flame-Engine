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

			void ConstantBuffer::Create(unsigned int bindingIndex, unsigned int size, const void* data)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstantBuffer.Create(size);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstantBuffer.Create(bindingIndex, size, data);
#endif
			}

			void ConstantBuffer::Update(unsigned int offset, unsigned int size, void* data)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxConstantBuffer.Update(data);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glConstantBuffer.Update(offset, size, data);
#endif
			}
		}
	}
}