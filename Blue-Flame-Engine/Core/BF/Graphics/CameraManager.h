#pragma once
#include <vector>
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Graphics/Camera.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class CameraManager
		{
			friend class BF::ECS::GameObject;

		private:
			Camera* mainCamera;
			std::vector<Camera*> cameras;
			BF::Graphics::API::ConstantBuffer constantBuffer;

		public:
			CameraManager();
			~CameraManager();

			void Initialize();
			void Update();

			void SetMainCamera(Camera* camera);

			void SetModelMatrix(const BF::Math::Matrix4& modelMatrix);
			void SetViewMatrix(const BF::Math::Matrix4& viewMatrix);
			void SetProjectionMatrix(const BF::Math::Matrix4& projectionMatrix);

			void AddCamera(Camera* camera);
			void RemoveCamera();

			inline Camera& GetMainCamera() const { return *mainCamera; }
		};
	}
}