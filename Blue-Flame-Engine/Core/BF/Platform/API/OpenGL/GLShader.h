#pragma once
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
#include <GLES3/gl3.h>
#endif

#include <vector>
#include "../../../IO/FileReader.h"
#include "../../../Math/Math.h"

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
	}
}