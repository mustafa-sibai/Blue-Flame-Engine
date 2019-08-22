#pragma once
#include "BF/System/TransformComponent.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class Transform : public TransformComponent<Transform>
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
			virtual ~Transform();

			void SetPosition(const BF::Math::Vector3f& position);
			void SetRotation(float angle, const BF::Math::Vector3f& rotation);
			void SetScale(const BF::Math::Vector3f& scale);

		private:
			void UpdateTransform();

		public:
			inline const BF::Math::Matrix4& GetWorldTransformation() const { return worldTransformation; }
			inline const BF::Math::Matrix4& GetTransformation() const { return transformation; }

			inline const BF::Math::Vector3f& GetWorldPosition() { return worldTransformation.GetTranslationVector(); }
			inline const BF::Math::Vector3f& GetWorldScale() { return worldTransformation.GetScaleVector(); }

			inline const BF::Math::Vector3f& GetPosition() const { return position; }
			inline const BF::Math::Vector3f& GetDirection() const { return direction; }
			inline const BF::Math::Vector3f& GetScale() const { return scale; }
		};
	}
}