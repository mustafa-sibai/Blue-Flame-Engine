#pragma once
#include <vector>
#include "BF/Graphics/API/VertexArray.h"
#include "Mesh.h"
#include "BF/IO/OBJReader.h"
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
				API::VertexArray* vertexArray;
				API::VertexBufferLayout* vertexBufferLayout;
				std::vector<Mesh>* meshes;
				IO::OBJReader* objReader;

			public:
				Model(API::Context* context, API::Shader* shader);
				~Model();

				void Load(const char* fileName);
				void Draw();
		};
	}
}