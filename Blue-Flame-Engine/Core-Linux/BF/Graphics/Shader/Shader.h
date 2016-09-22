#if 0
#pragma once
#include "../Renderer/Renderer.h"
#include "PlatformSpecific/DX11Shader.h"
#include "PlatformSpecific/GLShader.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class DLLEXPORT Shader
		{
			private:
				Renderer &renderer;
				DX11Shader dx11Shader;
				GLShader glShader;

			public:
				Shader(Renderer &renderer);
				~Shader();

				void Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath);
				void Bind();
				void CleanUp();

				inline DX11Shader &GetDX11Shader() { return dx11Shader; }
				inline GLShader &GetGLShader() { return glShader; }
		};
	}
}
#endif