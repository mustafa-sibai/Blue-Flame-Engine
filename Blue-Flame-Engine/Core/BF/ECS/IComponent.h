#pragma once
#include <string>
#include <vector>
#include <typeinfo>
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

		namespace GUI
		{
			class GUISystem;
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
			friend class BF::Graphics::GUI::GUISystem;

		private:
			static int globalID;
			int id;
			bool added;

		protected:
			enum class Type { None, Transform, Physics, Camera, Widget, Animator, Renderable, Model, Script, Astar };
			Type type;

			std::vector<size_t> types;

			template <typename T>
			bool IsSameType();

			template<typename T>
			static bool CompareTypes(const size_t& type);

			//inline std::string GetType() const { return IComponentType; }

		public:
			GameObject* gameObject;

		public:
			IComponent(Type type);
			virtual ~IComponent();

			template <typename T>
			static const size_t& TypeOf();

			inline int GetID() const { return id; }
		};

#include "IComponent.inl"
	}
}