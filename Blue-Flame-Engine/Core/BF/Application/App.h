#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined(BFE_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXEngineEntryPoint.h"
#elif defined(BFE_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined(BFE_PLATFORM_ANDROID)
	#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/Graphics/Animation/AnimationSystem.h"
#include "BF/Graphics/GUI3/GUISystem.h"
#include "BF/Scripting/ScriptExecutor.h"
#include "BF/AI/Astar/AstarSystem.h"
#include "BF/Graphics/Renderers/RenderPipeline.h"
#include "BF/Graphics/CameraManager.h"
#include "BF/Physics/PhysicsEngine.h"
#include "BF/System/TransformSystem.h"
#include "BF/Application/Scene.h"
#include "BF/Graphics/API/Context.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BFE_API App
		{
			friend class BF::Engine;
			friend class BF::ECS::GameObject;
			friend class BF::Application::Scene;

#ifdef BFE_PLATFORM_WINDOWS
			friend class BF::Platform::Windows::WINEngineEntryPoint;
#elif defined(BFE_PLATFORM_LINUX)
			friend class BF::Platform::Linux::LXEngineEntryPoint;
#elif defined(BFE_PLATFORM_WEB)
			friend class BF::Platform::Web::WEBEngineEntryPoint;
#elif defined(BFE_PLATFORM_ANDROID)
			friend class BF::Platform::Android::ANDEngineEntryPoint;
#endif		
		public:
			BF::Graphics::Renderers::RenderPipeline renderPipeline;

		private:
			Scene* mainScene;

			BF::Graphics::ConstantBufferManager constantBufferManager;
			BF::Graphics::CameraManager cameraManager;
			BF::System::TransformSystem transformSystem;
			BF::Physics::PhysicsEngine physicsEngine;
			BF::Graphics::Animation::AnimationSystem animationSystem;
			BF::Scripting::ScriptExecutor scriptExecutor;
			BF::Graphics::GUI::GUISystem guiSystem;
			BF::AI::Astar::AstarSystem astarSystem;

			BF::System::Timer frameTimer;
			BF::System::Timer fixedUpdateTimer;
			BF::System::Timer frameRateTimer;

			bool initialized;
			bool loaded;
			int fixedUpdateTicks;

		public:
			App();
			virtual ~App();

			virtual void Initialize();
			virtual void Load();
			virtual void PostLoad();
			virtual void Update(double deltaTime);
			virtual void Render();

			void RunScene(Scene& scene);
		};
	}
}