#include "Material.h"

namespace BF
{
	namespace Graphics
	{
		Material::Material(const API::Shader& shader) :
			shader(shader), constentBuffer()
		{
			constentBuffer.Create(sizeof(MaterialBuffer), 1);
		}

		Material::~Material()
		{
		}
	}
}