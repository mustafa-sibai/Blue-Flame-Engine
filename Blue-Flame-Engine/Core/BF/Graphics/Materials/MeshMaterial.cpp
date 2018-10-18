#include "BF/Graphics/Materials/MeshMaterial.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics::API;

			MeshMaterial::MeshMaterial() :
				diffuseMapActive(false), specularMapActive(false), normalMapActive(false)
			{
			}

			MeshMaterial::~MeshMaterial()
			{
			}

			void MeshMaterial::Initialize()
			{
			}

			void MeshMaterial::Bind()
			{
				shader->Bind();

				if (diffuseMapActive)
					diffuseMap.Bind(*shader, "diffuseMap", 1);

				if (specularMapActive)
					specularMap.Bind(*shader, "specularMap", 2);

				if (normalMapActive)
					normalMap.Bind(*shader, "normalMap", 3);
			}

			void MeshMaterial::Unbind()
			{
				if (diffuseMapActive)
					diffuseMap.Unbind();

				if (specularMapActive)
					specularMap.Unbind();

				if (normalMapActive)
					normalMap.Unbind();

				shader->Unbind();
			}

			void MeshMaterial::SetDiffuseMap(const Texture2D& diffuseMap)
			{
				this->diffuseMap = diffuseMap;
				diffuseMapActive = true;
			}

			void MeshMaterial::SetSpecularMap(const Texture2D& specularMap)
			{
				this->specularMap = specularMap;
				specularMapActive = true;
			}

			void MeshMaterial::SetNormalMap(const Texture2D& normalMap)
			{
				this->normalMap = normalMap;
				normalMapActive = true;
			}
		}
	}
}