#pragma once
#include <iostream>
#include <BF/IO/FileFormats/BFFFormat.h>
#include <BF/Graphics/Fonts/Font.h>

namespace Editor
{
	namespace IO
	{
		class BFFWriter
		{
		private:
			BF::IO::FileFormats::BFFFormat bffFormat;

		public:
			BFFWriter();
			~BFFWriter();

			void WriteToFile(const std::string& filename, const BF::Graphics::Fonts::Font& font);
		};
	}
}