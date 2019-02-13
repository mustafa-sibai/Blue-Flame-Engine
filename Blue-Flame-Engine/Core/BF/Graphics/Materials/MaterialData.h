#pragma once
#include "BF/Graphics/Materials/MeshMaterialColorBuffer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			struct BFE_API MaterialData
			{
				MeshMaterialColorBuffer meshMaterialColorBuffer;

				/*
				textures[0] = diffuseTexture
				textures[1] = specularTexture
				textures[2] = normalTexture
				*/
				std::string textures[3];

				/*
				textures[0] = diffuseTexture
				textures[1] = specularTexture
				textures[2] = normalTexture
				*/
				MaterialData(const MeshMaterialColorBuffer& meshMaterialColorBuffer, std::string textures[3]) :
					meshMaterialColorBuffer(meshMaterialColorBuffer)
				{
					for (size_t i = 0; i < 3; i++)
						this->textures[i] = textures[i];
				}
			};
		}
	}
}