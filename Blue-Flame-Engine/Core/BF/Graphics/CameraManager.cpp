#include "CameraManager.h"
#include "BF/ECS/GameObject.h"
#include "BF/System/Debug.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;
		using namespace BF::Graphics;

		CameraManager::CameraManager(BF::Graphics::ConstantBufferManager& constantBufferManager) :
			constantBufferManager(constantBufferManager), mainCamera(nullptr)
		{
		}

		CameraManager::~CameraManager()
		{
		}

		void CameraManager::Update(double deltaTime)
		{
			if (mainCamera != nullptr)
			{
				Vector3f position = mainCamera->gameObject->GetTransform()->GetWorldPosition();
				mainCamera->viewMatrix = Matrix4::LookAt(position, position + Vector3f::Forward(), Vector3f::Up());

				constantBufferManager.UpdateCameraView(mainCamera->viewMatrix);
				constantBufferManager.UpdateCameraProjection(mainCamera->projectionMatrix);
			}
		}

		void CameraManager::SetMainCamera(Camera* camera)
		{
			bool found = false;

			for (size_t i = 0; i < cameras.size(); i++)
			{
				if (cameras[i] == camera)
					found = true;
			}

			if (found || cameras.size() <= 0)
			{
				mainCamera = camera;
			}
			else
			{
				BFE_LOG_ERROR("Could not find the camera in cameras list, therefore camera will not be set as the main camera", "");
			}
		}

		void CameraManager::AddCamera(Camera* camera)
		{
			if (cameras.size() <= 0)
				SetMainCamera(camera);

			cameras.emplace_back(camera);
		}

		void CameraManager::RemoveCamera()
		{
		}
		void CameraManager::Initialize()
		{
		}
		void CameraManager::Load()
		{
		}
		void CameraManager::PostLoad()
		{
		}
		void CameraManager::Render()
		{
		}
	}
}