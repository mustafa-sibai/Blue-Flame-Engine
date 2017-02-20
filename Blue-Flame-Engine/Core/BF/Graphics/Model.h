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
				const API::Shader& shader;
				API::VertexBufferLayout vertexBufferLayout;
				std::vector<Mesh>* model;

			public:
				Model(const API::Shader& shader);
				~Model();

				void Load(const std::string& filename);
				void Render();
		};
	}
}