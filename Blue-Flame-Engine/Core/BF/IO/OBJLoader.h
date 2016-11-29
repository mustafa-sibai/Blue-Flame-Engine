#pragma once
#include <vector>
#include <fstream>
#include <string.h>
#include "BF/Math/Math.h"
#include "BF/Graphics/Mesh.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API OBJReader
		{
			private:
				struct Index;
				std::vector<Graphics::Mesh>* meshes;
				std::vector<Graphics::MeshVertexData>* vertices;
				std::vector<unsigned int>* indices;
				std::vector<std::string> meshMaterialNames;

				unsigned int totalVertices, totalTexCoord, totalNormals, index;
				std::string filePath;
				std::string materialFileName;

			public:
				OBJReader();
				~OBJReader();

				std::vector<Graphics::Mesh>* Load(std::string fileName);
				void LoadOBJFile(std::string fileName);
				void LoadMaterialFile();
				void AddMesh(std::vector<Math::Vector3>& tempVertices, std::vector<Math::Vector2>& tempTexcoord, std::vector<Math::Vector3>& tempNormals, std::vector<Index>& tempIndecies);
		};
	}
}