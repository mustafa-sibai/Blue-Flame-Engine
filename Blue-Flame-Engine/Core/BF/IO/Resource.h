#pragma once
#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API Resource
		{
			enum class Type { Audio, Texture, XML, Font, Shader, Model };

			std::string id;
			std::string filePath;
			Type type;

			Resource(Type type);
			~Resource();
		};
	}
}