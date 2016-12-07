#pragma once
#include <vector>
#include "Mesh.h"
#include "BF/IO/BFXLoader.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Model
		{
			private:
				API::Context* context;
				API::Shader* shader;
				API::VertexBufferLayout* vertexBufferLayout;
				std::vector<Mesh>* meshes;
				IO::BFXLoader bfxLoader;

			public:
				Model(API::Context* context, API::Shader* shader);
				~Model();

				void Load(const std::string& filename);
				void Draw();
		};
	}
}