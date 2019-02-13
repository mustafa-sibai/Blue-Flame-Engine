#include "MeshMaterial.h"
#include "BF/Graphics/Mesh.h"
#include "BF/Graphics/ConstantBufferManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics;
			using namespace BF::Graphics::API;

			MeshMaterial::MeshMaterial()
			{
			}

			MeshMaterial::~MeshMaterial()
			{
			}

			void MeshMaterial::Bind(ConstantBufferManager& constantBufferManager)
			{
				shader->Bind();

				constantBufferManager.UpdateMaterialIndex(index);

				if (colorBuffer.diffuseMapActive)
					diffuseMap.Bind(*shader, "diffuseMap", 1);

				if (colorBuffer.specularMapActive)
					specularMap.Bind(*shader, "specularMap", 2);

				if (colorBuffer.normalMapActive)
					normalMap.Bind(*shader, "normalMap", 3);
			}

			void MeshMaterial::Unbind()
			{
				if (colorBuffer.diffuseMapActive)
					diffuseMap.Unbind();

				if (colorBuffer.specularMapActive)
					specularMap.Unbind();

				if (colorBuffer.normalMapActive)
					normalMap.Unbind();

				shader->Unbind();
			}

			void MeshMaterial::SetDiffuseMap(const Texture2D& diffuseMap)
			{
				this->diffuseMap = diffuseMap;
				colorBuffer.diffuseMapActive = true;
			}

			void MeshMaterial::SetSpecularMap(const Texture2D& specularMap)
			{
				this->specularMap = specularMap;
				colorBuffer.specularMapActive = true;
			}

			void MeshMaterial::SetNormalMap(const Texture2D& normalMap)
			{
				this->normalMap = normalMap;
				colorBuffer.normalMapActive = true;
			}
		}
	}
}