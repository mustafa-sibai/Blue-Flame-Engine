#pragma once
#include "API/Shader.h"
#include "API/VertexBuffer.h"
#include "API/IndexBuffer.h"
#include "API/VertexBufferLayout.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Terrain
		{
		private:
			API::Shader shader;
			API::VertexBuffer vertexBuffer;
			API::IndexBuffer indexBuffer;
			API::VertexBufferLayout vertexBufferLayout;
		
			uint8_t* data;
			unsigned int width, height;

		public:
			Terrain();
			~Terrain();

			void Initialize();
			void Load(const std::string& filename);
			void Render();
		};
	}
}