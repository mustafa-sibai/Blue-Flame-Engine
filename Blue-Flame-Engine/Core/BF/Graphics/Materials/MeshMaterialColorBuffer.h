#pragma once
#include "BF/Graphics/Color.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			struct MeshMaterialColorBuffer
			{
				Color ambientColor;
				Color diffuseColor;
				Color specularColor;

				float shininess = 0.0f;

				int diffuseMapActive = 0;
				int specularMapActive = 0;
				int normalMapActive = 0;

				MeshMaterialColorBuffer() :
					ambientColor(0), diffuseColor(0), specularColor(0), shininess(0),
					diffuseMapActive(0), specularMapActive(0), normalMapActive(0)
				{
				}
			};
		}
	}
}