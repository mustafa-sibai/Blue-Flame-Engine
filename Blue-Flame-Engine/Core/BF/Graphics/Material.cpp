#include "Material.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Graphics::API;

		Material::Material(const Shader& shader)
		{
			diffuseMap = new Texture2D(shader);
			specularMap = new Texture2D(shader);
		}

		Material::~Material()
		{
		}

		void Material::Bind()
		{
			diffuseMap->Bind("diffuseMap", 0);
			specularMap->Bind("specularMap", 1);
		}

		void Material::Unbind()
		{
			diffuseMap->Unbind();
			specularMap->Unbind();
		}
	}
}