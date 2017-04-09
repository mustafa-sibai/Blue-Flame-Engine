#pragma once
#include <BF/Application/Scene.h>
#include <BF/System/Log.h>

class AndroidTestScene : public BF::Application::Scene
{
public:
	AndroidTestScene();
	~AndroidTestScene();

private:
	void Initialize() override;
	void Load() override;
	void Update() override;
	void FixedUpdate() override;
	void Render() override;
};