#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Background.h"
#include "PlatformHolder.h"
#include "PhysicsEngine.h"
#include "Boss.h"
#include "CollisionManager.h"
#include "IResizable.h"

class GameWorld : public IResizable
{
public:
    GameWorld(sf::RenderWindow* window);
    ~GameWorld();

    void blur();
    void unblur();

    void update(float dt);
    void draw();

    void onResize(sf::Vector2u newSize) override;

    Player* getPlayer() { return &m_player; }
    Boss* getBoss() { return m_boss; }

private:
    sf::RenderWindow* m_window;
    sf::Vector2u m_initialWindowSize;
    sf::RectangleShape m_rectangle;

    Player m_player;
    Background m_background;
    PlatformHolder m_platformHolder;
    PhysicsEngine* m_physicsEngine;
    CollisionManager* m_collisionManager;
    Boss* m_boss;


    bool m_blurred = false;
};