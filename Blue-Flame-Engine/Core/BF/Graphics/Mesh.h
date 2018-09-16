#pragma once
#include <vector>
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/Materials/MeshMaterial.h"
#include "BF/Graphics/Color.h"
#include "BF/ECS/Component.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Mesh : public BF::ECS::Component
		{
			public:
				#include "VertexData.inl"

				enum class VertexStructVersion { P, PUV, PN, PUVN, PUVNTB };
				VertexStructVersion vertexStructVersion;

				BF::Graphics::Materials::MeshMaterial* material;

			private:
				BF::Graphics::API::VertexBufferLayout vertexBufferLayout;
				BF::Graphics::API::VertexBuffer* vertexBuffer;
				BF::Graphics::API::IndexBuffer* indexBuffer;
				std::vector<unsigned int>& indices;
				void* vertices;

			public:
				Mesh(void* vertices, std::vector<unsigned int>& indices, VertexStructVersion vertexStructVersion);
				~Mesh();

				void SetBuffers();

				void Bind() const;
				void Unbind() const;

				unsigned int GetVerticesCount() const;

			public:
				inline BF::Graphics::API::VertexBuffer* GetVertexBuffer() const { return vertexBuffer; }
				inline void* GetVertices() const { return vertices; }
				inline std::vector<unsigned int>& GetIndices() const { return indices; }
		};
	}
}