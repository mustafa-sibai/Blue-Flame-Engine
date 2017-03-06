#include "Material.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Graphics::API;

		Material::Material(const Shader& shader) :
			diffuseMap(shader), specularMap(shader)
		{
		}

		Material::~Material()
		{
		}

		void Material::Bind()
		{
			diffuseMap.Bind("diffuseMap", 1);
			specularMap.Bind("specularMap", 2);
		}

		void Material::Unbind()
		{
			diffuseMap.Unbind();
			specularMap.Unbind();
		}
	}
}