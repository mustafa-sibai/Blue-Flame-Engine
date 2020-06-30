#pragma once
#include "BF/Graphics/API/BufferMode.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
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
				class BFE_API GLVertexBuffer
				{
				private:
					GLuint vao;
					GLuint vbo;
					unsigned int size;
					const BF::Graphics::API::VertexBufferLayout* vertexBufferLayout;

				public:
					GLVertexBuffer();
					~GLVertexBuffer();

					void Create();
					void Allocate(unsigned int size, const void* data, BF::Graphics::API::BufferMode mode);

					void SetLayout(const BF::Graphics::API::VertexBufferLayout* vertexBufferLayout);

					void* Map() const;
					void Unmap() const;

					void* MapPersistentStream() const;
					void UnmapPersistentStream() const;

					void Bind() const;
					void Unbind() const;

					inline const GLuint& GetBuffer() const { return vbo; }

				private:
					GLenum GetGLBufferMode(BF::Graphics::API::BufferMode mode);
					GLenum GetGLDataType(BF::Graphics::API::VertexBufferLayout::DataType dataType);
					unsigned int GetComponentCount(BF::Graphics::API::VertexBufferLayout::DataType dataType);
				};
			}
		}
	}
}