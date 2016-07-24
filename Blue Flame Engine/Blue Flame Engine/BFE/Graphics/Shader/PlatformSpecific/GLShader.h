#pragma once
#include <GLEW/GL/glew.h>
#include <vector>
#include "../../../IO/FileReader.h"
#include "../../../Math/Math.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class DLLEXPORT GLShader
		{
			private:
				GLint result;
				int errorLength;
				GLuint programID;

			private:
				GLuint CompileShader(std::string shaderCode, GLenum shaderType);

			public:
				GLShader();
				~GLShader();

				void Load(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);

				void Bind();
				void Unbind();

				inline GLuint &GetProgramID() { return programID; }
		};
	}
}