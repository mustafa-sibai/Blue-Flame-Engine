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
		class BFE_API Camera : public BF::ECS::Component
		{
			friend class CameraManager;
			friend class BF::ECS::GameObject;

		private:
			struct SystemBuffer
			{
				BF::Math::Matrix4 modelMatrix;
				BF::Math::Matrix4 viewMatrix;
				BF::Math::Matrix4 projectionMatrix;
				BF::Math::Vector4f cameraPosition;
			};

			BF::Graphics::CameraManager* cameraManager;
			BF::Graphics::API::BufferClearType bufferClearType;
			BF::Graphics::Color clearColor;

		protected:
			SystemBuffer systemBuffer;
			BF::Math::Vector3f position, direction;

		public:
			Camera(const BF::Math::Matrix4& projectionMatrix);
			virtual ~Camera();

			void SetAsMainCamera();
			void SetClearType(BF::Graphics::API::BufferClearType bufferClearType);
			void SetClearColor(const BF::Graphics::Color& clearColor);

			void Clear();
			void SwapBuffers();

			inline const BF::Math::Matrix4& GetSetModelMatrix() const { return systemBuffer.modelMatrix; }
			inline const BF::Math::Matrix4& GetViewMatrix() const { return systemBuffer.viewMatrix; }
			inline const BF::Math::Matrix4& GetProjectionMatrix() const { return systemBuffer.projectionMatrix; }
			inline const BF::Math::Vector3f& GetPosition() const { return position; }
		};
	}
}