#include "BF/Graphics/Material.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Graphics::API;

		Material::Material()
		{
		}

		Material::~Material()
		{
		}

		void Material::Bind(const Shader& shader)
		{
			diffuseMap.Bind(shader, "diffuseMap", 1);
			specularMap.Bind(shader, "specularMap", 2);
			normalMap.Bind(shader, "normalMap", 3);
		}

		void Material::Unbind()
		{
			diffuseMap.Unbind();
			specularMap.Unbind();
			normalMap.Unbind();
		}
	}
}