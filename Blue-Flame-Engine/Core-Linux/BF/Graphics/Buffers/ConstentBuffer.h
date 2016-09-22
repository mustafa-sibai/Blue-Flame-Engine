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
			class DLLEXPORT ConstentBuffer
			{
				private:
					Renderer &renderer;
					ID3D11Buffer *dx11Buffer;
					GLuint glBuffer;
					HRESULT hr;

				public:
					ConstentBuffer(Renderer &renderer);
					~ConstentBuffer();

					void Create(Shader &shader, void *data, unsigned int size, const unsigned int bindingIndex);
					void Update(void *data, unsigned int size);
					void Bind();
					void Unbind();
			};
		}
	}
}
#endif