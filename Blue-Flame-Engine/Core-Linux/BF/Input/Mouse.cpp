#if 0
#include "Mouse.h"

namespace BFE
{
	namespace Input
	{
		Vector2 *Mouse::Position{ 0 };

		inline const Vector2 Mouse::GetPosition()
		{
			if (Mouse::Position == nullptr)
				return Vector2(0);
			else
				return *Position;
		}
	}
}
#endif