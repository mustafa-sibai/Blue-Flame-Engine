#pragma once
#include "BF/ECS/Component.h"
#include "BF/Math/Math.h"
#include "BF/Graphics/API/ConstantBuffer.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Graphics/Color.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API Camera : public BF::ECS::Component
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
				Camera(const BF::Math::Matrix4& projectionMatrix);
				virtual ~Camera();

				virtual void Initialize();

				void SetModelMatrix(const BF::Math::Matrix4& modelMatrix);
				void SetViewMatrix(const BF::Math::Matrix4& viewMatrix);
				void SetProjectionMatrix(const BF::Math::Matrix4& projectionMatrix);

				inline const BF::Math::Matrix4& GetSetModelMatrix() const { return systemBuffer.modelMatrix; }
				inline const BF::Math::Matrix4& GetViewMatrix() const { return systemBuffer.viewMatrix; }
				inline const BF::Math::Matrix4& GetProjectionMatrix() const { return systemBuffer.projectionMatrix; }
				inline const BF::Math::Vector3f& GetPosition() const { return position; }
			
			public:
				virtual void Update();

				void Clear(BF::Graphics::API::BufferClearType bufferClearType, const BF::Graphics::Color& color);
				void SwapBuffers();
		};
	}
}