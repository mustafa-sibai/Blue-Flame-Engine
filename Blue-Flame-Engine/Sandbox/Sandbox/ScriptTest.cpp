#include "ScriptTest.h"
#include <iostream>

ScriptTest::ScriptTest() :
	xPosition(0)
{
}

ScriptTest::~ScriptTest()
{
}

void ScriptTest::OnTriggerEnter(BF::Physics::ICollider& other)
{
	std::cout << gameObject->Name + " collided with " + other.gameObject->Name << std::endl;
}

void ScriptTest::Start()
{
	//std::cout << "This is the test Script. It is exceuting the Start function. " << std::endl;
}

void ScriptTest::Update()
{
	//std::cout << "This is the test Script. It is exceuting the Update function. " << std::endl;

	//xPosition = this->gameObject->GetTransform()->GetPosition().x + 0.01f;
	//this->gameObject->GetTransform()->SetPosition(BF::Math::Vector3f(xPosition, xPosition, 0));
}