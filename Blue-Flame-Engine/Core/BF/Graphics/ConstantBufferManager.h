#pragma once
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Materials
		{
			class MeshMaterial;
		}

		class ConstantBufferManager
		{
			struct PerFrameBuffer
			{
				BF::Math::Matrix4 viewMatrix;
				BF::Math::Matrix4 projectionMatrix;
				BF::Math::Vector4f cameraPosition;
			};

			struct PerObjectBuffer
			{
				BF::Math::Matrix4 modelMatrix;
				int index;
			};

		public:
			BF::Graphics::API::ConstantBuffer perNeedConstantBuffer;
			BF::Graphics::API::ConstantBuffer perFrameConstantBuffer;
			BF::Graphics::API::ConstantBuffer perObjectConstantBuffer;

		public:
			ConstantBufferManager();
			~ConstantBufferManager();

			void Initialize();

			/*
			Updated per need bases
			*/
			void UpdateMaterial(BF::Graphics::Materials::MeshMaterial& material);

			/*
			Updated per object bases
			*/
			void UpdateCameraModel(const BF::Math::Matrix4& modelMatrix);

			/*
			Updated per frame bases
			*/
			void UpdateCameraView(const BF::Math::Matrix4& viewMatrix);

			/*
			Updated per frame bases
			*/
			void UpdateCameraProjection(const BF::Math::Matrix4& projectionMatrix);

			/*
			Updated per object bases
			*/
			void UpdateMaterialIndex(int materialIndex);
		};
	}
}