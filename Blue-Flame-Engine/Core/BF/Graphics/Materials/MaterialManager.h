#pragma once
#include "MeshMaterial.h"
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Common.h"

#define BFE_DEFAULT_MATERIAL_INDEX 0
#define BFE_MATERIAL_ARRAY_COUNT 256

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			class BFE_API MaterialManager
			{
			private:
				BF::Graphics::ConstantBufferManager& constantBufferManager;
				int latestIndex;
				static MeshMaterial materials[BFE_MATERIAL_ARRAY_COUNT];
				std::vector<int> freeIndecies;

			public:
				MaterialManager(BF::Graphics::ConstantBufferManager& constantBufferManager);
				~MaterialManager();

				void Initialize();

				void AddMaterial(MeshMaterial& material);
				void RemoveMaterial(const BF::Graphics::Mesh* mesh, MeshMaterial& material);

				static inline MeshMaterial& GetDefaultMaterial() { return materials[BFE_DEFAULT_MATERIAL_INDEX]; }
			};
		}
	}
}