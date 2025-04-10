#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include "Player.h"
#include "Background.h"
#include "Platform.h"
#include "PlatformHolder.h"
#include "PhysicsEngine.h"
#include "SoundManager.h"
#include "GameHUD.h"
#include "GameWorld.h"
#include "GameStateManager.h"
#include "GameState.h"
#include "Boss.h"
#include "WindowManager.h"

void handleWindowEvents(sf::RenderWindow& window, GameStateManager& gameStateManager)
{
    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        if (auto keyPressedEvent = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressedEvent->code == sf::Keyboard::Key::Numpad3)
            {
                window.close();
            }
        }
        if (const auto* resized = event->getIf<sf::Event::Resized>())
        {
            WindowManager::getInstance().handleResizeEvent(*resized);
            gameStateManager.handleResize({ resized->size.x, resized->size.y });
        }
    }
}


int main()
{
    GameOptions::getInstance().loadSettings();
    sf::RenderWindow window(sf::VideoMode{ {1920, 1080} }, "ProjectGameX");
    WindowManager::getInstance().initialize(&window);
    //window.setFramerateLimit(560);
    GameOptions::getInstance().applyVideoSettings(window);
    sf::Clock mainClock;

    GameWorld gameWorld(&window);
    GameStateManager gameStateManager(&gameWorld, GameStateId::TitleScreen, &window);
    SoundManager::getInstance().playInGameMusic();
    GameHUD gameHud(&window, &gameWorld);

    while (window.isOpen())
    {
        const float dt = mainClock.restart().asSeconds();

        handleWindowEvents(window, gameStateManager);

        //UPDATE STEP
        gameStateManager.update(dt);
        if (gameStateManager.getCurrentStateId() == GameStateId::Playing)
        {
            gameHud.update(dt);
        }

        //DRAW STEP
        gameStateManager.draw();
        if (gameStateManager.getCurrentStateId() == GameStateId::Playing)
        {
            gameHud.draw();
        }

        //DISPLAY STEP
        window.display();
    }

    return 0;
}