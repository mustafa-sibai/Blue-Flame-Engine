#pragma once
#include <vector>
#include "API/VertexBuffer.h"
#include "API/IndexBuffer.h"
#include "API/VertexBufferLayout.h"
#include "API/Texture2D.h"
#include "BF/Math/Math.h"
#include "Material.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BF_API MeshVertexData
		{
			Math::Vector3 position;
			//Math::Vector4 color;
			Math::Vector2 texcoord;
			Math::Vector3 normal;
			//float textureID;

			MeshVertexData() :
				position(0), texcoord(0), normal(0) { }

			MeshVertexData(Math::Vector3 position, Math::Vector2 texcoord, Math::Vector3 normal/*, float textureID*/) :
				position(position), /*color(Math::Vector4(1.0f, 1.0f, 1.0f, 1.0f)),*/ texcoord(texcoord), normal(normal)//, textureID(textureID)
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
				Mesh(std::vector<MeshVertexData>* vertices, std::vector<unsigned int>* indices, std::vector<Material>* materials);
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