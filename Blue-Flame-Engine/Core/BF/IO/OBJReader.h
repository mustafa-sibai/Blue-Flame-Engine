#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "../Math/Math.h"
#include "../Graphics/Mesh.h"
#include "../Common.h"

namespace BF
{
	namespace IO
	{
		struct Index;
		class BF_API OBJReader
		{
			private:
				std::vector<Graphics::Mesh> *meshes;
				std::vector<Graphics::Vertex> *vertices;
				std::vector<unsigned int> *indices;

				unsigned int totalVertices, totalTexCoord, totalNormals;

			public:
				OBJReader();
				~OBJReader();

				std::vector<Graphics::Mesh> *Load(const char *fileName);
				void AddMesh(std::vector<Math::Vector3> &tempVertices, std::vector<Math::Vector2> &tempTexcoord, std::vector<Math::Vector3> &tempNormals, std::vector<Index> &tempIndecies);
		};
	}
}