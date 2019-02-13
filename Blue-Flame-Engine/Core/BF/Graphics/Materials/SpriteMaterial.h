#pragma once
#include "BF/Graphics/Color.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			class BFE_API SpriteMaterial
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
					BF::Graphics::API::Texture2D diffuseMap;
					BF::Graphics::API::Texture2D specularMap;
					BF::Graphics::API::Texture2D normalMap;

					SpriteMaterial();
					~SpriteMaterial();

					void Bind(const BF::Graphics::API::Shader& shader);
					void Unbind();
			};
		}
	}
}