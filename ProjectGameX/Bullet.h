#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Bullet : public GameObject
{
protected:
    sf::Texture m_texture;
    sf::Vector2f position;
    sf::Vector2f direction;
    float speed;
    sf::Sprite m_sprite;

public:
    Bullet(sf::RenderWindow* window, const sf::Vector2f& startPos, const sf::Vector2f& dir, float bulletSpeed);
    void update(float deltaTime) override;
    void draw() override;
    sf::FloatRect getBoundingBox() const override;
};