#if 0
#pragma once
#include "../Renderer/Renderer.h"
#include "../Shader/Shader.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		namespace Buffers
		{
			class DLLEXPORT VertexBuffer
			{
				private:
					Renderer &renderer;
					ID3D11Buffer *dx11Buffer;
					GLuint glBuffer;
					HRESULT hr;

				public:
					VertexBuffer(Renderer &renderer);
					~VertexBuffer();

					void Create(void* data, const unsigned int size);
					void Bind();
					void Unbind();

					inline ID3D11Buffer* GetDX11Buffer() const { return dx11Buffer; }
					inline ID3D11Buffer* const* GetConstDX11Buffer() const { return &dx11Buffer; }
					inline GLuint &GetGLBuffer() { return glBuffer; }
			};
		}
	}
}
#endif