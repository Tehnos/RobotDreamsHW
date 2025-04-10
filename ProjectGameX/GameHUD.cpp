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
    , m_bossHealthText(FontManager::getInstance().getDefaultFont())
    , m_playerHealthText(FontManager::getInstance().getDefaultFont())
{
    m_playerHealthHUD.setCharacterSize(24);
    m_playerHealthHUD.setFillColor(sf::Color::Black);
    m_playerHealthHUD.setString("Player HP");
    m_playerHealthHUD.setPosition({ 20.0f, 20.0f });

    m_bossHealthHUD.setCharacterSize(24);
    m_bossHealthHUD.setFillColor(sf::Color::Black);
    m_bossHealthHUD.setString("Boss HP");
    m_bossHealthHUD.setPosition({ static_cast<float>(m_window->getSize().x) - 420.0f, 20.0f });

    m_playerHealthBarBackground.setSize({ 200.0f, 25.0f });
    m_playerHealthBarBackground.setFillColor(sf::Color(50, 50, 50));
    m_playerHealthBarBackground.setOutlineThickness(2.0f);
    m_playerHealthBarBackground.setOutlineColor(sf::Color::Black);

    m_playerHealthBar.setSize({ 200.0f, 25.0f });
    m_playerHealthBar.setFillColor(sf::Color::Green);

    m_playerHealthText.setFont(FontManager::getInstance().getDefaultFont());
    m_playerHealthText.setCharacterSize(18);
    m_playerHealthText.setFillColor(sf::Color::Black);
    m_playerHealthText.setString("100/100");

    m_bossHealthBarBackground.setSize({ 400.0f, 30.0f });
    m_bossHealthBarBackground.setFillColor(sf::Color(50, 50, 50));
    m_bossHealthBarBackground.setOutlineThickness(2.0f);
    m_bossHealthBarBackground.setOutlineColor(sf::Color::Black);

    m_bossHealthBar.setSize({ 400.0f, 30.0f });
    m_bossHealthBar.setFillColor(sf::Color::Green);

    m_bossHealthText.setFont(FontManager::getInstance().getDefaultFont());
    m_bossHealthText.setCharacterSize(20);
    m_bossHealthText.setFillColor(sf::Color::Black);
    m_bossHealthText.setString("1000/1000");

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
        float playerHealthPercent = player->getHealth() / 100.0f;
        m_playerHealthBar.setSize({ 200.0f * playerHealthPercent, 25.0f });

        if (playerHealthPercent > 0.5f)
        {
            m_playerHealthBar.setFillColor(sf::Color::Green);
        }
        else if (playerHealthPercent > 0.25f)
        {
            m_playerHealthBar.setFillColor(sf::Color::Yellow);
        }
        else {
            m_playerHealthBar.setFillColor(sf::Color::Red);
        }

        m_playerHealthText.setString(std::to_string(static_cast<int>(player->getHealth())) + "/100");
    }
    else
    {
        m_playerHealthBar.setSize({ 0.0f, 25.0f });
        m_playerHealthText.setString("0/100");
    }

    Boss* boss = m_gameWorld->getBoss();
    if (boss)
    {
        float bossHealthPercent = boss->getHealth() / boss->getMaxHealth();
        m_bossHealthBar.setSize({ 400.0f * bossHealthPercent, 30.0f });

        if (bossHealthPercent > 0.5f) {
            m_bossHealthBar.setFillColor(sf::Color::Green);
        }
        else if (bossHealthPercent > 0.25f) {
            m_bossHealthBar.setFillColor(sf::Color::Yellow);
        }
        else {
            m_bossHealthBar.setFillColor(sf::Color::Red);
        }

        m_bossHealthText.setString(std::to_string(static_cast<int>(boss->getHealth())) + "/" +
            std::to_string(static_cast<int>(boss->getMaxHealth())));
    }
    else
    {
        m_bossHealthBar.setSize({ 0.0f, 30.0f });
        m_bossHealthText.setString("0/0");
    }
}

void GameHUD::draw()
{
    sf::Vector2f playerTextPos = m_playerHealthHUD.getPosition();

    m_playerHealthBarBackground.setPosition({ playerTextPos.x, playerTextPos.y + 30.0f });
    m_playerHealthBar.setPosition({ playerTextPos.x, playerTextPos.y + 30.0f });

    sf::FloatRect playerHealthBarBounds = m_playerHealthBarBackground.getGlobalBounds();
    sf::FloatRect playerTextBounds = m_playerHealthText.getGlobalBounds();
    m_playerHealthText.setPosition({ playerHealthBarBounds.getCenter().x-25.0f, playerHealthBarBounds.getCenter().y - 10.0f });

    m_window->draw(m_playerHealthBarBackground);
    m_window->draw(m_playerHealthBar);
    m_window->draw(m_playerHealthText);

    if (m_gameWorld->getBoss())
    {
        sf::Vector2f bossTextPos = m_bossHealthHUD.getPosition();

        m_bossHealthBarBackground.setPosition({ bossTextPos.x, bossTextPos.y + 30.0f });
        m_bossHealthBar.setPosition({ bossTextPos.x, bossTextPos.y + 30.0f });

        sf::FloatRect bossHealthBarBounds = m_bossHealthBarBackground.getGlobalBounds();
        sf::FloatRect bossTextBounds = m_bossHealthText.getGlobalBounds();
        m_bossHealthText.setPosition({ bossHealthBarBounds.getCenter().x - 25.0f, bossHealthBarBounds.getCenter().y - 10.0f });

        m_window->draw(m_bossHealthBarBackground);
        m_window->draw(m_bossHealthBar);
        m_window->draw(m_bossHealthText);
    }

    m_window->draw(m_playerHealthHUD);
    m_window->draw(m_bossHealthHUD);
}

void GameHUD::onResize(sf::Vector2u newSize)
{
    m_playerHealthHUD.setPosition({ 20.0f, 20.0f });
    m_bossHealthHUD.setPosition({ static_cast<float>(newSize.x) - 420.0f, 20.0f });

    m_playerHealthBarBackground.setPosition({ m_playerHealthHUD.getPosition().x, m_playerHealthHUD.getPosition().y + 30.0f });
    m_playerHealthBar.setPosition({ m_playerHealthHUD.getPosition().x, m_playerHealthHUD.getPosition().y + 30.0f });

    if (m_gameWorld->getBoss())
    {
        m_bossHealthBarBackground.setPosition({ m_bossHealthHUD.getPosition().x, m_bossHealthHUD.getPosition().y + 30.0f });
        m_bossHealthBar.setPosition({ m_bossHealthHUD.getPosition().x, m_bossHealthHUD.getPosition().y + 30.0f });
    }

    updateHealthTextPositions();
}

void GameHUD::updateHealthTextPositions()
{
    sf::FloatRect playerHealthBarBounds = m_playerHealthBarBackground.getGlobalBounds();
    sf::FloatRect playerTextBounds = m_playerHealthText.getGlobalBounds();
    m_playerHealthText.setPosition( playerHealthBarBounds.getCenter());

    if (m_gameWorld->getBoss())
    {
        sf::FloatRect bossHealthBarBounds = m_bossHealthBarBackground.getGlobalBounds();
        sf::FloatRect bossTextBounds = m_bossHealthText.getGlobalBounds();
        m_bossHealthText.setPosition(
                        bossHealthBarBounds.getCenter()
        );
    }
}