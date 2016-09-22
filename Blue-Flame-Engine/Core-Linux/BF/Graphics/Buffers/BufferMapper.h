#if 0
#pragma once
#include "../Renderer/Renderer.h"
#include "../Shader/Shader.h"
#include "../Buffers/VertexBuffer.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		namespace Buffers
		{
			class DLLEXPORT BufferMapper
			{
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

				private:
					Renderer &renderer;
					ID3D11InputLayout *inputLayout;
					Shader *shader;
					ShaderLayout *shaderLayout;
					unsigned short count;

				public:
					BufferMapper(Renderer &renderer);
					~BufferMapper();
					void Create(Shader *shader, ShaderLayout *shaderLayout, const unsigned short count);
					void Map(VertexBuffer *vertexBuffer);

				private:
					GLenum GetGLDataType(DataType dataType);
					DXGI_FORMAT GetDX11DataType(DataType dataType, unsigned int componentCount);
			};
		}
	}
}
#endif