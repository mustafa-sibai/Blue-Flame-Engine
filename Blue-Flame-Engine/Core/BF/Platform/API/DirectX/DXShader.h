#pragma once
#include <d3d11.h>
#include <string>
#include "BF/Common.h"

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
						ID3D11VertexShader* VS;
						ID3D11PixelShader* PS;

						char* VSData;
						char* PSData;
						size_t VSsize, PSsize;

					public:
						DXShader();
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