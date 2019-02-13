#pragma once
#include <BF/BlueFlame.h>

class ScriptTest : public BF::Scripting::Script<ScriptTest>
{
private:
	float xPosition;

public:
	ScriptTest();
	~ScriptTest();

	void Start() override;
	void Update() override;
};