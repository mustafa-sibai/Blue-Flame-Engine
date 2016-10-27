#pragma once
#include <vector>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class DataType { Byte, Short, Int, Float, Float2, Float3, Float4, Double };

			struct BF_API VertexBufferElement
			{
				int index = 0;
				const char* name = 0;
				DataType dataType;
				unsigned int stride = 0;
				unsigned int offset = 0;
			};

			class BF_API VertexBufferLayout
			{
				private:
					std::vector<VertexBufferElement> vertexBufferElements;

				public:
					VertexBufferLayout();
					~VertexBufferLayout();

					void Push(int index, const char* name, DataType dataType, unsigned int stride, unsigned int offset);

					inline std::vector<VertexBufferElement> GetBufferElement() const { return vertexBufferElements; }
			};
		}
	}
}