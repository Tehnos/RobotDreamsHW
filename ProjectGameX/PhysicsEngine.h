#pragma once
#include "Player.h"
#include "PlatformHolder.h"
#include "Boss.h"

class PhysicsEngine
{
public:
	PhysicsEngine(Player* player, std::vector<Platform*>& platforms, Boss* boss = nullptr);
	void update(float dt);
private:
	Player* m_player;
	std::vector<Platform*>& m_platforms;
	Boss* m_boss;
};