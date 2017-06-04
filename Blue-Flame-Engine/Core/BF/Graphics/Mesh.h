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
		struct BF_API MeshVertexData
		{
			Math::Vector3 position;
			Math::Vector2 texcoord;
			Math::Vector3 normal;
			Math::Vector3 tangent;
			Math::Vector3 binormal;
			//Color color;

			MeshVertexData() :
				position(0), texcoord(0), normal(0), tangent(0), binormal(0) { }

			MeshVertexData(Math::Vector3 position, /*Color color,*/ Math::Vector2 texcoord, Math::Vector3 normal, Math::Vector3 tangent, Math::Vector3 binormal) :
				position(position), /*color(color), */texcoord(texcoord), normal(normal), tangent(tangent), binormal(binormal)
			{
			}
		};

		class BF_API Mesh
		{
			private:
				API::VertexBuffer* vertexBuffer;
				API::IndexBuffer* indexBuffer;
				//std::vector<API::Texture2D*>* textures;
				std::vector<MeshVertexData>* vertices;
				//std::vector<Material>* materials;
				std::vector<unsigned int>* indices;
				std::string textureFileName;

			public:
				Mesh(std::vector<MeshVertexData>* vertices, std::vector<unsigned int>* indices/*, std::vector<Material>* materials*/);
				~Mesh();

				void SetBuffers(const API::Shader& shader);
				void SetTextureFileName(std::string textureFileName);

				void Bind() const;
				void Unbind() const;

				inline API::VertexBuffer* GetVertexBuffer() const { return vertexBuffer; }
				inline std::vector<MeshVertexData>* GetVertices() const { return vertices; }
				inline std::vector<unsigned int>* GetIndices() const { return indices; }
		};
	}
}