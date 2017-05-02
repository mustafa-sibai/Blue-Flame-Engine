#pragma once
#include <BF/BlueFlame.h>
#include <iostream>
#include <chrono>
#include <vector>

class InputTests : public BF::Application::Scene
{
public:
	InputTests();
	~InputTests();

private:
	void Initialize() override;
	void Load() override;
	void Update() override;
	//void FixedUpdate() override;
	void Render() override;
};