#pragma once
#include <SFML/Graphics.hpp>
#include "FontManager.h"
#include "GameWorld.h"
#include "IResizable.h"

class GameHUD : public IResizable
{
public:
    GameHUD(sf::RenderWindow* window, GameWorld* gameWorld);
    ~GameHUD();

    void update(float dt);
    void draw();
    void onResize(sf::Vector2u newSize) override;

private:
    void updateHealthTextPositions();

    sf::RenderWindow* m_window;
    GameWorld* m_gameWorld;

    sf::Text m_playerHealthHUD;
    sf::Text m_bossHealthHUD;

    sf::RectangleShape m_playerHealthBarBackground;
    sf::RectangleShape m_playerHealthBar;
    sf::Text m_playerHealthText;

    sf::RectangleShape m_bossHealthBarBackground;
    sf::RectangleShape m_bossHealthBar;
    sf::Text m_bossHealthText;
};