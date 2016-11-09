#include "GLShader.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace std;
				using namespace BF::IO;

				GLShader::GLShader() :
					programID(0), result(GL_FALSE), errorLength(0)
				{
				}

				GLShader::~GLShader()
				{
				}

				GLuint GLShader::CompileShader(std::string shaderCode, GLenum shaderType)
				{
					GLuint shaderID = glCreateShader(shaderType);

					const char* cShaderCode = shaderCode.c_str();

					glShaderSource(shaderID, 1, &cShaderCode, 0);
					glCompileShader(shaderID);

					glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
					glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &errorLength);
					if (errorLength > 0)
					{
						vector<char> shaderErrorMessage(errorLength + 1);
						glGetShaderInfoLog(shaderID, errorLength, NULL, &shaderErrorMessage[0]);
						printf("Compile Error: %s\n", &shaderErrorMessage[0]);
					}

					return shaderID;
				}

				void GLShader::Load(const char* vertexShaderFilePath, const char* fragmentShaderFilePath)
				{
					GLuint vertexShader = CompileShader(FileLoader::LoadTextFile(vertexShaderFilePath), GL_VERTEX_SHADER);
					GLuint fragmentShader = CompileShader(FileLoader::LoadTextFile(fragmentShaderFilePath), GL_FRAGMENT_SHADER);

					programID = glCreateProgram();

					glAttachShader(programID, vertexShader);
					glAttachShader(programID, fragmentShader);
					glLinkProgram(programID);

					glGetProgramiv(programID, GL_LINK_STATUS, &result);
					glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &errorLength);
					if (errorLength > 0)
					{
						vector<char> ProgramErrorMessage(errorLength + 1);
						glGetProgramInfoLog(programID, errorLength, NULL, &ProgramErrorMessage[0]);
						printf("Link Error: %s\n", &ProgramErrorMessage[0]);
					}

					glDetachShader(programID, vertexShader);
					glDetachShader(programID, fragmentShader);
					glDeleteShader(vertexShader);
					glDeleteShader(fragmentShader);
				}

				void GLShader::Bind() const
				{
					glUseProgram(programID);
				}

				void GLShader::Unbind() const
				{
					glUseProgram(0);
				}
			}
		}
	}
}