#pragma once
#include <BF/BlueFlame.h>

class ScriptTest : public BF::Scripting::Script
{
public:
	ScriptTest();
	~ScriptTest();

	void Start() override;
	void Update() override;
};