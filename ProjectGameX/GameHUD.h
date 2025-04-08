#pragma once
#include <SFML/Graphics.hpp>
#include "Iresizable.h"
#include "WindowManager.h"

class GameWorld;

class GameHUD:public IResizable
{
public:
    GameHUD(sf::RenderWindow* window, GameWorld* gameWorld);

    ~GameHUD();

    void update(float dt);
    void draw();

    void onResize(sf::Vector2u newSize) override;
private:
    sf::RenderWindow* m_window;
    GameWorld* m_gameWorld;

    sf::Text m_playerHealthHUD;
    sf::Text m_bossHealthHUD;
};
