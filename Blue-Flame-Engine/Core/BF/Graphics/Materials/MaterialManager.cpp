#include "MaterialManager.h"
#include "BF/Graphics/Mesh.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			using namespace BF::Graphics::API;

			MeshMaterial MaterialManager::materials[BFE_MATERIAL_ARRAY_COUNT];

			MaterialManager::MaterialManager(ConstantBufferManager& constantBufferManager) :
				constantBufferManager(constantBufferManager), latestIndex(1)
			{
			}

			MaterialManager::~MaterialManager()
			{
			}

			void MaterialManager::Initialize()
			{
				materials[0].index = 0;
				materials[0].shader = new Shader();
				materials[0].shader->LoadStandardShader(ShaderType::P);
				materials[0].colorBuffer.ambientColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
				materials[0].colorBuffer.diffuseColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
				materials[0].colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);

				constantBufferManager.UpdateMaterial(materials[0]);
			}

			void MaterialManager::AddMaterial(MeshMaterial& material)
			{
				if (latestIndex >= BFE_MATERIAL_ARRAY_COUNT - 1)
					BFE_LOG_ERROR("Material array max size is reached. Please expand the array from " + std::to_string(BFE_MATERIAL_ARRAY_COUNT) + " to a bigger number", "");
				else
				{
					material.index = latestIndex;
					materials[material.index] = material;
					latestIndex++;
					constantBufferManager.UpdateMaterial(material);
				}
			}

			void MaterialManager::RemoveMaterial(const Mesh* mesh, MeshMaterial& material)
			{
				if (material.meshesUsingCurrentMaterial.size() <= 1)
				{
					freeIndecies.emplace_back(material.index);

					materials[material.index].index = 0;
					materials[material.index].shader = nullptr;
					materials[material.index].colorBuffer = MeshMaterialColorBuffer();
					materials[material.index].meshesUsingCurrentMaterial.clear();

					material.index = 0;
					material.meshesUsingCurrentMaterial.clear();
				}
				else
				{
					/*for (std::vector<BF::Graphics::Mesh*>::iterator it = material.meshesUsingCurrentMaterial.begin(); it != material.meshesUsingCurrentMaterial.end(); ++it)
					{
						if (((BF::Graphics::Mesh*)*it)->GetID() == mesh->GetID())
						{
							material.meshesUsingCurrentMaterial.erase(it);
							break;
						}
					}*/
				}
			}
		}
	}
}