#include "GLShader.h"
#include "GLError.h"

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

				GLuint GLShader::CompileShader(const string& shaderCode, GLenum shaderType)
				{
					GLuint shaderID = 0;
					GLCall(shaderID = glCreateShader(shaderType));

					const char* cShaderCode = shaderCode.c_str();

					GLCall(glShaderSource(shaderID, 1, &cShaderCode, 0));
					GLCall(glCompileShader(shaderID));

					GLCall(glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result));
					GLCall(glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &errorLength));
					if (errorLength > 0)
					{
						vector<char> shaderErrorMessage(errorLength + 1);
						GLCall(glGetShaderInfoLog(shaderID, errorLength, NULL, &shaderErrorMessage[0]));
						BF_LOG_ERROR("Compile Error: %s", &shaderErrorMessage[0]);
					}

					return shaderID;
				}

				void GLShader::Load(const string& vertexShaderFilePath, const string& pixelShaderFilePath)
				{
					GLuint vertexShader = CompileShader(FileLoader::LoadTextFile(vertexShaderFilePath), GL_VERTEX_SHADER);
					GLuint pixelShader = CompileShader(FileLoader::LoadTextFile(pixelShaderFilePath), GL_FRAGMENT_SHADER);

					GLCall(programID = glCreateProgram());

					GLCall(glAttachShader(programID, vertexShader));
					GLCall(glAttachShader(programID, pixelShader));
					GLCall(glLinkProgram(programID));

					GLCall(glGetProgramiv(programID, GL_LINK_STATUS, &result));
					GLCall(glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &errorLength));
					if (errorLength > 0)
					{
						vector<char> ProgramErrorMessage(errorLength + 1);
						GLCall(glGetProgramInfoLog(programID, errorLength, NULL, &ProgramErrorMessage[0]));
						BF_LOG_ERROR("Link Error: %s", &ProgramErrorMessage[0]);
					}

					GLCall(glDetachShader(programID, vertexShader));
					GLCall(glDetachShader(programID, pixelShader));
					GLCall(glDeleteShader(vertexShader));
					GLCall(glDeleteShader(pixelShader));
				}

				void GLShader::Bind() const
				{
					GLCall(glUseProgram(programID));
				}

				void GLShader::Unbind() const
				{
					GLCall(glUseProgram(0));
				}
			}
		}
	}
}