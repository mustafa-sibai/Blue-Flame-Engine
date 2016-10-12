#include "Model.h"

namespace BF
{
	namespace Graphics
	{
		Model::Model(API::Context *context, API::Shader *shader) :
			context(context), shader(shader)
		{
			objReader = new IO::OBJReader();
		}

		Model::~Model()
		{
		}

		void Model::Load(const char *fileName)
		{
			meshes = objReader->Load(fileName);

			for (size_t i = 0; i < meshes->size(); i++)
				meshes[0][i].SetBuffers(context, shader);
		}

		void Model::Draw()
		{
			for (size_t i = 0; i < meshes->size(); i++)
			{
				meshes[0][i].Bind();
				context->Draw((unsigned int)meshes[0][i].GetIndices()->size());
				meshes[0][i].Unbind();
			}
		}
	}
}