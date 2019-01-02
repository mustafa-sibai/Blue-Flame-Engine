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
				class BF_API GLConstantBuffer
				{
					private:
						GLuint buffer;
						unsigned int bindingIndex;

					public:
						GLConstantBuffer();
						~GLConstantBuffer();

						void Create(unsigned int bindingIndex, unsigned int size, const void* data);
						void Update(unsigned int offset, unsigned int size, const void* data);
				};
			}
		}
	}
}