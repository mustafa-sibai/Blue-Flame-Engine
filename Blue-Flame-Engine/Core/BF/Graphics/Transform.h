#pragma once
#include "BF/ECS/Component.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API Transform : public BF::ECS::Component<Transform>
		{
		private:
			BF::Math::Matrix4 worldTransformation;
			BF::Math::Matrix4 transformation;

			BF::Math::Vector3f position;
			BF::Math::Vector3f direction;
			BF::Math::Vector3f rotation;
			BF::Math::Vector3f scale;
			float angle;

		public:
			Transform();
			~Transform();

			void SetPosition(const BF::Math::Vector3f& position);
			void SetRotation(float angle, const BF::Math::Vector3f& rotation);
			void SetScale(const BF::Math::Vector3f& scale);

		private:
			void UpdateTransform();

		public:
			inline const BF::Math::Matrix4& GetWorldTransformation() const { return worldTransformation; }
			inline const BF::Math::Matrix4& GetTransformation() const { return transformation; }

			inline const BF::Math::Vector3f GetWorldPosition() { return worldTransformation.GetTranslationVector(); }
			inline const BF::Math::Vector3f GetWorldScale() { return worldTransformation.GetScaleVector(); }

			inline const BF::Math::Vector3f GetPosition() { return transformation.GetTranslationVector(); }
			inline const BF::Math::Vector3f& GetDirection() const { return direction; }
			inline const BF::Math::Vector3f GetScale() { return transformation.GetScaleVector(); }
		};
	}
}