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

					public:
						GLConstantBuffer();
						~GLConstantBuffer();

						void Create(unsigned int size, unsigned int bindingIndex);
						void Update(const void* data, unsigned int size);
				};
			}
		}
	}
}