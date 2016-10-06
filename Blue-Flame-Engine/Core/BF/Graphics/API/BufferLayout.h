#pragma once
#include <vector>
#include "../../Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class DataType { Byte, Short, Int, Float, Float2, Float3, Float4, Double };

			struct BF_API BufferElement
			{
				int index = 0;
				char* name = NULL;
				DataType dataType;
				unsigned int stride = 0;
				unsigned int offset = 0;
			};

			class BF_API BufferLayout
			{
				private:
					std::vector<BufferElement> bufferElements;

				public:
					BufferLayout();
					~BufferLayout();

					void Push(int index, char* name, DataType dataType, unsigned int stride, unsigned int offset);

					inline const std::vector<BufferElement> GetBufferElement() const { return bufferElements; }
			};
		}
	}
}