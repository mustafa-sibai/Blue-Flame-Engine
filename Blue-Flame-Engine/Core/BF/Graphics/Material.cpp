#include "Material.h"

namespace BF
{
	namespace Graphics
	{
		Material::Material(std::string diffuseMapName, Math::Vector4 diffuseColor) :
			diffuseMapName(diffuseMapName), diffuseColor(diffuseColor)
		{
		}

		Material::~Material()
		{
		}
	}
}