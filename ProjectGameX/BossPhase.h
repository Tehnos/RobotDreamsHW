#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "SoundManager.h"
#include "Boss.h"
#include <cstdlib>

class Boss;

class BossPhase {
public:
    virtual ~BossPhase() = default;
    virtual void onEnter(Boss& boss) = 0;
    virtual void update(Boss& boss, float dt) = 0;
    virtual void onExit(Boss& boss) = 0;
};

class BossPhase1 : public BossPhase {
public:
    void onEnter(Boss& boss) override;
    void update(Boss& boss, float dt) override;
    void onExit(Boss& boss) override;
private:
    sf::Clock m_shootClock;
};

class BossPhase2 : public BossPhase {
public:
    void onEnter(Boss& boss) override;
    void update(Boss& boss, float dt) override;
    void onExit(Boss& boss) override;
private:
    sf::Clock m_shootClock;
};

class BossPhase3 : public BossPhase {
public:
    void onEnter(Boss& boss) override;
    void update(Boss& boss, float dt) override;
    void onExit(Boss& boss) override;
private:
    sf::Clock m_shootClock;
};