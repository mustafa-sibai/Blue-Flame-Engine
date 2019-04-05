#pragma once
#include <vector>
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/TextureCube.h"
#include "BF/Graphics/Renderers/IRenderer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API SkyboxRenderer : public BF::Graphics::Renderers::IRenderer
			{
			private:
				BF::Graphics::API::Shader shader;
				BF::Graphics::API::VertexBuffer vertexBuffer;
				BF::Graphics::API::IndexBuffer indexBuffer;
				BF::Graphics::API::VertexBufferLayout vertexBufferLayout;
				BF::Graphics::API::TextureCube textureCube;

				std::vector<float> vertcies;
				std::vector<unsigned int> indices;

			public:
				SkyboxRenderer();
				~SkyboxRenderer();

				void Initialize()										override;
				void Load(const std::vector<std::string>& filenames);
				void PostLoad()											override;
				void Update(double deltaTime)							override;
				void Render()											override;

				void Bind();
				void Unbind();
			};
		}
	}
}