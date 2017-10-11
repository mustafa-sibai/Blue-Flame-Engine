#pragma once
#include <BF/BlueFlame.h>

namespace PhysicsScene
{
	class PhysicsScene : public BF::Application::Scene
	{
		private:
			BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
			BF::Graphics::Camera camera;


			BF::Graphics::Renderers::RegularPolygon floor;
			BF::Physics::Rigidbody2D floorRigidbody2D;

			BF::Graphics::Renderers::RegularPolygon box;
			BF::Physics::Rigidbody2D boxRigidbody2D;

		public:
			PhysicsScene();
			~PhysicsScene();

		private:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void Render() override;
	};
}