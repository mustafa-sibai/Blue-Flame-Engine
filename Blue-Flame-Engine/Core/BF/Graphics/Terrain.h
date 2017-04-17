#pragma once
#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
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