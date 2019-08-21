#pragma once
#include "BF/Graphics/API/BufferMode.h"
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
				class BFE_API GLIndexBuffer
				{
				private:
					GLuint buffer;
					unsigned int count;

				public:
					GLIndexBuffer();
					~GLIndexBuffer();

					void Create();
					void SetBuffer(const unsigned int* indices, unsigned int count, BF::Graphics::API::BufferMode mode);

					void* Map() const;
					void Unmap() const;

					void Bind() const;
					void Unbind() const;

					inline const GLuint& GetBuffer() const { return buffer; }
					inline unsigned int GetIndicesCount() const { return count; }

				private:
					GLenum GetGLBufferMode(BF::Graphics::API::BufferMode mode);
				};
			}
		}
	}
}