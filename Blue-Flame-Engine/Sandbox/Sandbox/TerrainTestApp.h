#pragma once
#include <BF/BlueFlame.h>

class TerrainTestApp : public BF::Application::App
{
	private:
		BF::Application::Scene* scene;

		BF::Graphics::FPSCamera fpsCamera;

		BF::Graphics::LightBuffer light;
		BF::Graphics::API::ConstantBuffer constantBuffer;

		BF::Graphics::Materials::MeshMaterial terrainMaterial;
		BF::Graphics::API::ConstantBuffer materialConstantBuffer;

		BF::Graphics::Terrain terrain;

	public:
		TerrainTestApp();
		~TerrainTestApp();

	public:
		void Initialize() override;
		void Load() override;
		void Update() override;
		void Render() override;
};