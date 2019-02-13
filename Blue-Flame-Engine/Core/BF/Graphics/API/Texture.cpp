#include "Texture.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Texture::Texture() :
				textureData(nullptr), format(Format::R8G8B8A8), wrap(Wrap::Repeat), filter(Filter::Point)
			{
			}

			Texture::~Texture()
			{
			}

			/*void Texture::Load(const string& filename)
			{
				if (ResourceManager::Exist(filename))
					textureData = (TextureData*)ResourceManager::GetResource(filename);
				else
				{
					textureData = ImageLoader::Load(filename);
					textureData->filePath = filename;
					ResourceManager::Add(filename, textureData);
				}
			}*/
		}
	}
}