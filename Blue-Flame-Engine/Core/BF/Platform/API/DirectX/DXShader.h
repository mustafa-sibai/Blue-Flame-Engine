#pragma once
#include "DXContext.h"
#include "BF/IO/FileReader.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BF_API DXShader
				{
					private:
						DXContext* context;

						ID3D11VertexShader* VS;
						ID3D11PixelShader* PS;
						HRESULT hr;

						char* VSData;
						char* PSData;
						size_t VSsize, PSsize;

					public:
						DXShader(DXContext* context);
						~DXShader();
					
						void Load(const char* vertexShaderFilePath, const char* pixelShaderFilePath);
						void Bind();
						void CleanUp();

						inline const char* GetVSData() const { return VSData; }
						inline const size_t& GetVSsize() const { return VSsize; }
				};
			}
		}
	}
}