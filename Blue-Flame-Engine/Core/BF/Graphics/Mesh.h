#pragma once
#include <vector>
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
#include "BF/Graphics/API/Texture2D.h"
#include "BF/Graphics/Color.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Mesh
		{
			public:
				#include "VertexData.inl"

				enum class VertexStructVersion { P, PUV, PN, PUVN, PUVNTB };
				VertexStructVersion vertexStructVersion;

			private:
				BF::Graphics::API::VertexBuffer* vertexBuffer;
				BF::Graphics::API::IndexBuffer* indexBuffer;
				//std::vector<API::Texture2D*>* textures;
				void* vertices;
				//std::vector<Material>* materials;
				std::vector<unsigned int>& indices;
				std::string textureFilename;

			public:
				Mesh(void* vertices, std::vector<unsigned int>& indices, VertexStructVersion vertexStructVersion/*, std::vector<Material>* materials*/);
				~Mesh();

				void SetBuffers(const BF::Graphics::API::Shader& shader, unsigned int bufferSize);
				void SetTexturefilename(std::string textureFilename);

				void Bind() const;
				void Unbind() const;

			private:
				unsigned int getVerticesCount() const;

			public:
				inline BF::Graphics::API::VertexBuffer* GetVertexBuffer() const { return vertexBuffer; }
				inline void* GetVertices() const { return vertices; }
				inline unsigned int GetVerticesCount() const { return getVerticesCount(); }
				inline std::vector<unsigned int>& GetIndices() const { return indices; }

		};
	}
}