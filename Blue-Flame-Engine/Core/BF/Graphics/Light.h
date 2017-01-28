#pragma once
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API Light
		{
		private:
			Math::Vector3 position;
			Math::Vector4 color;

		public:
			Light();
			~Light();

			void SetLight(Math::Vector3 position, Math::Vector4 color);

			inline const Math::Vector3& GetPosition() const { return position; }
			inline const Math::Vector4& GetColor() const { return color; }
		};
	}
}