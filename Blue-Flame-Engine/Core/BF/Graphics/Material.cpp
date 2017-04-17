#include "BF/Graphics/Material.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Graphics::API;

		Material::Material(const Shader& shader) :
			diffuseMap(shader), specularMap(shader), normalMap(shader)
		{
		}

		Material::~Material()
		{
		}

		void Material::Bind()
		{
			diffuseMap.Bind("diffuseMap", 1);
			specularMap.Bind("specularMap", 2);
			normalMap.Bind("normalMap", 3);
		}

		void Material::Unbind()
		{
			diffuseMap.Unbind();
			specularMap.Unbind();
			normalMap.Unbind();
		}
	}
}