#pragma once
#include "BF/ECS/ISystem.h"
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BFE_API TransformSystem : public BF::ECS::ISystem
		{
		public:
			TransformSystem();
			~TransformSystem();

			void Initialize()			  override;
			void Load()					  override;
			void PostLoad()				  override;
			void Update(double deltaTime) override;
			void Render()				  override;
		};
	}
}