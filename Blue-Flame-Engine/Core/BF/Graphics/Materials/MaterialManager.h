#pragma once
#include "MeshMaterial.h"
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Common.h"

#define BF_MATERIAL_ARRAY_COUNT 256

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			class BF_API MaterialManager
			{
				private:
					int latestIndex;
					MeshMaterial materials[BF_MATERIAL_ARRAY_COUNT];
					BF::Graphics::API::ConstantBuffer constantBuffer;

				public:
					MaterialManager();
					~MaterialManager();

					void Initialize();

					void SetMaterial(MeshMaterial& material);
					void UpdateMaterial(MeshMaterial& material);
			};
		}
	}
}