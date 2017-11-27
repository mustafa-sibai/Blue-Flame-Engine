#include "GLShader.h"
#include "BF/Platform/API/OpenGL/GLError.h"
#include "BF/Graphics/API/Shader.h"

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
				using namespace BF::Graphics::API;

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
						BF_LOG_ERROR("Compile Error: " + std::string(&shaderErrorMessage[0]));
					}

					return shaderID;
				}

				void GLShader::CreateProgram(GLuint& compiledVertexShader, GLuint& compiledPixelShader)
				{
					GLCall(programID = glCreateProgram());

					GLCall(glAttachShader(programID, compiledVertexShader));
					GLCall(glAttachShader(programID, compiledPixelShader));
					GLCall(glLinkProgram(programID));

					GLCall(glGetProgramiv(programID, GL_LINK_STATUS, &result));
					GLCall(glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &errorLength));
					if (errorLength > 0)
					{
						vector<char> ProgramErrorMessage(errorLength + 1);
						GLCall(glGetProgramInfoLog(programID, errorLength, NULL, &ProgramErrorMessage[0]));
						BF_LOG_ERROR("Link Error: " + std::string(&ProgramErrorMessage[0]));
					}

					GLCall(glDetachShader(programID, compiledVertexShader));
					GLCall(glDetachShader(programID, compiledPixelShader));
					GLCall(glDeleteShader(compiledVertexShader));
					GLCall(glDeleteShader(compiledPixelShader));
				}

				void GLShader::LoadStandardShader(ShaderType type)
				{
					string vertexShader, pixelShader;

					switch (type)
					{
					case ShaderType::SingleLight3D:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/SingleLight3DShader.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/SingleLight3DShader.vpshader"
#endif
							break;
						}
						case ShaderType::P:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/P.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::PUV:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/PUV.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::PN:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/PN.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::PUVN:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/PUVN.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::PUVNTB:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/PUVNTB.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::_3D:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-Core4.5/P.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
#include "BF/Graphics/API/StandardShaders/3D/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::_3DMipAF:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "BF/Graphics/API/StandardShaders/3DMipAF/GLSL-Core4.5/Shader.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Graphics/API/StandardShaders/3DMipAF/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::Light:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "BF/Graphics/API/StandardShaders/Light/GLSL-Core4.5/Shader.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Graphics/API/StandardShaders/Light/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::SpriteRenderer:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "BF/Graphics/API/StandardShaders/SpriteRenderer/GLSL-Core4.5/Shader.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Graphics/API/StandardShaders/SpriteRenderer/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						case ShaderType::TextureCube:
						{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "BF/Graphics/API/StandardShaders/TextureCube/GLSL-Core4.5/Shader.vpshader"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "BF/Graphics/API/StandardShaders/TextureCube/GLSL-ES3.0/Shader.vpshader"
#endif
							break;
						}
						default:
						{
							break;
						}
					}

					GLuint compiledVertexShader = CompileShader(vertexShader, GL_VERTEX_SHADER);
					GLuint compiledPixelShader = CompileShader(pixelShader, GL_FRAGMENT_SHADER);

					CreateProgram(compiledVertexShader, compiledPixelShader);
				}

				void GLShader::LoadFromFile(const string& vertexShaderFilePath, const string& pixelShaderFilePath)
				{
					GLuint compiledVertexShader = CompileShader(FileLoader::LoadTextFile(vertexShaderFilePath), GL_VERTEX_SHADER);
					GLuint compiledPixelShader = CompileShader(FileLoader::LoadTextFile(pixelShaderFilePath), GL_FRAGMENT_SHADER);

					CreateProgram(compiledVertexShader, compiledPixelShader);
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