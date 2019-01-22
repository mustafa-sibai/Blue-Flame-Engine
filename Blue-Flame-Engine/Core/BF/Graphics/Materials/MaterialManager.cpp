#include "MaterialManager.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics::API;

			MeshMaterial MaterialManager::materials[BFE_MATERIAL_ARRAY_COUNT];

			MaterialManager::MaterialManager() :
				latestIndex(1)
			{
			}

			MaterialManager::~MaterialManager()
			{
			}

			void MaterialManager::Initialize()
			{
				constantBuffer.Create(1, sizeof(MeshMaterial::ColorBuffer) * BFE_MATERIAL_ARRAY_COUNT, nullptr);
				materials[0].index = 0;
				materials[0].shader = new Shader();
				materials[0].shader->LoadStandardShader(ShaderType::P);
				materials[0].colorBuffer.ambientColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
				materials[0].colorBuffer.diffuseColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
				materials[0].colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);

				constantBuffer.Update(materials[0].index * sizeof(MeshMaterial::ColorBuffer), sizeof(MeshMaterial::ColorBuffer), &materials[0].colorBuffer);
			}

			void MaterialManager::SetMaterial(MeshMaterial& material)
			{
				material.index = latestIndex;
				materials[material.index] = material;
				latestIndex++;

				constantBuffer.Update(material.index * sizeof(MeshMaterial::ColorBuffer), sizeof(MeshMaterial::ColorBuffer), &materials[material.index].colorBuffer);
			}

			void MaterialManager::UpdateMaterial(MeshMaterial& material)
			{
				materials[material.index] = material;
				constantBuffer.Update(material.index * sizeof(MeshMaterial::ColorBuffer), sizeof(MeshMaterial::ColorBuffer), &materials[material.index].colorBuffer);
			}
		}
	}
}