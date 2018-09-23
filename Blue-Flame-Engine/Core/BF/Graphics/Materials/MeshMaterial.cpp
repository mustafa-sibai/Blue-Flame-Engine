#include "BF/Graphics/Materials/MeshMaterial.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics::API;

			MeshMaterial::MeshMaterial()
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
				diffuseMap.Bind(*shader, "diffuseMap", 1);
				specularMap.Bind(*shader, "specularMap", 2);
				normalMap.Bind(*shader, "normalMap", 3);
			}

			void MeshMaterial::Unbind()
			{
				diffuseMap.Unbind();
				specularMap.Unbind();
				normalMap.Unbind();
				shader->Unbind();
			}
		}
	}
}