#pragma once
#include "DXContext.h"
#include "BF/IO/FileLoader.h"

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
						const DXContext* context;

						ID3D11VertexShader* VS;
						ID3D11PixelShader* PS;
						HRESULT hr;

						char* VSData;
						char* PSData;
						size_t VSsize, PSsize;

					public:
						DXShader(const DXContext* context);
						~DXShader();
					
						void Load(const std::string& vertexShaderFilePath, const std::string& pixelShaderFilePath);
						void Bind() const;
						void CleanUp() const;

						inline const char* GetVSData() const { return VSData; }
						inline const size_t GetVSsize() const { return VSsize; }
				};
			}
		}
	}
}