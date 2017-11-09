#pragma once
#include "BF/Math/Math.h"
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Camera
		{
			private:
				struct SystemBuffer
				{
					Math::Matrix4 modelMatrix;
					Math::Matrix4 viewMatrix;
					Math::Matrix4 projectionMatrix;
					Math::Vector4f cameraPosition;
				};

				API::ConstantBuffer constantBuffer;

			protected:
				SystemBuffer systemBuffer;
				Math::Vector3f position, direction;

			public:
				Camera();
				~Camera();

				virtual void Initialize(const Math::Matrix4& projectionMatrix);
				virtual void Update();

				void SetModelMatrix(const Math::Matrix4& modelMatrix);
				void SetViewMatrix(const Math::Matrix4& viewMatrix);
				void SetProjectionMatrix(const Math::Matrix4& projectionMatrix);

				inline const Math::Matrix4& GetSetModelMatrix() const { return systemBuffer.modelMatrix; }
				inline const Math::Matrix4& GetViewMatrix() const { return systemBuffer.viewMatrix; }
				inline const Math::Matrix4& GetProjectionMatrix() const { return systemBuffer.projectionMatrix; }
				inline const Math::Vector3f& GetPosition() const { return position; }
		};
	}
}