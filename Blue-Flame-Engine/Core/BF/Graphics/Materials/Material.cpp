#include "Material.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			int Material::globalID = 0;

			Material::Material() :
				id(0), index(0)
			{
				Material::globalID++;
				id = globalID;
			}

			Material::~Material()
			{
			}
		}
	}
}