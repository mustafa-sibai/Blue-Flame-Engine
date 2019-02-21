#include "ConstantBufferManager.h"
#include "BF/Graphics/Materials/MeshMaterial.h"
#include "BF/Graphics/Materials/MaterialManager.h"
#include "BF/Graphics/Materials/MeshMaterialColorBuffer.h"
namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;
		using namespace BF::Graphics::Materials;

		ConstantBufferManager::ConstantBufferManager()
		{

		}

		ConstantBufferManager::~ConstantBufferManager()
		{

		}

		void ConstantBufferManager::Initialize()
		{
			perFrameConstantBuffer.Create(0, sizeof(PerFrameBuffer), nullptr);
			perNeedConstantBuffer.Create(1, sizeof(MeshMaterialColorBuffer) * BFE_MATERIAL_ARRAY_COUNT, nullptr);
			perObjectConstantBuffer.Create(2, sizeof(PerObjectBuffer), nullptr);
		}

		//TODO: For whatever reason updating the constant buffer allocates a lot of memory. investigate this out !!
		void ConstantBufferManager::UpdateMaterial(MeshMaterial& material)
		{
			perNeedConstantBuffer.Update(material.index * sizeof(MeshMaterialColorBuffer), sizeof(MeshMaterialColorBuffer), &material.colorBuffer);
		}

		void ConstantBufferManager::UpdateCameraModel(const Matrix4& modelMatrix)
		{
			perObjectConstantBuffer.Update(0, sizeof(Matrix4), &modelMatrix);
		}

		void ConstantBufferManager::UpdateCameraView(const Matrix4& viewMatrix)
		{
			perFrameConstantBuffer.Update(0, sizeof(Matrix4), &viewMatrix);
		}

		void ConstantBufferManager::UpdateCameraProjection(const Matrix4& projectionMatrix)
		{
			perFrameConstantBuffer.Update(sizeof(Matrix4), sizeof(Matrix4), &projectionMatrix);
		}

		void ConstantBufferManager::UpdateMaterialIndex(int materialIndex)
		{
			perObjectConstantBuffer.Update(sizeof(Matrix4), sizeof(int), &materialIndex);
		}
	}
}