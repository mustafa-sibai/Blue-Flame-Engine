#pragma once
#ifdef BF_PLATFORM_WINDOWS
//#include "BF/Platform/API/DirectX/DXVertexBuffer.h"
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
#include "BF/Platform/API/OpenGL/GLVertexArray.h"
#endif

#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Graphics/API/Shader.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API VertexArray
			{
			private:
				Context* context;

#ifdef BF_PLATFORM_WINDOWS
				//Platform::API::DirectX::DXVertexBuffer* dxVertexBuffer;
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				Platform::API::OpenGL::GLVertexArray* glVertexArray;
#endif	
			public:
				VertexArray(Context* context, Shader* shader);
				~VertexArray();

				void Create();
				void Push(VertexBuffer* vertexBuffer);
				void SetVertexBufferLayout(Graphics::API::VertexBufferLayout* vertexBufferLayout);
				void Bind() const;
				void Unbind() const;
			};
		}
	}
}