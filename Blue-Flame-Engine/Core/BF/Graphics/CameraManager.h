#pragma once
#include <vector>
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/ConstantBufferManager.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class CameraManager
		{
			friend class BF::ECS::GameObject;

		private:
			BF::Graphics::ConstantBufferManager& constantBufferManager;
			BF::Graphics::Camera* mainCamera;
			std::vector<Camera*> cameras;

		public:
			CameraManager(BF::Graphics::ConstantBufferManager& constantBufferManager);
			~CameraManager();

			void Update();

			void SetMainCamera(BF::Graphics::Camera* camera);

			void SetModelMatrix(const BF::Math::Matrix4& modelMatrix);
			void SetViewMatrix(const BF::Math::Matrix4& viewMatrix);
			void SetProjectionMatrix(const BF::Math::Matrix4& projectionMatrix);

			void AddCamera(BF::Graphics::Camera* camera);
			void RemoveCamera();

			inline Camera& GetMainCamera() const { return *mainCamera; }
		};
	}
}