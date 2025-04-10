#include "BossPhase.h"
#include "Boss.h"

void BossPhase1::onEnter(Boss& boss)
{
    m_shootClock.restart();
    if (boss.getPlayer())
    {
        boss.shootAt(boss.getPlayer()->getPosition());
    }
}

void BossPhase1::update(Boss& boss, float dt)
{
    if (boss.getPlayer() && m_shootClock.getElapsedTime().asSeconds() > 1.5f)
    {
        boss.shootAt(boss.getPlayer()->getPosition());
        m_shootClock.restart();
    }
}

void BossPhase1::onExit(Boss& boss) {}

void BossPhase2::onEnter(Boss& boss)
{
    m_shootClock.restart();
}

void BossPhase2::update(Boss& boss, float dt)
{
    if (m_shootClock.getElapsedTime().asSeconds() > 1.f)
    {
        sf::Vector2f playerPos = boss.getPlayerPosition();

        sf::Vector2f baseDirection = playerPos - boss.getPosition();
        float baseLength = std::sqrt(baseDirection.x * baseDirection.x + baseDirection.y * baseDirection.y);
        if (baseLength > 0) baseDirection /= baseLength;

        for (int i = -2; i <= 2; i++)
        {
            float angle = i * 15.0f;
            float rad = angle * 3.14159f / 180.0f;

            sf::Vector2f direction(
                baseDirection.x * std::cos(rad) - baseDirection.y * std::sin(rad),
                baseDirection.x * std::sin(rad) + baseDirection.y * std::cos(rad)
            );

            boss.shootAt(boss.getPosition() + direction * 1000.0f);
        }
        m_shootClock.restart();
    }
}

void BossPhase2::onExit(Boss& boss) {}

void BossPhase3::onEnter(Boss& boss)
{
    m_shootClock.restart();
}

void BossPhase3::update(Boss& boss, float dt)
{
    if (m_shootClock.getElapsedTime().asSeconds() > 0.2f) {
        float randomAngle = static_cast<float>(rand() % 360);
        sf::Vector2f direction(std::cos(randomAngle * 3.14159f / 180.0f),
            std::sin(randomAngle * 3.14159f / 180.0f));
        boss.shootAt(boss.getPosition() + direction * 1000.0f);
        m_shootClock.restart();
    }
    boss.getSprite().move({ std::sin({ boss.getPatternTimer() * 2.0f}) * 100.0f * dt, 0 });
}

void BossPhase3::onExit(Boss& boss) {}