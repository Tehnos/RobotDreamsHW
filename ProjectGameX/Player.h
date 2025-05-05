#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "DistanceTracker.h"
#include "Animator.h"
#include "Bullet.h"
class Boss;
enum class PlayerOrientation
{
	Left,
	Right,
	Center
};
enum class PlayerState {
	Idle,
	Walking,
	Jumping
};

class Player : public GameObject
{
public:
	Player(sf::RenderWindow* window);

	void update(float dt) override;
	void draw() override;
	sf::FloatRect getBoundingBox() const override;
	void setScale(float x, float y);
	void onCollision(GameObject* collidedObject);
	std::vector<Bullet>& getBullets() { return bullets; }
	sf::Vector2f getPosition() const { return m_position; }
	float getHealth() const { return m_health; }
	void setPosition(const sf::Vector2f& position);
	void handleResize();
	void takeDamage(float damage);
private:
	void handleInput(float dt);
	void shoot();
	void physicsUpdate(float dt);
	void orientationUpdate();

	sf::Sprite& getSpriteImpl();
	const sf::Sprite& getSpriteImpl() const;

	//The order is important
	//Here's why: //https://wiki.sei.cmu.edu/confluence/display/cplusplus/OOP53-CPP.+Write+constructor+member+initializers+in+the+canonical+order
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	sf::Vector2f m_position;
	PlayerOrientation m_orientation;
	PlayerOrientation m_newOrientationRequest;
private:
	void updateGravity(float dt);

	void updateJump(float dt);
	void jumpImpl(float dt);
	void applyVelocity(float dt);
	void checkBoundaries();
private:
	sf::Vector2f m_velocity;

	sf::Clock m_cooldownTimer;
	sf::Clock m_shootCooldownTimer;
	float m_cooldownSec = 1.0f;
	float m_BulletcooldownSec = 0.2f;

	float m_health = 100;
	bool m_isOnGround = false;

private:
	Animator m_animator;
	PlayerState m_state;
	AnimationSettings m_currentSettings;

	std::vector<Bullet> bullets;
	sf::Texture m_bulletTexture;
	sf::VideoMode m_videoMode;

	Boss* m_boss;

};