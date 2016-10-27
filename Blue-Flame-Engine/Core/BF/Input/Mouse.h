#pragma once
#include "BF/Math/Vector2.h"
#include "BF/Platform/Windows/WINWindow.h"

namespace BF
{
	namespace Input
	{
		class BF_API Mouse
		{
			private:
				friend class BF::Platform::Windows::WINWindow;

			private:
				static Math::Vector2 Position;

			public:
				Mouse();
				~Mouse();

			public:
				inline static Math::Vector2 GetPosition() { return Position; }
		};
	}
}