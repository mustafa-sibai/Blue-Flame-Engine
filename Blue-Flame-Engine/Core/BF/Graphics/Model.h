#pragma once
#include "BF/Graphics/Mesh.h"
#include "BF/Graphics/Materials/MeshMaterial.h"
#include "BF/Graphics/Color.h"
#include "BF/ECS/Component.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class ForwardRenderer;
		}

		class BFE_API Model : public BF::ECS::Component<Model>
		{
			friend class BF::Graphics::Renderers::ForwardRenderer;

		public:
			enum class PresetMeshes { Plane };

		private:
			BF::Graphics::Materials::MaterialManager* materialManager;
			std::vector<Mesh> meshes;

		public:
			Model(std::vector<Mesh>& meshes);
			~Model();

			void Initialize(BF::Graphics::Materials::MaterialManager* materialManager);

			void Bind() const;
			void Unbind() const;
		};
	}
}