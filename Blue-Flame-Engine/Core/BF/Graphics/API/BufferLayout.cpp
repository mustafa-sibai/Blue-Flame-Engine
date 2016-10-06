#include "BufferLayout.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			BufferLayout::BufferLayout() :
				bufferElements(NULL)
			{
			}

			BufferLayout::~BufferLayout()
			{
			}

			void BufferLayout::Push(int index, char *name, DataType dataType, unsigned int stride, unsigned int offset)
			{
				BufferElement bufferElement;
				bufferElement.index = index;
				bufferElement.name = name;
				bufferElement.dataType = dataType;
				bufferElement.stride = stride;
				bufferElement.offset = offset;
				bufferElements.push_back(bufferElement);
			}
		}
	}
}