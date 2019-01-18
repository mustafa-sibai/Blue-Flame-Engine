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
			class BFE_API MeshMaterial
			{
				friend class MaterialManager;

				private:
					int index;
					BF::Graphics::API::Texture2D diffuseMap;
					BF::Graphics::API::Texture2D specularMap;
					BF::Graphics::API::Texture2D normalMap;

				public:
					struct ColorBuffer
					{
						Color ambientColor;
						Color diffuseColor;
						Color specularColor;

						float shininess = 0.0f;

						int diffuseMapActive = 0;
						int specularMapActive = 0;
						int normalMapActive = 0;
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