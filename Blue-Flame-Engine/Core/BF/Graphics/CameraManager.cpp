#include "CameraManager.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;
		using namespace BF::Graphics;

		CameraManager::CameraManager() :
			mainCamera(nullptr)
		{
		}

		CameraManager::~CameraManager()
		{
		}

		void CameraManager::Initialize()
		{
			constantBuffer.Create(0, sizeof(Camera::SystemBuffer), nullptr);
		}

		void CameraManager::Update()
		{
			if(mainCamera != nullptr)
				constantBuffer.Update(0, sizeof(Camera::SystemBuffer), &mainCamera->systemBuffer);
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

		void CameraManager::SetModelMatrix(const Matrix4& modelMatrix)
		{
			mainCamera->systemBuffer.modelMatrix = modelMatrix;
			constantBuffer.Update(0, sizeof(Camera::SystemBuffer), &mainCamera->systemBuffer);
		}

		void CameraManager::SetViewMatrix(const Matrix4& viewMatrix)
		{
			mainCamera->systemBuffer.viewMatrix = viewMatrix;
			constantBuffer.Update(0, sizeof(Camera::SystemBuffer), &mainCamera->systemBuffer);
		}

		void CameraManager::SetProjectionMatrix(const Matrix4& projectionMatrix)
		{
			mainCamera->systemBuffer.projectionMatrix = projectionMatrix;
			constantBuffer.Update(0, sizeof(Camera::SystemBuffer), &mainCamera->systemBuffer);
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
	}
}