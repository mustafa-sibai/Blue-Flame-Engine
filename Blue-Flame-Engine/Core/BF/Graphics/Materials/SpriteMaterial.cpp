#include "BF/Graphics/Materials/SpriteMaterial.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics::API;

			SpriteMaterial::SpriteMaterial()
			{
			}

			SpriteMaterial::~SpriteMaterial()
			{
			}

			void SpriteMaterial::Bind(const Shader& shader)
			{
				diffuseMap.Bind(shader, "diffuseMap", 1);
				specularMap.Bind(shader, "specularMap", 2);
				normalMap.Bind(shader, "normalMap", 3);
			}

			void SpriteMaterial::Unbind()
			{
				diffuseMap.Unbind();
				specularMap.Unbind();
				normalMap.Unbind();
			}
		}
	}
}