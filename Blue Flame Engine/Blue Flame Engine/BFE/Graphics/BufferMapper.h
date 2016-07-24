#pragma once
#include "Renderer/Renderer.h"
#include "Shader/Shader.h"
#include "Buffer.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class DLLEXPORT BufferMapper
		{
			private:
				Renderer &renderer;

			public:
				enum DataType { BYTE, SHORT, INT, FLOAT, DOUBLE };
				struct ShaderLayout
				{
					int index;
					char* name;
					unsigned int componentCount;
					DataType dataType;
					unsigned int stride;
					unsigned int offset;
				};

			public:
				BufferMapper(Renderer &renderer);
				~BufferMapper();

				void Map(Buffer &buffer, Shader &shader, ShaderLayout *shaderLayout, const unsigned short count);

			private:
				GLenum GetGLDataType(DataType dataType);
				DXGI_FORMAT GetDX11DataType(DataType dataType, unsigned int componentCount);
		};
	}
}