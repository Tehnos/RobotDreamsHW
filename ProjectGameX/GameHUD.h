#pragma once
#include <SFML/Graphics.hpp>

class GameWorld;

class GameHUD
{
public:
    GameHUD(sf::RenderWindow* window, GameWorld* gameWorld);

    void update(float dt);
    void draw();

private:
    sf::RenderWindow* m_window;
    GameWorld* m_gameWorld;

    sf::Text m_playerHealthHUD;
    sf::Text m_bossHealthHUD;
    sf::Text m_shortcutsHelper;
};
