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

		Model::Model(std::vector<Mesh>& meshes) :
			meshes(meshes), materialManager(nullptr)
		{
		}

		Model::~Model()
		{
		}

		void Model::Initialize(MaterialManager* materialManager)
		{
			this->materialManager = materialManager;
			for (size_t i = 0; i < meshes.size(); i++)
			{
				meshes[i].Initialize(materialManager);
			}
		}

		void Model::Bind() const
		{
		}

		void Model::Unbind() const
		{
		}
	}
}