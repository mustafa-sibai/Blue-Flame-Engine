#pragma once
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
#include "BF/Graphics/Materials/MeshMaterial.h"
#include "BF/Graphics/MeshData.h"
#include "BF/Graphics/Color.h"
#include "BF/ECS/Component.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API Mesh
		{
		public:
			enum class PresetMeshes { Plane };
			BF::Graphics::Materials::MeshMaterial material;
			MeshData* meshData;

		private:
			BF::Graphics::Materials::MaterialManager* materialManager;
			BF::Graphics::API::VertexBufferLayout vertexBufferLayout;
			BF::Graphics::API::VertexBuffer* vertexBuffer;
			BF::Graphics::API::IndexBuffer* indexBuffer;

		public:
			Mesh(PresetMeshes presetMeshes);
			Mesh(MeshData* meshData);
			~Mesh();

			void Initialize(BF::Graphics::Materials::MaterialManager* materialManager);

			void SetMeshData(MeshData* meshData);

			void AddMaterial(BF::Graphics::Materials::MeshMaterial& material);

			void Bind() const;
			void Unbind() const;

			//unsigned int GetVerticesCount() const;

		private:
			void CreateMaterialFromMaterialData();

		public:
			inline BF::Graphics::API::VertexBuffer* GetVertexBuffer() const { return vertexBuffer; }
		};
	}
}