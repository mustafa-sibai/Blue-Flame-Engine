#pragma once
#include <vector>
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/TextureCube.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Skybox
		{
		private:
			API::Shader shader;
			API::VertexBuffer vertexBuffer;
			API::IndexBuffer indexBuffer;
			API::VertexBufferLayout vertexBufferLayout;
			API::TextureCube textureCube;

			std::vector<float> vertcies;
			std::vector<unsigned int> indices;

		public:
			Skybox();
			~Skybox();

			void Initialize();
			void Load(const std::vector<std::string>& filenames, const std::string& vertexShaderFilename, const std::string& pixelShaderFilename);
			void Render();

			void Bind();
			void Unbind();
		};
	}
}