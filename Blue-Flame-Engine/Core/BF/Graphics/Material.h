#pragma once
#include "BF/Graphics/Color.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Material
		{
			private:
				struct ColorBuffer
				{
					Color ambientColor;
					Color diffuseColor;
					Color specularColor;

					float shininess;
				};

			public:
				ColorBuffer colorBuffer;
				API::Texture2D diffuseMap;
				API::Texture2D specularMap;
				API::Texture2D normalMap;

				Material();
				~Material();

				void Bind(const API::Shader& shader);
				void Unbind();
		};
	}
}