#pragma once
#include "Color.h"
#include "API/Texture2D.h"
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

				Material(const API::Shader& shader);
				~Material();

				void Bind();
				void Unbind();
		};
	}
}