#pragma once
#include <SFML/Graphics.hpp>

enum class PlayerOrientation
{
	Left,
	Right,
	Center
};

class Player
{
public:
	Player(sf::RenderWindow* window);

	void update(float dt);
	void draw();

	const sf::Sprite& getSprite() const { return m_sprite; }

	void handleResize(const sf::VideoMode& newVideoMode);
private:
	void handleInput(float dt);

	void updateGravity(float dt);
	void applyVelocity(float dt);

	void jumpImpulse(float dt);
	void updateJumpInput(float dt);
	void updateOrientation();

	void checkBoundaries();

	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::VideoMode m_videoMode;

	sf::RenderWindow* m_window = nullptr;

	sf::Vector2f m_velocity;

	sf::Vector2f m_position;
	PlayerOrientation m_orientation;
	PlayerOrientation m_newOrientationRequest;


	sf::Clock m_jumpCooldownTimer;
	float m_jumpCooldownSec = 0.3f;
};