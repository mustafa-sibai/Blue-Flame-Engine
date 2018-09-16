#pragma once
#include "BF/Graphics/Color.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			class BF_API MeshMaterial
			{
				private:
					struct ColorBuffer
					{
						Color ambientColor;
						Color diffuseColor;
						Color specularColor;

						float shininess = 0.0f;
					};

				public:
					ColorBuffer colorBuffer;
					BF::Graphics::API::Shader shader;
					BF::Graphics::API::ConstantBuffer materialConstantBuffer;
					BF::Graphics::API::Texture2D diffuseMap;
					BF::Graphics::API::Texture2D specularMap;
					BF::Graphics::API::Texture2D normalMap;

					MeshMaterial();
					~MeshMaterial();

					void Initialize();
					void Bind();
					void Unbind();
			};
		}
	}
}