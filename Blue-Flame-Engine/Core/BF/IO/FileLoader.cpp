#include "FileLoader.h"
#include <fstream>
#include "BF/System/Debug.h"

namespace BF
{
	namespace IO
	{
		using namespace std;

		string FileLoader::LoadTextFile(const string& filename)
		{
			ifstream file(filename, ios::in);
			string data = "", line = "";

			if (file.is_open())
			{
				while (getline(file, line))
					data += line + "\n";
			}
			else
				BF_LOG_FATAL("Could not read text file " + filename + "\n", "");

			return data;
		}

		char* FileLoader::LoadBinaryFile(const string& filename, size_t* size)
		{
			char* data = nullptr;
			ifstream stream(filename, ifstream::in | ifstream::binary);

			if (stream.good())
			{
				stream.seekg(0, ios::end);
				*size = size_t(stream.tellg());
				data = new char[*size];
				stream.seekg(0, ios::beg);
				stream.read(&data[0], *size);
				stream.close();
			}
			else
				BF_LOG_FATAL("Could not read binary file " + filename + "\n", "");

			return data;
		}
	}
}