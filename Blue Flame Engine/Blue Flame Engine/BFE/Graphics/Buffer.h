#pragma once
#include "Renderer/Renderer.h"
#include "Shader/Shader.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class DLLEXPORT Buffer
		{
			private:
				Renderer &renderer;
				ID3D11Buffer *dx11Buffer;
				GLuint glBuffer;

			public:
				Buffer(Renderer &renderer);
				~Buffer();

				void CreateVertexBuffer(void* data, const unsigned int size);
				void CreateConstentBuffer(Shader &shader, void *data, const unsigned int size, const char* bufferNameInShader, const unsigned int bindingIndex);
				void UpdateConstentBuffer(void* data);

				inline ID3D11Buffer* GetDX11Buffer() const { return dx11Buffer; }
				inline ID3D11Buffer* const* GetConstDX11Buffer() const { return &dx11Buffer; }
				inline GLuint &GetGLBuffer() { return glBuffer; }
		};
	}
}