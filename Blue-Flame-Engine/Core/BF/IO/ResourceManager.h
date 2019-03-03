#pragma once
#include <unordered_map>
#include "BF/Graphics/Mesh.h"
#include "BF/IO/BFXLoader.h"
#include "BF/IO/ImageLoader.h"
#include "BF/Graphics/Materials/MaterialManager.h"
#include "Resource.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API ResourceManager
		{
		private:
			static std::unordered_map<std::string, Resource*> resources;

		public:
			ResourceManager();
			~ResourceManager();

			template <typename T>
			static T* Load(const std::string& filename);

			template<>
			static BF::Graphics::MeshData* Load<BF::Graphics::MeshData>(const std::string& filename);

			template<>
			static BF::Graphics::API::TextureData* Load<BF::Graphics::API::TextureData>(const std::string& filename);

			static void Add(const std::string& name, Resource* resource);
			static bool Exist(const std::string& name);
			static Resource* GetResource(const std::string& name);
		};

		/*template<typename T>
		inline T* ResourceManager::Load(const std::string& filename)
		{
			BFE_LOG_ERROR("U", "");
		}*/

		template<>
		inline BF::Graphics::MeshData* ResourceManager::Load(const std::string& filename)
		{
			if (Exist(filename))
			{
				return (BF::Graphics::MeshData*)GetResource(filename);
			}
			else
			{
				BF::Graphics::MeshData* meshData = BF::IO::BFXLoader::Load(filename);
				Add(filename, meshData);
				return meshData;
			}
		}

		template<>
		inline BF::Graphics::API::TextureData* ResourceManager::Load(const std::string& filename)
		{
			if (Exist(filename))
			{
				return (BF::Graphics::API::TextureData*)GetResource(filename);
			}
			else
			{
				BF::Graphics::API::TextureData* textureData = BF::IO::ImageLoader::Load(filename);
				textureData->filePath = filename;
				Add(filename, textureData);
				return textureData;
			}
		}
	}
}