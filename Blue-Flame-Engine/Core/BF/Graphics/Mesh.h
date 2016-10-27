#pragma once
#include <vector>
#include "API/VertexBuffer.h"
#include "API/IndexBuffer.h"
#include "API/VertexBufferLayout.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BF_API MeshVertexData
		{
			Math::Vector3 position;
			Math::Vector2 texcoord;
			Math::Vector3 normal;

			MeshVertexData() :
				position(0), texcoord(0), normal(0) { }

			MeshVertexData(Math::Vector3 position, Math::Vector2 texcoord, Math::Vector3 normal) :
				position(0), texcoord(0), normal(0)
			{
				this->position = position;
				this->texcoord = texcoord;
				this->normal = normal;
			}
		};

		class BF_API Mesh
		{
			//private:
		public:
				API::VertexBuffer* buffer;
				API::IndexBuffer* indexBuffer;
				std::vector<MeshVertexData>* vertices;
				std::vector<unsigned int>* indices;

			public:
				Mesh(std::vector<MeshVertexData>* vertices, std::vector<unsigned int>* indices);
				~Mesh();

				void SetBuffers(API::Context* context, API::Shader* shader);

				void Bind() const;
				void Unbind() const;

				inline std::vector<MeshVertexData>* GetVertices() const { return vertices; }
				inline std::vector<unsigned int>* GetIndices() const { return indices; }
		};
	}
}