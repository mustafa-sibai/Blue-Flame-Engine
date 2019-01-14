#pragma once
#include <BF/BlueFlame.h>

class ScriptTest : public BF::Scripting::Script
{
private:
	float xPosition;

public:
	ScriptTest();
	~ScriptTest();

	void Start() override;
	void Update() override;
};