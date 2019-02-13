#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <BF/Graphics/Mesh.h>
#include <BF/IO/FileFormats/BFXFormat.h>

namespace Editor
{
	namespace IO
	{
		class BFXWriter
		{
			private:
				BF::IO::FileFormats::BFXFormat bfxFormat;
				const std::vector<BF::Graphics::MeshData>& meshesData;

			public:
				BFXWriter(const std::vector<BF::Graphics::MeshData>& meshesData);
				~BFXWriter();

				void WriteToFile(const std::string& filename);
		};
	}
}