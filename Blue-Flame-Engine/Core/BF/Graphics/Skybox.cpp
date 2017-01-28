#include "Skybox.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Graphics::API;

		Skybox::Skybox() :
			vertexBuffer(shader), textureCube(shader)
		{
		}

		Skybox::~Skybox()
		{
		}

		void Skybox::Initialize()
		{
			vertcies =
			{
				-1.0f,  1.0f, -1.0f,
				-1.0f, -1.0f, -1.0f,
				 1.0f, -1.0f, -1.0f,
				 1.0f,  1.0f, -1.0f,
				-1.0f, -1.0f,  1.0f,
				-1.0f,  1.0f,  1.0f,
				 1.0f, -1.0f,  1.0f,
				 1.0f,  1.0f,  1.0f,
			};

			indices = { 0, 1, 2, 2, 3, 0, 4, 1, 0, 0, 5, 4, 2, 6, 7, 7, 3, 2, 4, 5, 7, 7, 6, 4, 0, 3, 7, 7, 5, 0, 1, 4, 2, 2, 4, 6 };
		}

		void Skybox::Load(const vector<string>& filenames, const string& vertexShaderFilename, const string& pixelShaderFilename)
		{
			vertexBuffer.Create(&vertcies[0], (unsigned int)vertcies.size() * sizeof(float));
			indexBuffer.Create(&indices[0], (unsigned int)indices.size() * sizeof(unsigned int));

			vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, sizeof(float) * 3, 0);
			vertexBuffer.SetLayout(vertexBufferLayout);

			shader.Load(vertexShaderFilename, pixelShaderFilename);
			textureCube.Load(filenames);
		}

		void Skybox::Render()
		{
			Engine::GetContext().EnableDepthMask(false);
			shader.Bind();
			textureCube.Bind();
			vertexBuffer.Bind();
			indexBuffer.Bind();
			Engine::GetContext().Draw((unsigned int)indices.size());
			indexBuffer.Unbind();
			vertexBuffer.Unbind();
			textureCube.Unbind();
			shader.Unbind();
			Engine::GetContext().EnableDepthMask(true);
		}
	}
}