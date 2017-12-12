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

		void ResourceManager::Add(const string& name, Resource* resource)
		{
			resources.insert({ name, resource });
		}

		bool ResourceManager::Exist(const string& name)
		{
			return resources.count(name);
		}

		Resource* ResourceManager::GetResource(const string& name)
		{
			return resources.at(name);
		}
	}
}