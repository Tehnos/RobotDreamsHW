#pragma once
#include "Player.h"
#include "BossPhaseManager.h"
#include "BossPhaseId.h"
#include <vector>
#include "Bullet.h"
#include "IResizable.h"

class Player;

enum class BossOrientation
{
    Left,
    Right,
    Center
};


class Boss : public GameObject, public IResizable
{
public:
    Boss(sf::RenderWindow* window);
    ~Boss();
    void setPlayer(Player* player);
    void update(float dt) override;
    void draw() override;
    sf::FloatRect getBoundingBox() const override;
    void onCollision(GameObject* other) override;
    void takeDamage(int dmg);
    void shootAt(const sf::Vector2f& target);
    void die();
    std::vector<Bullet>& getBullets() { return m_bullets; }
    float getHealth() const { return m_health; }
    float getMaxHealth() const { return m_maxHealth; }
    void nextPhase();
    sf::Vector2f getPosition() const { return m_position; }
    sf::Sprite& getSprite() { return m_sprite; }
    float getPatternTimer() const { return m_patternTimer; }
    void setCurrentPhaseId(BossPhaseId id) { m_currentPhaseId = id; }
    void updateOrientation(const sf::Vector2f& target);
    void initializeShootingPoints();
    void setPosition(const sf::Vector2f& position);
    void handleResize(const sf::Vector2u& newSize);
    void onResize(sf::Vector2u newSize);
    Player* getPlayer() const { return m_player; }
    sf::Vector2f getPlayerPosition() const;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    float m_health;
    float m_maxHealth;
    float m_patternTimer;
    bool m_isDead = false;
    Player* m_player;
    BossPhaseManager m_phaseManager;
    std::vector<Bullet> m_bullets;
    std::vector<sf::Vector2f> m_shootingPoints;
    sf::Vector2u m_originalWindowSize;
    BossPhaseId m_currentPhaseId;
    BossOrientation m_orientation;
    sf::Clock m_hitTimer;
    bool m_isHit;
    static constexpr float HIT_DURATION = 0.1f; //
    const float RIGHT_OFFSET = 20.0f;
    const float BOTTOM_OFFSET = 20.0f;
    const float BOSS_SCALE = 0.5f;
    const float SHOOTING_POINT_OFFSET = 30.0f;
    sf::VideoMode m_videoMode;

};
