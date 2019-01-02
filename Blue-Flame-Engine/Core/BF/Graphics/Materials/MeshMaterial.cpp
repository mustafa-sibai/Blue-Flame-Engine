#include "BF/Graphics/Materials/MeshMaterial.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics::API;

			MeshMaterial::MeshMaterial() :
				index(0)
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