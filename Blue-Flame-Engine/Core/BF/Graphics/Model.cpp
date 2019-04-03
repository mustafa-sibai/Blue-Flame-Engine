#include "Model.h"
#include "Materials/MaterialManager.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Graphics::API;
		using namespace BF::Graphics::Materials;

		Model::Model() :
			materialManager(nullptr)
		{
			type = IComponent::Type::Model;
		}

		Model::~Model()
		{
		}

		void Model::Initialize(MaterialManager* materialManager)
		{
			this->materialManager = materialManager;

			for (size_t i = 0; i < materials.size(); i++)
			{
				materialManager->AddMaterial(materials[i]);
			}

			for (size_t i = 0; i < meshes.size(); i++)
			{
				meshes[i].material = materials[meshes[i].meshData->materialIndexInModel];
				meshes[i].Initialize(materialManager);
			}
		}

		void Model::AddMesh(Mesh& mesh)
		{
			meshes.emplace_back(mesh);
		}

		void Model::AddMaterial(MeshMaterial& meshMaterial)
		{
			materials.emplace_back(meshMaterial);
		}

		void Model::Bind() const
		{
		}

		void Model::Unbind() const
		{
		}
	}
}