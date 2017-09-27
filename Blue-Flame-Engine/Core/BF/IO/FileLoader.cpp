#include "FileLoader.h"
#include <string>
#include "BF/System//Log.h"

namespace BF
{
	namespace IO
	{
		std::string FileLoader::LoadTextFile(const std::string& filename)
		{
			std::ifstream file(filename, std::ios::in);
			std::string data = "", line = "";

			if (file.is_open())
			{
				while (std::getline(file, line))
					data += line + "\n";
			}
			else
				BF_LOG_FATAL("Could not read text file %s", filename.c_str());

			return data;
		}

		char* FileLoader::LoadBinaryFile(const std::string& filename, size_t* size)
		{
			char* data = nullptr;
			std::ifstream stream(filename, std::ifstream::in | std::ifstream::binary);

			if (stream.good())
			{
				stream.seekg(0, std::ios::end);
				*size = size_t(stream.tellg());
				data = new char[*size];
				stream.seekg(0, std::ios::beg);
				stream.read(&data[0], *size);
				stream.close();
			}
			else
				BF_LOG_FATAL("Could not read binary file %s", filename.c_str());

			return data;
		}
	}
}