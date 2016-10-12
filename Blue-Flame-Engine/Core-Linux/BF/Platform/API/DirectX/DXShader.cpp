#ifdef BF_PLATFORM_WINDOWS
#include "DXShader.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				DXShader::DXShader(DXContext *context) :
					context(context), VS(nullptr), PS(nullptr), hr(0), VSData(nullptr), PSData(nullptr), VSsize(0), PSsize(0)
				{
				}

				DXShader::~DXShader()
				{
				}

				void DXShader::Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath)
				{
					VSData = IO::FileReader::ReadBinaryFile(vertexShaderFilePath, &VSsize);
					PSData = IO::FileReader::ReadBinaryFile(pixelShaderFilePath, &PSsize);
					
					if (FAILED(hr = context->GetDevice()->CreateVertexShader(VSData, VSsize, 0, &VS)))
					{
						std::cout << hr << std::endl;
					}

					if (FAILED(hr = context->GetDevice()->CreatePixelShader(PSData, PSsize, 0, &PS)))
					{
						std::cout << hr << std::endl;
					}
				}

				void DXShader::Bind()
				{
					context->GetContext()->VSSetShader(VS, 0, 0);
					context->GetContext()->PSSetShader(PS, 0, 0);
				}

				void DXShader::CleanUp()
				{
					VS->Release();
					PS->Release();
				}
			}
		}
	}
}
#endif