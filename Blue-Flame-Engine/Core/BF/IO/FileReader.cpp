#include "FileReader.h"

namespace BF
{
	namespace IO
	{
		std::string FileReader::ReadTextFile(const char* fileName)
		{
			std::ifstream file(fileName, std::ios::in);
			std::string data = "", line = "";

			if (file.is_open())
			{
				while (std::getline(file, line))
					data += line + "\n";
			}
			else
				throw std::runtime_error(std::string("Could not read text file ") + fileName);

			return data;
		}

		char* FileReader::ReadBinaryFile(const char* fileName, size_t* size)
		{
			std::ifstream stream;
			char* data;

			stream.open(fileName, std::ifstream::in | std::ifstream::binary);
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
			{
				throw std::runtime_error(std::string("Could not read binary file ") + fileName);
			}

			return data;
		}
	}
}