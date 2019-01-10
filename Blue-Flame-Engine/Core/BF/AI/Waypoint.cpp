#include "Waypoint.h"

namespace BF
{
	namespace AI
	{
		Waypoint::Waypoint(Graphics::Renderers::Sprite& sprite, std::vector<Node>& waypoints) :
			sprite(sprite), waypoints(waypoints), currentIndex(0), reachedFinalWaypoint(false), length(0)
		{
		}

		Waypoint::~Waypoint()
		{
		}

		void Waypoint::GoTo(Node& node)
		{
			MoveTo(node);
		}

		void Waypoint::MoveTo(Node& node)
		{
			//if (previousNode != &node && previousNode != nullptr)
				//previousNode->arrived = false;

			/*if (!node.arrived)
			{
				direction = node.position - sprite.GetPosition();
				length = direction.Magnitude();

				if (length > 1.0f)
				{
					position += direction.Normalize();
					sprite.SetPosition(position * 0.25f);
				}
				else
				{
					node.arrived = true;
					previousNode = &node;
					sprite.SetPosition(node.position);
				}
			}*/
		}

		void Waypoint::Update()
		{
			/*direction = waypoints[currentIndex].position - sprite.GetPosition();
			length = direction.Magnitude();

			if (length > 1.0f)
			{
				position += direction.Normalize();
				sprite.SetPosition(position * 0.25f);
			}
			else
			{
				waypoints[currentIndex].arrived = true;

				if (currentIndex < waypoints.size() - 1)
				{
					if (waypoints[currentIndex].arrived)
						currentIndex++;
				}
				else
				{
					sprite.SetPosition(waypoints[currentIndex].position);
				}*/


				/*if (!loop &&      
				{
					sprite.SetPosition(waypoints[currentIndex].position);
					currentIndex = waypoints.size() - 1;
					reachedFinalWaypoint = true;
				}

				if (loop && currentIndex == waypoints.size() - 1)
					currentIndex = 0;*/
			//}
		}

	}
}