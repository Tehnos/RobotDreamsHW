#pragma once
#include <vector>
#include "Player.h"
#include "Boss.h"
#include "Platform.h"

class CollisionManager {
public:
    CollisionManager(Player& player, Boss& boss, std::vector<Platform*>& platforms);
    void checkCollisions(float dt);
    void updateBullets(float dt);
    void drawBullets();
private:
    Player& m_player;
    Boss& m_boss;
    std::vector<Platform*>& m_platforms;

    void checkPlayerBossCollisions();
    void checkPlayerBulletsWithBoss();
    void checkBossBulletsWithPlayer();
    void checkPlayerWithPlatforms();
};