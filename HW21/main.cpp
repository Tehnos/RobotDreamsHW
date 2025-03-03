#include <iostream>
#include <algorithm>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Player.h"



bool handleCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2)
{
    sf::FloatRect box1 = sprite1.getGlobalBounds();
    sf::FloatRect box2 = sprite2.getGlobalBounds();

    if (std::optional intersectedBox = box1.findIntersection(box2))
    {
        return true;
    }

    return false;
}


bool isFullscreen = false;

int main()
{
    sf::VideoMode setup({ 1920,1080 }, 32);
    sf::RenderWindow window(setup, "Doodle Jump, pt.2");
    window.setFramerateLimit(60);

    Background background(&window);
    Player player(&window);

    sf::Clock frameRateClock;
    //Game loop
    while (window.isOpen())
    {
        const float dt = frameRateClock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() ||
                (event->is<sf::Event::KeyPressed>() &&
                    event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape))
            {
                window.close();
            }
            if (event->is<sf::Event::KeyPressed>())
            {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::F11)
                {
                    isFullscreen = !isFullscreen;
                    window.close();
                    window.create(isFullscreen?sf::VideoMode::getDesktopMode():setup, "Doodle Jump, pt.2", isFullscreen?sf::State::Fullscreen:sf::State::Windowed);
                    sf::VideoMode newVideoMode(window.getSize());
                    player.handleResize(newVideoMode);
                    sf::View newView(sf::FloatRect({ 0, 0 }, { static_cast<float>(window.getSize().x),static_cast<float>(window.getSize().y)}));
                    window.setView(newView);
                    background.resize(window.getSize());
                }
            }
            if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                sf::VideoMode newVideoMode({ resized->size.x, resized->size.y });
                player.handleResize(newVideoMode);

                sf::View newView(sf::FloatRect({ 0, 0 }, { static_cast<float>(resized->size.x), static_cast<float>(resized->size.y) }));
                window.setView(newView);
                background.resize(resized->size);
            }


        }

        //UPDATE STEP
        player.update(dt);

        //DRAW STEP
        window.clear(sf::Color{ 0, 255, 0 });
        background.draw();
        player.draw();

        //DISPLAY STEP
        window.display();
    }

    return 0;
}
