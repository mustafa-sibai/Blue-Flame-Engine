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
					BF::Math::Matrix4 modelMatrix;
					BF::Math::Matrix4 viewMatrix;
					BF::Math::Matrix4 projectionMatrix;
					BF::Math::Vector4f cameraPosition;
				};

				API::ConstantBuffer constantBuffer;

			protected:
				SystemBuffer systemBuffer;
				BF::Math::Vector3f position, direction;

			public:
				Camera();
				virtual ~Camera();

				virtual void Initialize(const BF::Math::Matrix4& projectionMatrix);

				void SetModelMatrix(const BF::Math::Matrix4& modelMatrix);
				void SetViewMatrix(const BF::Math::Matrix4& viewMatrix);
				void SetProjectionMatrix(const BF::Math::Matrix4& projectionMatrix);

				inline const BF::Math::Matrix4& GetSetModelMatrix() const { return systemBuffer.modelMatrix; }
				inline const BF::Math::Matrix4& GetViewMatrix() const { return systemBuffer.viewMatrix; }
				inline const BF::Math::Matrix4& GetProjectionMatrix() const { return systemBuffer.projectionMatrix; }
				inline const BF::Math::Vector3f& GetPosition() const { return position; }
			
			public:
				virtual void Update();
		};
	}
}