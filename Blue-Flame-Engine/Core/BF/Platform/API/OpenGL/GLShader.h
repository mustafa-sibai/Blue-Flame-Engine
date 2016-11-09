#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif

#include <vector>
#include "BF/IO/FileLoader.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLShader
				{
					private:
						GLuint programID;
						GLint result;
						int errorLength;

					private:
						GLuint CompileShader(std::string shaderCode, GLenum shaderType);

					public:
						GLShader();
						~GLShader();

						void Load(const char* vertexShaderFilePath, const char* fragmentShaderFilePath);

						void Bind() const;
						void Unbind() const;

						inline const GLuint& GetProgramID() const { return programID; }
				};
			}
		}
	}
}