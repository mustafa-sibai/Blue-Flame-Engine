#pragma once
#include <vector>
#include "API/VertexBuffer.h"
#include "API/IndexBuffer.h"
#include "API/VertexBufferLayout.h"
#include "../Math/Math.h"
#include "../Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BF_API Vertex
		{
			Math::Vector3 position;
			Math::Vector2 texcoord;
			Math::Vector3 normal;

			Vertex() :
				position(0), texcoord(0), normal(0) { }

			Vertex(Math::Vector3 position, Math::Vector2 texcoord, Math::Vector3 normal) :
				position(0), texcoord(0), normal(0)
			{
				this->position = position;
				this->texcoord = texcoord;
				this->normal = normal;
			}
		};

		class BF_API Mesh
		{
			private:
				API::VertexBuffer *buffer;
				API::IndexBuffer *indexBuffer;
				API::VertexBufferLayout *vertexBufferLayout;

				std::vector<Vertex> *vertices;
				std::vector<unsigned int> *indices;


			public:
				Mesh(std::vector<Vertex> *vertices, std::vector<unsigned int> *indices);
				~Mesh();

				void SetBuffers(API::Context *context, API::Shader *shader);

				const void Bind() const;
				const void Unbind() const;

				inline std::vector<Vertex> *GetVertices() const { return vertices; }
				inline std::vector<unsigned int> *GetIndices() const { return indices; }
		};
	}
}