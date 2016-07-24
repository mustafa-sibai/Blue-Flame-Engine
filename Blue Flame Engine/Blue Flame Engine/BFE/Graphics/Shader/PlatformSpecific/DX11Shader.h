#pragma once
#include "../../Renderer/PlatformSpecific/DX11Renderer.h"
#include "../../../IO/FileReader.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class DLLEXPORT DX11Shader
		{
			private:
				HRESULT hr;

				char* VSData, *PSData;
				size_t VSsize, PSsize;

				ID3D11VertexShader *VS;
				ID3D11PixelShader *PS;
				
				DX11Renderer &dx11Renderer;

			public:
				DX11Shader(DX11Renderer &dx11Renderer);
				~DX11Shader();

				void Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath);
				void Bind();
				void CleanUp();

				inline char* &GetVSData() { return VSData; }
				inline size_t &GetVSsize() { return VSsize; }
		};
	}
}