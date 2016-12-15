#include "DXShader.h"
#include "BF/IO/FileLoader.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				using namespace std;
				using namespace BF::IO;

				DXShader::DXShader() :
					VS(nullptr), PS(nullptr), hr(0), VSData(nullptr), PSData(nullptr), VSsize(0), PSsize(0)
				{
				}

				DXShader::~DXShader()
				{
				}

				void DXShader::Load(const string& vertexShaderFilePath, const string& pixelShaderFilePath)
				{
					VSData = FileLoader::LoadBinaryFile(vertexShaderFilePath, &VSsize);
					PSData = FileLoader::LoadBinaryFile(pixelShaderFilePath, &PSsize);
					
					if (FAILED(hr = Engine::GetContext().GetDXContext().GetDevice()->CreateVertexShader(VSData, VSsize, 0, &VS)))
						std::cout << hr << std::endl;

					if (FAILED(hr = Engine::GetContext().GetDXContext().GetDevice()->CreatePixelShader(PSData, PSsize, 0, &PS)))
						std::cout << hr << std::endl;
				}

				void DXShader::Bind() const
				{
					Engine::GetContext().GetDXContext().GetContext()->VSSetShader(VS, 0, 0);
					Engine::GetContext().GetDXContext().GetContext()->PSSetShader(PS, 0, 0);
				}

				void DXShader::CleanUp() const
				{
					VS->Release();
					PS->Release();
				}
			}
		}
	}
}