#pragma once
#include <iostream>
#include <fstream>
#include <string>

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace IO
	{
		struct DLLEXPORT FileReader
		{
			static std::string ReadTextFile(const char *FileName)
			{
				std::ifstream file(FileName, std::ios::in);
				std::string data = "", line = "";

				if (file.is_open())
				{
					while (std::getline(file, line))
						data += line + "\n";
				}
				else
					throw std::runtime_error(std::string("Could not read text file ") + FileName);

				return data;
			}

			static char* ReadBinaryFile(const char *FileName, size_t &size)
			{
				std::ifstream stream;
				char* data;

				stream.open(FileName, std::ifstream::in | std::ifstream::binary);
				if (stream.good())
				{
					stream.seekg(0, std::ios::end);
					size = size_t(stream.tellg());
					data = new char[size];
					stream.seekg(0, std::ios::beg);
					stream.read(&data[0], size);
					stream.close();
				}
				else
				{
					throw std::runtime_error(std::string("Could not read binary file ") + FileName);
				}

				return data;
			}
		};
	}
}