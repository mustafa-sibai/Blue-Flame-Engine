#pragma once
#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/API/ConstentBuffer.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct MaterialBuffer
		{
			Math::Vector3 ambientColor;
			Math::Vector3 diffuseColor;
			Math::Vector3 specularColor;
		};

		class BF_API Material
		{
		private:
			const API::Shader& shader;
			API::ConstentBuffer constentBuffer;

			public:
				Material(const API::Shader& shader);
				~Material();
		};
	}
}