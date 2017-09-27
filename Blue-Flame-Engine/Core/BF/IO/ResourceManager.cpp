#include "ResourceManager.h"

namespace BF
{
	namespace IO
	{
		using namespace std;

		unordered_map<string, Resource*> ResourceManager::resources;

		ResourceManager::ResourceManager()
		{
		}

		ResourceManager::~ResourceManager()
		{
		}

		void ResourceManager::Add(string name, Resource* resource)
		{
			resources.insert({ name, resource });
		}

		bool ResourceManager::Exist(string name)
		{
			return resources.count(name);
		}

		Resource* ResourceManager::GetResource(string name)
		{
			return resources.at(name);
		}
	}
}