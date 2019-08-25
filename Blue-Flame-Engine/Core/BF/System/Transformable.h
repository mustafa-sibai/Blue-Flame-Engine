#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				class IRenderable;
			}
		}
	}

	namespace System
	{
		class TransformSystem;

		class BFE_API Transformable
		{
			friend class BF::System::TransformSystem;
			friend class BF::Graphics::Renderers::SpriteRendererComponents::IRenderable;

		protected:
			enum class Type { SpriteRendererTransform, MeshRendererTransform, PhysicsTransform };
			Type type;

			bool update;

		public:
			Transformable(Type type);
			~Transformable();
		};
	}
}