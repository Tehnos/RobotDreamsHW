#include "Boss.h"
#include "BossPhase.h"
#include "BossPhaseManager.h"
#include "WindowManager.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <algorithm>
#include <iostream>

constexpr float HIT_DURATION = 0.5f;
Boss::Boss(sf::RenderWindow* window)
    : GameObject(window)
    , m_health(1000.0f)
    , m_maxHealth(1000.0f)
    , m_patternTimer(0.0f)
    , m_phaseManager(this)
    , m_texture("resources/doodle.png")
    , m_sprite(m_texture)
    , m_currentPhaseId(BossPhaseId::PhaseOne)
    , m_isHit(false)
    , m_player(nullptr)
    , m_originalWindowSize(window->getSize())
{
    m_window->setView(m_window->getDefaultView());
    m_sprite.setScale({ 0.5f, 0.5f });
    sf::Vector2f windowSize = static_cast<sf::Vector2f>(window->getSize());
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    m_position = {
        windowSize.x - spriteBounds.size.x,
        windowSize.y - spriteBounds.size.y
    };
    m_orientation = BossOrientation::Right;
    m_sprite.setPosition(m_position);
    m_phaseManager.setPhase(BossPhaseId::PhaseOne);
    WindowManager::getInstance().registerResizable(this);
}

Boss::~Boss()
{
    WindowManager::getInstance().unregisterResizable(this);
}
void Boss::setPlayer(Player* player) { m_player = player; }

void Boss::update(float dt)
{
    if (m_isDead) return;

    if (m_player)
    {
        updateOrientation(m_player->getPosition());
    }

    m_patternTimer += dt;
    m_phaseManager.update(dt);

    if (m_isHit)
    {
        float elapsed = m_hitTimer.getElapsedTime().asSeconds();
        if (elapsed > HIT_DURATION)
        {
            m_isHit = false;
        }
        else
        {
            float alpha = 255 * (1.0f - elapsed / HIT_DURATION);
            m_sprite.setColor(sf::Color(255, 0, 0, alpha));
        }
    }
}

void Boss::draw()
{
    if (!m_isDead)
    {
        m_sprite.setColor(m_isHit ? sf::Color::Red : sf::Color::White);
        m_window->draw(m_sprite);
    }
}

sf::FloatRect Boss::getBoundingBox() const { return m_sprite.getGlobalBounds(); }

void Boss::onCollision(GameObject* other)
{
    if (auto* bullet = dynamic_cast<Bullet*>(other)) { takeDamage(10); }
}

void Boss::takeDamage(int dmg)
{
    if (m_isDead) return;

    m_health -= dmg;
    m_isHit = true;
    m_hitTimer.restart();
    //SoundManager::getInstance().playCollision();
    if (m_health <= 0)
    {
        die();
    }
    else if (m_health <= m_maxHealth * 0.66f && m_currentPhaseId == BossPhaseId::PhaseOne) { nextPhase(); }
    else if (m_health <= m_maxHealth * 0.33f && m_currentPhaseId == BossPhaseId::PhaseTwo) { nextPhase(); }
}

void Boss::shootAt(const sf::Vector2f& target)
{
    if (m_shootingPoints.empty()) return;

    BossOrientation currentOrientation = m_orientation;
    updateOrientation(target);

    if (currentOrientation != m_orientation) { initializeShootingPoints(); }

    for (const auto& point : m_shootingPoints)
    {
        sf::Vector2f direction = target - point;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length > 0)
        {
            direction /= length;
            m_bullets.emplace_back(m_window, point, direction, 300.0f);
            SoundManager::getInstance().playShoot();
        }
    }
}

void Boss::die()
{
    m_isDead = true;
    m_phaseManager.setPhase(BossPhaseId::Dead);
}

void Boss::nextPhase()
{
    if (m_currentPhaseId == BossPhaseId::PhaseOne)
    {
        m_phaseManager.setPhase(BossPhaseId::PhaseTwo);
        SoundManager::getInstance().playPhaseChange();
    }
    else if (m_currentPhaseId == BossPhaseId::PhaseTwo)
    {
        m_phaseManager.setPhase(BossPhaseId::PhaseThree);
        SoundManager::getInstance().playPhaseChange();
    }

    initializeShootingPoints();
}

void Boss::updateOrientation(const sf::Vector2f& target)
{
    BossOrientation newOrientation = (target.x < m_position.x)
        ? BossOrientation::Left
        : BossOrientation::Right;

    if (newOrientation != m_orientation)
    {
        m_orientation = newOrientation;

        sf::FloatRect bounds = m_sprite.getLocalBounds();
        float spriteWidth = bounds.size.x;

        float newScaleX = (m_orientation == BossOrientation::Left) ? -BOSS_SCALE : BOSS_SCALE;
        m_sprite.setScale({ newScaleX, BOSS_SCALE });

        float scaledWidth = spriteWidth * std::abs(newScaleX);
        m_position.x = m_window->getSize().x - scaledWidth;
        m_sprite.setPosition(m_position);

        initializeShootingPoints();
    }
}


void Boss::initializeShootingPoints()
{
    m_shootingPoints.clear();
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    float scaleX = std::abs(m_sprite.getScale().x);

    float localX = (m_orientation == BossOrientation::Left)
        ? -bounds.size.x / 2 + 30.0f
        : bounds.size.x / 2 - 30.0f;

    m_shootingPoints.push_back(
        {
        m_position.x + localX * scaleX,
        m_position.y + 20.0f
        }
    );
}


void Boss::setPosition(const sf::Vector2f& position)
{
    m_position = position;
    m_sprite.setPosition(position);
}

void Boss::handleResize(const sf::Vector2u& newSize)
{
    sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();
    m_position = {
        newSize.x - spriteBounds.size.x,
        newSize.y - spriteBounds.size.y
    };
    setPosition(m_position);
}

void Boss::onResize(sf::Vector2u newSize) {
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    float scaleX = std::abs(m_sprite.getScale().x);
    float spriteWidth = bounds.size.x * scaleX;

    sf::View view = m_window->getView();
    float rightEdge = view.getCenter().x + view.getSize().x / 2.f;
    m_position.x = rightEdge - bounds.size.x * scaleX;
    m_position.y = newSize.y - bounds.size.y * BOSS_SCALE;

    m_sprite.setPosition(m_position);
    initializeShootingPoints();
}

sf::Vector2f Boss::getPlayerPosition() const
{
    if (m_player)
    {
        return m_player->getPosition();
    }
    return m_position + sf::Vector2f(-1000.0f, 0.0f);
}