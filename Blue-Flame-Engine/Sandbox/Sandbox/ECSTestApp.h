#pragma once
#include <BF/BlueFlame.h>

namespace ECSTestApp
{
	class ECSTestApp : public BF::Application::App
	{
		private:
			BF::Graphics::Camera camera;
			BF::Application::Scene* scene;

			//BF::Graphics::GUI::MenuStrip::MenuItem* exitItem;

		public:
			ECSTestApp();
			~ECSTestApp();

		public:
			void Initialize() override;
			void Load() override;
			void Update() override;
			void Render() override;
	};
}