#pragma once
#include <unordered_map>
#include "Resource.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API ResourceManager
		{
		private:
			static std::unordered_map<std::string, Resource*> resources;

		public:
			ResourceManager();
			~ResourceManager();

			static void Add(const std::string& name, Resource* resource);
			static bool Exist(const std::string& name);
			static Resource* GetResource(const std::string& name);
		};
	}
}