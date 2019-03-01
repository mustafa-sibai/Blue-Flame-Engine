#pragma once
#include <BF/BlueFlame.h>

namespace IsoMapTest
{
	class IsoMapTest : public BF::Application::App
	{
	private:
		BF::Application::Scene* scene;
		BF::Graphics::Camera* camera;
		BF::Math::Rectangle orthographicRectangle;

	public:
		IsoMapTest();
		~IsoMapTest();

		void Initialize() override;
		void Load() override;
		void PostLoad() override;
		void Update() override;
		void Render() override;
	};
}