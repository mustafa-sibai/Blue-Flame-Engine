#pragma once
#include <string>
#include <vector>
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Graphics
	{
		namespace Renderers
		{
			class RenderPipeline;
			class SpriteRenderer;
		}
	}

	namespace ECS
	{
		class GameObject;

		class BFE_API IComponent
		{
			friend class BF::Application::Scene;
			friend class BF::ECS::GameObject;
			friend class BF::Graphics::Renderers::RenderPipeline;
			friend class BF::Graphics::Renderers::SpriteRenderer;

		private:
			static int globalID;
			int id;
			bool added;

		protected:
			std::vector<std::string> types;

			template <typename T>
			bool IsSameType();

			template<typename T>
			static bool CompareTypes(const std::string& type);

			//inline std::string GetType() const { return IComponentType; }

		public:
			GameObject* gameObject;

		public:
			IComponent();
			virtual ~IComponent();

			template <typename T>
			static std::string TypeOf();

			inline int GetID() const { return id; }
		};

#include "IComponent.inl"
	}
}