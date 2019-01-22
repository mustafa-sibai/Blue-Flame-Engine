#pragma once
#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BFE_API Resource
		{
			enum class Type { Audio, Texture, XML, Font, Shader, Mesh };

			std::string id;
			std::string filePath;
			Type type;

			Resource(Type type);
			virtual ~Resource();
		};
	}
}