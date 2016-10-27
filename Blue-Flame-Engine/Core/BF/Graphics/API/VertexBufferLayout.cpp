#include "VertexBufferLayout.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			VertexBufferLayout::VertexBufferLayout() :
				vertexBufferElements(0)
			{
			}

			VertexBufferLayout::~VertexBufferLayout()
			{
			}

			void VertexBufferLayout::Push(int index, const char* name, DataType dataType, unsigned int stride, unsigned int offset)
			{
				VertexBufferElement vertexBufferElement;
				vertexBufferElement.index = index;
				vertexBufferElement.name = name;
				vertexBufferElement.dataType = dataType;
				vertexBufferElement.stride = stride;
				vertexBufferElement.offset = offset;
				vertexBufferElements.push_back(vertexBufferElement);
			}
		}
	}
}