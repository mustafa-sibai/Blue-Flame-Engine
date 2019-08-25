#pragma once
#include <vector>
#include "BF/System/Transform.h"
#include "BF/ECS/ISystem.h"
#include "BF/Common.h"
#include "BF/System/RenderableTransform.h"

namespace BF
{
	namespace Application
	{
		class App;
	}
	namespace ECS
	{
		class GameObject;
	}

	namespace System
	{
		class BFE_API TransformSystem : public BF::ECS::ISystem
		{
			friend class BF::Application::App;
			friend class BF::ECS::GameObject;
			friend class BF::Application::Scene;

		private:
			std::vector<Transform*> transforms;
			std::vector<Transformable*> transformable;

		public:
			TransformSystem();
			~TransformSystem();

		private:
			void Initialize()			  override;
			void Load()					  override;
			void PostLoad()				  override;
			void Update(double deltaTime) override;
			void Render()				  override;

			void AddTransform(Transform* transform);
			void RemoveTransform(Transform* transform);
		};
	}
}