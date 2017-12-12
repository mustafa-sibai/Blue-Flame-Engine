#pragma once
#include <vector>
#include "BF/Graphics/Mesh.h"
#include "BF/IO/BFXLoader.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Model
		{
			private:
				const BF::Graphics::API::Shader& shader;
				BF::Graphics::API::VertexBufferLayout vertexBufferLayout;
				std::vector<Mesh>* model;

			public:
				Model(const BF::Graphics::API::Shader& shader);
				~Model();

				void Load(const std::string& filename);
				void Render();
		};
	}
}