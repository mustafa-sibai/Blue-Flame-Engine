#include "VertexBufferLayout.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace std;

			VertexBufferLayout::VertexBufferLayout() :
				vertexBufferElements(0)
			{
			}

			VertexBufferLayout::~VertexBufferLayout()
			{
			}

			void VertexBufferLayout::Push(int index, const string& name, DataType dataType, unsigned int stride, unsigned int offset)
			{
				VertexBufferElement vertexBufferElement;
				vertexBufferElement.index = index;
				vertexBufferElement.name = name;
				vertexBufferElement.dataType = dataType;
				vertexBufferElement.stride = stride;
				vertexBufferElement.offset = offset;
				vertexBufferElements.emplace_back(vertexBufferElement);
			}
		}
	}
}