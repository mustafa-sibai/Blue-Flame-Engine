#pragma once
#include <vector>
#include "Mesh.h"
#include "../IO/OBJReader.h"
#include "../Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Model
		{
			private:
				API::Context *context;
				API::Shader *shader;
				std::vector<Mesh> *meshes;
				IO::OBJReader *objReader;

			public:
				Model(API::Context *context, API::Shader *shader);
				~Model();

				void Load(const char *fileName);
				void Draw();
		};
	}
}