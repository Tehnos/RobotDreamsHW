#include "GameHUD.h"
#include "FontManager.h"
#include "GameWorld.h"
#include "Player.h"
#include "Boss.h"

GameHUD::GameHUD(sf::RenderWindow* window, GameWorld* gameWorld)
    : m_window(window)
    , m_gameWorld(gameWorld)
    , m_playerHealthHUD(FontManager::getInstance().getDefaultFont())
    , m_bossHealthHUD(FontManager::getInstance().getDefaultFont())
{
    m_playerHealthHUD.setCharacterSize(48);
    m_playerHealthHUD.setFillColor(sf::Color::Black);
    m_playerHealthHUD.setPosition({ 20.0f, 20.0f });

    m_bossHealthHUD.setCharacterSize(48);
    m_bossHealthHUD.setFillColor(sf::Color::Black);
    m_bossHealthHUD.setPosition({ static_cast<float>(m_window->getSize().x) - 200.0f, 20.0f });
    WindowManager::getInstance().registerResizable(this);
}
GameHUD::~GameHUD()
{
    WindowManager::getInstance().unregisterResizable(this);
}
void GameHUD::update(float dt)
{
    Player* player = m_gameWorld->getPlayer();
    if (player)
    {
        m_playerHealthHUD.setString("Player HP: " + std::to_string(static_cast<int>(player->getHealth())));
    }
    else
    {
        m_playerHealthHUD.setString("Player HP: N/A");
    }

    Boss* boss = m_gameWorld->getBoss();
    if (boss)
    {
        m_bossHealthHUD.setString("Boss HP: " + std::to_string(static_cast<int>(boss->getHealth())));
        m_bossHealthHUD.setPosition({ static_cast<float>(m_window->getSize().x) - 400.0f, 20.0f });
    }
    else
    {
        m_bossHealthHUD.setString("Boss HP: N/A");
    }
}

void GameHUD::draw()
{
    m_window->draw(m_playerHealthHUD);
    m_window->draw(m_bossHealthHUD);
}

void GameHUD::onResize(sf::Vector2u newSize)
{
    m_playerHealthHUD.setPosition({ 20.0f, 20.0f });
    m_bossHealthHUD.setPosition({ static_cast<float>(newSize.x) - 400.0f, 20.0f });
}