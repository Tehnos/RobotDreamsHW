#pragma once

class GameConfig
{
public:
	static constexpr bool AutoJump = false;
	static constexpr float JumpImpulse = -900.0f;
	static constexpr float GravityAcceleration = 1200.0f;

	static constexpr float PlatformsMovementSpeed = 0.0f;

	static constexpr float PlatformHeight = 30.0f;
	static constexpr float PlatformWidth = 100.0f;
};
