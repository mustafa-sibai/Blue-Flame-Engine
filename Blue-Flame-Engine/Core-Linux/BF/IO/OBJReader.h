#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "../Math/Math.h"
#include "../Common.h"
#include <time.h>

namespace BF
{
	namespace IO
	{
		struct BF_API Vertex
		{
			Math::Vector3 position;
			Math::Vector2 texcoord;
			Math::Vector3 normal;

			Vertex(Math::Vector3 position, Math::Vector2 texcoord, Math::Vector3 normal) :
				position(0), texcoord(0), normal(0)
			{
				this->position = position;
				this->texcoord = texcoord;
				this->normal = normal;
			}
		};

		struct BF_API OBJReader
		{
			private:
				std::vector<Vertex> vertices;
				std::vector<unsigned int> indices;

			public:
				OBJReader();
				~OBJReader();

				void Load(const char* fileName);

				inline std::vector<Vertex> GetVertices() const { return vertices; }
				inline std::vector<unsigned int> GetIndices() const { return indices; }
		};
	}
}