#include "GameWorld.h"
#include "WindowManager.h"

GameWorld::GameWorld(sf::RenderWindow* window)
    : m_window(window),
    m_player(window),
    m_background(window),
    m_platformHolder(window, &m_player),
    m_physicsEngine(nullptr),
    m_collisionManager(nullptr),
    m_boss(nullptr)
{
    m_boss = new Boss(window);
    m_boss->setPlayer(&m_player);
    WindowManager::getInstance().registerResizable(m_boss);
    m_physicsEngine = new PhysicsEngine(&m_player, m_platformHolder.getPlatforms(), m_boss);
    m_collisionManager = new CollisionManager(m_player, *m_boss, m_platformHolder.getPlatforms());

    m_rectangle.setFillColor(sf::Color(255, 255, 255, 150));
    m_rectangle.setSize(sf::Vector2f(window->getSize()));
    m_initialWindowSize = window->getSize();

    WindowManager::getInstance().registerResizable(this);
}

GameWorld::~GameWorld()
{
    delete m_boss;
    delete m_physicsEngine;
    delete m_collisionManager;
    WindowManager::getInstance().unregisterResizable(this);
}

void GameWorld::blur()
{
    m_blurred = true;
}

void GameWorld::unblur()
{
    m_blurred = false;
}

void GameWorld::update(float dt)
{
    m_player.update(dt);
    m_platformHolder.update(dt);
    m_physicsEngine->update(dt);
    m_collisionManager->checkCollisions(dt);
    m_collisionManager->updateBullets(dt);
    m_boss->update(dt);
}

void GameWorld::draw()
{
    m_window->clear(sf::Color(0, 255, 0));

    m_background.draw();
    m_platformHolder.draw();
    m_player.draw();
    m_boss->draw();
    m_collisionManager->drawBullets();

    if (m_blurred)
    {
        m_window->draw(m_rectangle);
    }
}

void GameWorld::onResize(sf::Vector2u newSize)
{
    sf::View view;
    view.setSize({ static_cast<float>(newSize.x), static_cast<float>(newSize.y) });
    view.setCenter({ static_cast<float>(newSize.x) / 2.f, static_cast<float>(newSize.y) / 2.f });
    m_window->setView(view);
    m_player.handleResize();
    m_platformHolder.handleResize(m_window);
    m_rectangle.setSize({ static_cast<float>(newSize.x), static_cast<float>(newSize.y) });
    m_initialWindowSize = newSize;
}