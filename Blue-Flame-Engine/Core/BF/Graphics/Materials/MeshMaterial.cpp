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
				materialConstantBuffer.Create(sizeof(colorBuffer), 2);
			}

			void MeshMaterial::Bind()
			{
				shader->Bind();
				materialConstantBuffer.Update(&colorBuffer, sizeof(colorBuffer));
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