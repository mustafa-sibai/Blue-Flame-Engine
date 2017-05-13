#pragma once
#include "BF/Graphics/API/Texture2D.h"
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
				class BF_API GLFramebuffer
				{
				private:
					const Graphics::API::Texture2D* texture2D;
					GLuint buffer;

				public:
					GLFramebuffer();
					~GLFramebuffer();

					void Create(Graphics::API::Texture2D& texture2D);

					void Bind() const;
					void Unbind() const;
				};
			}
		}
	}
}