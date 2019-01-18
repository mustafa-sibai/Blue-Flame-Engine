#pragma once
#include <vector>
#include "BF/Math/Math.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace AI
	{
		class BFE_API Waypoint
		{
		public:
			class Node
			{
				friend class Waypoint;

				private:
					Math::Vector2f position;
					bool arrived;

				public:
					Node() = default;
					Node(Math::Vector2f position) : position(position), arrived(false) { }

					inline bool HasArrived() const { return arrived; }
			};

		private:
			Graphics::Renderers::Sprite& sprite;
			std::vector<Node>& waypoints;

			Node* previousNode;

			Math::Vector2f position;
			Math::Vector2f direction;
			unsigned int currentIndex;
			float length;
			bool reachedFinalWaypoint;

		public:
			Waypoint(Graphics::Renderers::Sprite& sprite, std::vector<Node>& waypoint);
			~Waypoint();

			void GoTo(Node& node);
			void GoTo(Node&&) = delete;
			void Update();

			inline unsigned int GetCurrentIndex() const { return currentIndex; }

		private:
			void MoveTo(Node& node);

		};
	}
}