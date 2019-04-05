#pragma once
#include <BF/BlueFlame.h>

namespace Hello_Triangle
{
	class Hello_Triangle : public BF::Application::App
	{
		private:
			BF::Application::Scene* scene;

			BF::Graphics::Model* planeModel;

			BF::Math::Vector3f position;

		public:
			Hello_Triangle();
			~Hello_Triangle();

			void Initialize() override;
			void Load() override;
			void PostLoad() override;
			void Update(double deltaTime) override;
			void Render() override;
	};
}