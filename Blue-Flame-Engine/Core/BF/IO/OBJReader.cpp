#include "OBJReader.h"

namespace BF
{
	namespace IO
	{
		struct Index
		{
			unsigned int positionIndex, texcoordIndex, normalIndex;
			int index;

			Index(unsigned int positionIndex, unsigned int texcoordIndex, unsigned int normalIndex) :
				positionIndex(0), texcoordIndex(0), normalIndex(0), index(-1)
			{
				this->positionIndex = positionIndex;
				this->texcoordIndex = texcoordIndex;
				this->normalIndex = normalIndex;
			}
		};

		OBJReader::OBJReader() :
			totalVertices(0), totalTexCoord(0), totalNormals(0)
		{
			meshes = new std::vector<Graphics::Mesh>();
			vertices = new std::vector<Graphics::MeshVertexData>();
			indices = new std::vector<unsigned int>();
		}

		OBJReader::~OBJReader()
		{
		}

		std::vector<Graphics::Mesh>* OBJReader::Load(const char* fileName)
		{
			FILE * file = fopen(fileName, "r");

			if (file == 0)
				printf("Impossible to open the file !\n");

			bool hasTextureCoords = false;
			bool didFormatScan = false;
			bool readFace = false;
			bool addPreviousMesh = false;
			bool containsGroups = false;

			std::vector<Math::Vector3> tempVertices;
			std::vector<Math::Vector2> tempTexcoord;
			std::vector<Math::Vector3> tempNormals;
			std::vector<Index> tempIndecies;

			while (true)
			{
				char lineHeader[255];

				int res = fscanf(file, "%s", lineHeader);

				if (res == EOF || strcmp(lineHeader, "o") == 0)
				{
					if ((res == EOF || strcmp(lineHeader, "o") == 0) && addPreviousMesh)
					{
						AddMesh(tempVertices, tempTexcoord, tempNormals, tempIndecies);

						if (res == EOF)
							break;
					}

					containsGroups = true;
					addPreviousMesh = true;
				}
				else if (strcmp(lineHeader, "v") == 0)
				{
					if (strcmp(lineHeader, "v") == 0 && readFace && !containsGroups)
					{
						AddMesh(tempVertices, tempTexcoord, tempNormals, tempIndecies);
						readFace = false;
					}

					Math::Vector3 vertex(0.0f);
					fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
					tempVertices.push_back(vertex);
				}
				else if (strcmp(lineHeader, "vt") == 0)
				{
					Math::Vector2 texcoord(0.0f);
					fscanf(file, "%f %f\n", &texcoord.x, &texcoord.y);
					tempTexcoord.push_back(texcoord);
				}
				else if (strcmp(lineHeader, "vn") == 0)
				{
					Math::Vector3 normal(0.0f);
					fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
					tempNormals.push_back(normal);
				}
				else if (strcmp(lineHeader, "f") == 0)
				{
					int vertexIndex[3] = { -1, -1, -1 };
					int texcoordIndex[3] = { -1, -1, -1 };
					int normalIndex[3] = { -1, -1, -1 };

					if (!didFormatScan)
					{
						//Check if file contains texture coordinates. 0//0
						fscanf(file, "%s", lineHeader);
						std::string s = lineHeader;
						std::size_t dfs = s.find("//");

						if (dfs == std::string::npos)
							hasTextureCoords = true;
						else
							hasTextureCoords = false;

						if (hasTextureCoords)
						{
							std::size_t ffs = s.find("/");
							std::size_t sfs = s.find("/", ffs + 1);

							vertexIndex[0] = std::stoi(s.substr(0, ffs));
							texcoordIndex[0] = std::stoi(s.substr(0, sfs));
							normalIndex[0] = std::stoi(s.substr(sfs + 1));

							fscanf(file, "%d/%d/%d %d/%d/%d\n", &vertexIndex[1], &texcoordIndex[1], &normalIndex[1], &vertexIndex[2], &texcoordIndex[2], &normalIndex[2]);
						}
						else
						{
							vertexIndex[0] = std::stoi(s.substr(0, dfs));
							normalIndex[0] = std::stoi(s.substr(dfs + 2));

							fscanf(file, "%d//%d %d//%d\n", &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
						}

						didFormatScan = true;
					}

					if (hasTextureCoords && didFormatScan)
					{
						fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
							&vertexIndex[0], &texcoordIndex[0], &normalIndex[0],
							&vertexIndex[1], &texcoordIndex[1], &normalIndex[1],
							&vertexIndex[2], &texcoordIndex[2], &normalIndex[2]);
					}
					else
					{
						fscanf(file, "%d//%d %d//%d %d//%d\n",
							&vertexIndex[0], &normalIndex[0],
							&vertexIndex[1], &normalIndex[1],
							&vertexIndex[2], &normalIndex[2]);
					}

					for (int i = 0; i < 3; i++)
					{
						if (hasTextureCoords)
							tempIndecies.push_back(Index(vertexIndex[i] - 1, texcoordIndex[i] - 1, normalIndex[i] - 1));
						else
							tempIndecies.push_back(Index(vertexIndex[i] - 1, 0, normalIndex[i] - 1));
					}

					readFace = true;
				}
			}

			return meshes;
		}

		void OBJReader::AddMesh(std::vector<Math::Vector3>& tempVertices, std::vector<Math::Vector2>& tempTexcoord, std::vector<Math::Vector3>& tempNormals, std::vector<Index>& tempIndecies)
		{
			int index = 0;

			for (size_t i = 0; i < tempIndecies.size(); i++)
			{
				/*for (int j = i; j < tempIndecies.size(); j++)
				{
					if (i != j)
					{
						if (tempIndecies[i].positionIndex == tempIndecies[j].positionIndex &&
							tempIndecies[i].texcoordIndex == tempIndecies[j].texcoordIndex &&
							tempIndecies[i].normalIndex == tempIndecies[j].normalIndex)
						{
							tempIndecies[j].index = i;
						}
					}
				}*/

				if (tempIndecies[i].index == -1)
				{
					tempIndecies[i].index = index;

					if (tempTexcoord.size() <= 0)
						vertices->push_back(Graphics::MeshVertexData(tempVertices[tempIndecies[i].positionIndex - totalVertices], Math::Vector2(0), tempNormals[tempIndecies[i].normalIndex - totalNormals]));
					else
						vertices->push_back(Graphics::MeshVertexData(tempVertices[tempIndecies[i].positionIndex - totalVertices], tempTexcoord[tempIndecies[i].texcoordIndex - totalTexCoord], tempNormals[tempIndecies[i].normalIndex - totalNormals]));

					index++;
				}
			}

			for (size_t i = 0; i < tempIndecies.size(); i++)
				indices->push_back(tempIndecies[i].index);

			meshes->push_back(Graphics::Mesh(vertices, indices));

			totalVertices += (unsigned int)tempVertices.size();
			totalTexCoord += (unsigned int)tempTexcoord.size();
			totalNormals += (unsigned int)tempNormals.size();
			vertices = new std::vector<Graphics::MeshVertexData>();
			indices = new std::vector<unsigned int>();

			tempVertices.clear();
			tempTexcoord.clear();
			tempNormals.clear();
			tempIndecies.clear();
		}
	}
}