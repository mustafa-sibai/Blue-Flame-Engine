#pragma once
#include <BF/BlueFlame.h>

class FPSCamera : public BF::Scripting::Script
{
private:
	float movmentSpeed, sensitivity, yaw, pitch;
	bool lockMouseToCenter;

public:
	BF::Math::Vector3f cameraFront, cameraUp;
	BF::Math::Vector2f windowCenter;

public:
	FPSCamera();
	~FPSCamera();

	void Start() override;
	void Update() override;
};