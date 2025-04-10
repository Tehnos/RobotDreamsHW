#include "CollisionManager.h"

CollisionManager::CollisionManager(Player& player, Boss& boss, std::vector<Platform*>& platforms)
    : m_player(player)
    , m_boss(boss)
    , m_platforms(platforms)
{
}

void CollisionManager::checkCollisions(float dt)
{
    checkPlayerBossCollisions();
    checkPlayerBulletsWithBoss();
    checkBossBulletsWithPlayer();
    checkPlayerWithPlatforms();
}

void CollisionManager::updateBullets(float dt)
{
    auto& playerBullets = m_player.getBullets();
    for (auto& bullet : playerBullets) {
        bullet.update(dt);
    }

    // Îíîâëåííÿ êóëü áîñà ç âèäàëåííÿì òèõ, ùî âèéøëè çà ìåæ³
    auto& bossBullets = m_boss.getBullets();
    bossBullets.erase(std::remove_if(bossBullets.begin(), bossBullets.end(),
        [this, dt](Bullet& bullet) {
            bullet.update(dt);
            return bullet.getBoundingBox().size.x > m_boss.getWindow()->getSize().x ||
                bullet.getBoundingBox().size.y < 0;
        }), bossBullets.end());
}

void CollisionManager::drawBullets()
{
    for (auto& bullet : m_player.getBullets())
    {
        bullet.draw();
    }
    for (auto& bullet : m_boss.getBullets())
    {
        bullet.draw();
    }
}

void CollisionManager::checkPlayerBossCollisions()
{
    if (m_player.getBoundingBox().findIntersection(m_boss.getBoundingBox()))
    {
        m_player.takeDamage(10);
        m_boss.onCollision(&m_player);
    }
}

void CollisionManager::checkPlayerBulletsWithBoss()
{
    auto& bullets = m_player.getBullets();
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        if (it->getBoundingBox().findIntersection(m_boss.getBoundingBox()))
        {
            m_boss.takeDamage(10);
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void CollisionManager::checkBossBulletsWithPlayer()
{
    auto& bullets = m_boss.getBullets();
    for (auto it = bullets.begin(); it != bullets.end();)
    {
        if (it->getBoundingBox().findIntersection(m_player.getBoundingBox()))
        {
            m_player.takeDamage(10);
            it = bullets.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void CollisionManager::checkPlayerWithPlatforms()
{
    for (Platform* platform : m_platforms)
    {
        if (platform && m_player.getBoundingBox().findIntersection(platform->getBoundingBox()))
        {
            m_player.onCollision(platform);
        }
    }
}