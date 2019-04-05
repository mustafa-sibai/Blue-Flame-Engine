#pragma once
#include "BF/ECS/Component.h"
#include "BF/Math/Math.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Graphics/Color.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API Camera : public BF::ECS::Component<Camera>
		{
			friend class CameraManager;
			friend class BF::ECS::GameObject;

		private:
			BF::Graphics::CameraManager* cameraManager;
			BF::Graphics::API::BufferClearType bufferClearType;
			BF::Graphics::Color clearColor;

		protected:
			BF::Math::Matrix4 modelMatrix;
			BF::Math::Matrix4 viewMatrix;
			BF::Math::Matrix4 projectionMatrix;
			BF::Math::Vector4f cameraPosition;
			BF::Math::Vector3f position, direction;

		public:
			BF::Math::Vector2f size;

		public:
			Camera(const BF::Math::Matrix4& projectionMatrix);
			virtual ~Camera();

			void SetAsMainCamera();
			void SetClearType(BF::Graphics::API::BufferClearType bufferClearType);
			void SetClearColor(const BF::Graphics::Color& clearColor);

			void SetModelMatrix(const BF::Math::Matrix4& modelMatrix);
			void SetViewMatrix(const BF::Math::Matrix4& viewMatrix);
			void SetProjectionMatrix(const BF::Math::Matrix4& projectionMatrix);

			static BF::Math::Vector3f ScreenToWorldPoint(const BF::Math::Vector3f& position, const BF::Math::Vector2f& pivot);

			void Clear();
			void SwapBuffers();

			inline const BF::Math::Matrix4& GetSetModelMatrix() const { return modelMatrix; }
			inline const BF::Math::Matrix4& GetViewMatrix() const { return viewMatrix; }
			inline const BF::Math::Matrix4& GetProjectionMatrix() const { return projectionMatrix; }
			inline const BF::Math::Vector3f& GetPosition() const { return position; }
		};
	}
}