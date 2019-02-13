#pragma once
#include <vector>
#include "BF/IO/FileLoader.h"
#include "BF/Platform/API/OpenGL/GLCommon.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class ShaderType;
		}
	}

	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BFE_API GLShader
				{
					private:
						GLuint programID;
						GLint result;
						int errorLength;

					public:
						GLShader();
						~GLShader();

						void LoadStandardShader(Graphics::API::ShaderType type);
						void LoadFromFile(const std::string& vertexShaderFilePath, const std::string& pixelShaderFilePath);

						void Bind() const;
						void Unbind() const;

						inline const GLuint& GetProgramID() const { return programID; }

					private:
						GLuint CompileShader(const std::string& shaderCode, GLenum shaderType);
						void CreateProgram(GLuint& compiledVertexShader, GLuint& compiledPixelShader);
				};
			}
		}
	}
}