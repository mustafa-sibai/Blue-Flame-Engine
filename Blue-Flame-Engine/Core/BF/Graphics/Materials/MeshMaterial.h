#pragma once
#include "BF/Graphics/Color.h"
#include "BF/Graphics/API/Texture2D.h"
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
					BF::Graphics::API::Texture2D diffuseMap;
					BF::Graphics::API::Texture2D specularMap;
					BF::Graphics::API::Texture2D normalMap;

					bool diffuseMapActive;
					bool specularMapActive;
					bool normalMapActive;

				public:
					struct ColorBuffer
					{
						Color ambientColor;
						Color diffuseColor;
						Color specularColor;

						float shininess = 0.0f;
					};

					ColorBuffer colorBuffer;
					BF::Graphics::API::Shader* shader;

				public:
					MeshMaterial();
					~MeshMaterial();

					void Initialize();
					void Bind();
					void Unbind();

					void SetDiffuseMap(const BF::Graphics::API::Texture2D& diffuseMap);
					void SetSpecularMap(const BF::Graphics::API::Texture2D& specularMap);
					void SetNormalMap(const BF::Graphics::API::Texture2D& normalMap);
			};
		}
	}
}