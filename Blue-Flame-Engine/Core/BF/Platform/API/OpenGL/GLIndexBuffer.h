#pragma once
#include "BF/Platform/API/OpenGL/GLCommon.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLIndexBuffer
				{
					private:
						GLuint buffer;
						unsigned int count;

					public:
						GLIndexBuffer();
						~GLIndexBuffer();

						void Create(const unsigned int* indices, unsigned int count);

						void Bind() const;
						void Unbind() const;

						inline const GLuint& GetBuffer() const { return buffer; }
						inline unsigned int GetIndicesCount() const { return count; }
				};
			}
		}
	}
}