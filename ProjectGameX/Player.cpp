#include "Player.h"
#include "Platform.h"
#include "GameConfig.h"
#include "SoundManager.h"
#include "Bullet.h"
#include "Boss.h"

constexpr AnimationSettings PlayerAnimationSettings = { 350, 128, 5 , 0.1f, "resources/dino_rex_move.png" };
constexpr float SPEED_X = 800.0f;
constexpr float MaxSpeed = 900.0f;

Player::Player(sf::RenderWindow* window)
    : GameObject(window),
    m_texture("resources/doodle.png"),
    m_sprite(m_texture),
    m_animator(PlayerAnimationSettings),
    m_cooldownSec(0.3f),
    m_BulletcooldownSec(0.2f),
    m_health(100),
    m_isOnGround(false)
{
    getSpriteImpl().setOrigin({ getSpriteImpl().getLocalBounds().size.x / 2.0f, getSpriteImpl().getLocalBounds().size.y / 2.0f });
    getSpriteImpl().setScale({ 1.2f, 1.2f });

    const sf::Vector2u windowSize = m_window->getSize();
    getSpriteImpl().setPosition(sf::Vector2f{ 0.0f + getSpriteImpl().getLocalBounds().size.x / 2 ,windowSize.y - getSpriteImpl().getGlobalBounds().size.y / 2 });

    m_position = getSpriteImpl().getPosition();
    m_orientation = PlayerOrientation::Right;
    m_cooldownTimer.restart();
}

void Player::update(float dt)
{
    handleInput(dt);
    physicsUpdate(dt);
    orientationUpdate();
    getSpriteImpl().setPosition(m_position);
    m_isOnGround = false;
    DistanceTracker::setPlayerHeightOnScreen(m_window->getSize().y - m_position.y);
    m_animator.update(dt);
    handleResize();
}

void Player::draw()
{
    m_window->draw(getSpriteImpl());
}

sf::FloatRect Player::getBoundingBox() const
{
    return getSpriteImpl().getGlobalBounds();
}
void Player::setScale(float x, float y)
{
    m_sprite.setScale({ x, y });
}

void Player::onCollision(GameObject* collidedObject)
{
    if (auto* platform = dynamic_cast<Platform*>(collidedObject))
    {
        if (m_velocity.y >= 0.0f)
        {
            m_velocity.y = 0.0f;
            m_isOnGround = true;
            m_animator.reset();
        }
    }
}

void Player::handleInput(float dt)
{
    float deltaX = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        deltaX += -SPEED_X * dt;
        m_newOrientationRequest = PlayerOrientation::Left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        deltaX += SPEED_X * dt;
        m_newOrientationRequest = PlayerOrientation::Right;
    }

    m_position.x += deltaX;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        shoot();
    }
}

void Player::shoot() {
    if (m_shootCooldownTimer.getElapsedTime().asSeconds() > m_BulletcooldownSec)
    {
        m_shootCooldownTimer.restart();

        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*m_window));
        sf::Vector2f bulletDir = mousePos - m_position;
        float length = std::sqrt(bulletDir.x * bulletDir.x + bulletDir.y * bulletDir.y);
        bulletDir /= length;

        bullets.emplace_back(m_window, m_position, bulletDir, 1200.0f);
        //SoundManager::getInstance().playShoot();
    }
}

void Player::physicsUpdate(float dt)
{
    updateGravity(dt);
    updateJump(dt);
    applyVelocity(dt);
}

void Player::orientationUpdate()
{
    if (m_newOrientationRequest != m_orientation)
    {
        getSpriteImpl().setScale({ getSpriteImpl().getScale().x * -1.0f, getSpriteImpl().getScale().y });
        m_orientation = m_newOrientationRequest;
    }
}

sf::Sprite& Player::getSpriteImpl()
{
    return m_animator.getSprite();
}

const sf::Sprite& Player::getSpriteImpl() const
{
    return const_cast<Player*>(this)->getSpriteImpl();
}

void Player::updateGravity(float dt)
{
    if (!m_isOnGround)
    {
        m_velocity.y += GameConfig::GravityAcceleration * dt;
        if (m_velocity.y >= MaxSpeed)
        {
            m_velocity.y = MaxSpeed;
        }
    }
}

void Player::updateJump(float dt)
{
    if (!m_isOnGround)
    {
        return;
    }

    const bool shouldJump = GameConfig::AutoJump || (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_cooldownTimer.getElapsedTime().asSeconds() > m_cooldownSec);

    if (shouldJump)
    {
        m_cooldownTimer.restart();
        jumpImpl(dt);
        SoundManager::getInstance().playJump();
    }
}

void Player::jumpImpl(float dt)
{
    m_velocity.y = GameConfig::JumpImpulse;
}

void Player::takeDamage(float damage)
{
    m_health -= damage;
    if (m_health <= 0)
    {
        //TODO Player death logic
    }
}

void Player::applyVelocity(float dt)
{
    m_position += m_velocity * dt;
}

void Player::checkBoundaries()
{
    sf::FloatRect spriteBounds = getSpriteImpl().getGlobalBounds();
    sf::Vector2u windowSize = m_window->getSize();

    if (m_position.y + spriteBounds.size.y / 2 > windowSize.y)
    {
        m_position.y = windowSize.y - spriteBounds.size.y;
    }
    if (m_position.y < 0.0f)
    {
    }

    if (m_position.x < 0.0f + spriteBounds.size.x / 6)
    {
        m_position.x = 0.0f + spriteBounds.size.x / 6;
    }
    if (m_position.x + spriteBounds.size.x / 6 > windowSize.x)
    {
        m_position.x = windowSize.x - spriteBounds.size.x / 6;
    }

    getSpriteImpl().setPosition(m_position);
}
void Player::setPosition(const sf::Vector2f& position)
{
    m_position = position;
    m_sprite.setPosition(position);
}

void Player::handleResize()
{
    checkBoundaries();
    getSpriteImpl().setPosition(m_position);
}