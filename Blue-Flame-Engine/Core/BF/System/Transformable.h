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
		class TransformThreadWorker;

		class BFE_API Transformable
		{
			friend class BF::System::TransformThreadWorker;
			friend class BF::Graphics::Renderers::SpriteRendererComponents::IRenderable;

		protected:
			enum class Type { SpriteRendererTransform, MeshRendererTransform, PhysicsTransform };
			Type type;

			bool updatePivotAndSize;

		public:
			Transformable(Type type);
			~Transformable();
		};
	}
}