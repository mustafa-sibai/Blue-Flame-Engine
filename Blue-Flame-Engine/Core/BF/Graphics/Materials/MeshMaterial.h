#pragma once
#include "BF/Graphics/Color.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/Materials/Material.h"
#include "BF/Graphics/ConstantBufferManager.h"
#include "BF/Graphics/Materials/MeshMaterialColorBuffer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class Mesh;

		namespace Materials
		{
			class BFE_API MeshMaterial : public Material
			{
				friend class MaterialManager;
				friend class ConstantBufferManager;

				private:
					std::vector<BF::Graphics::Mesh*> meshesUsingCurrentMaterial;
					BF::Graphics::API::Texture2D diffuseMap;
					BF::Graphics::API::Texture2D specularMap;
					BF::Graphics::API::Texture2D normalMap;

				public:
					MeshMaterialColorBuffer colorBuffer;
					BF::Graphics::API::Shader* shader;

				public:
					MeshMaterial();
					MeshMaterial(BF::Graphics::API::Shader* shader, MeshMaterialColorBuffer& colorBuffer);
					~MeshMaterial();

					void Bind(ConstantBufferManager& constantBufferManager);
					void Unbind();

					void SetDiffuseMap(const BF::Graphics::API::Texture2D& diffuseMap);
					void SetSpecularMap(const BF::Graphics::API::Texture2D& specularMap);
					void SetNormalMap(const BF::Graphics::API::Texture2D& normalMap);
			};
		}
	}
}