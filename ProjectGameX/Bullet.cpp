#include "Bullet.h"


Bullet::Bullet(sf::RenderWindow* window, const sf::Vector2f& startPos, const sf::Vector2f& dir, float bulletSpeed)
    : GameObject(window)
    , m_texture("resources/bullet.png")
    , m_sprite(m_texture)
    , position(startPos)
    , direction(dir)
    , speed(bulletSpeed)
{
    m_sprite.setTextureRect(sf::IntRect{ {0, 0}, {40, 20} });
    m_sprite.setOrigin({
        m_sprite.getLocalBounds().size.x / 2.0f,
        m_sprite.getLocalBounds().size.y / 2.0f
        });

    m_sprite.setScale({ 1.0f, 1.0f });
    m_texture.setSmooth(true);

    m_sprite.setPosition(position);
}

void Bullet::update(float deltaTime)
{
    position += direction * speed * deltaTime;
    m_sprite.setPosition(position);
}

void Bullet::draw()
{
    m_window->draw(m_sprite);
}

sf::FloatRect Bullet::getBoundingBox() const
{
    return m_sprite.getGlobalBounds();
}
