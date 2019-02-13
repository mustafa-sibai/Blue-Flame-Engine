#pragma once
#include <vector>
#include "BF/Math/Math.h"
#include "BF/Graphics/Materials/MaterialData.h"
#include "BF/IO/Resource.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BFE_API MeshData : BF::IO::Resource
		{
			enum class VertexStructVersion { P, PUV, PN, PUVN, PUVNTB };
			VertexStructVersion vertexStructVersion;

#include "VertexData.inl"

			void* vertices;
			std::vector<unsigned int>* indices;
			BF::Graphics::Materials::MaterialData materialData;

			MeshData(void* vertices, std::vector<unsigned int>* indices, const BF::Graphics::Materials::MaterialData& materialData, VertexStructVersion vertexStructVersion) :
				Resource(BF::IO::Resource::Type::Mesh),
				vertices(vertices), indices(indices), materialData(materialData), vertexStructVersion(vertexStructVersion)
			{
			}

			inline unsigned int GetVerticesCount() const
			{
				switch (vertexStructVersion)
				{
				case MeshData::VertexStructVersion::P:
				{
					return (unsigned int)((std::vector<PVertexData>*)vertices)->size();
					break;
				}
				case MeshData::VertexStructVersion::PUV:
				{
					return (unsigned int)((std::vector<PUVVertexData>*)vertices)->size();
					break;
				}
				case MeshData::VertexStructVersion::PN:
				{
					return (unsigned int)((std::vector<PNVertexData>*)vertices)->size();
					break;
				}
				case MeshData::VertexStructVersion::PUVN:
				{
					return (unsigned int)((std::vector<PUVNVertexData>*)vertices)->size();
					break;
				}
				case MeshData::VertexStructVersion::PUVNTB:
				{
					return (unsigned int)((std::vector<PUVNTBVertexData>*)vertices)->size();
					break;
				}
				default:
				{
					return 0;
					break;
				}
				}
			}
		};
	}
}