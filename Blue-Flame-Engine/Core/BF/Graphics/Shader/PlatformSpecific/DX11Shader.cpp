#if 0
#include "DX11Shader.h"

namespace BFE
{
	namespace Graphics
	{
		DX11Shader::DX11Shader(DX11Renderer &dx11Renderer) :
			dx11Renderer(dx11Renderer), VSData(nullptr), PSData(nullptr), VS(nullptr), PS(nullptr), VSsize(0), PSsize(0)
		{
		}

		DX11Shader::~DX11Shader()
		{
		}

		void BFE::Graphics::DX11Shader::Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath)
		{
			VSData = IO::FileReader::ReadBinaryFile(vertexShaderFilePath, VSsize);
			PSData = IO::FileReader::ReadBinaryFile(pixelShaderFilePath, PSsize);
			
			if (FAILED(hr = dx11Renderer.GetDevice().CreateVertexShader(VSData, VSsize, 0, &VS)))
			{
				std::cout << hr << std::endl;
			}

			if (FAILED(hr = dx11Renderer.GetDevice().CreatePixelShader(PSData, PSsize, 0, &PS)))
			{
				std::cout << hr << std::endl;
			}
		}

		void DX11Shader::Bind()
		{
			dx11Renderer.GetContext().VSSetShader(VS, 0, 0);
			dx11Renderer.GetContext().PSSetShader(PS, 0, 0);
		}

		void BFE::Graphics::DX11Shader::CleanUp()
		{
			VS->Release();
			PS->Release();
		}
	}
}
#endif