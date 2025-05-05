#include "PhysicsEngine.h"
#include "Boss.h"

PhysicsEngine::PhysicsEngine(Player* player, std::vector<Platform*>& platforms, Boss* boss)
    : m_player(player),
    m_platforms(platforms),
    m_boss(boss)
{

}

void PhysicsEngine::update(float dt)
{
    sf::FloatRect playerBounds = m_player->getBoundingBox();

    for (Platform* platform : m_platforms)
    {
        sf::FloatRect platformBounds = platform->getBoundingBox();
        if (playerBounds.findIntersection(platformBounds))
        {
            m_player->onCollision(platform);
            platform->onCollision(m_player);
        }
    }


}

