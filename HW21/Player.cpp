#include "Player.h"

Player::Player(sf::RenderWindow* window)
	: m_window(window)
	, m_texture("resources/doodle.png")
	, m_sprite(m_texture)
	, m_orientation(PlayerOrientation::Right)
	, m_newOrientationRequest(PlayerOrientation::Right)
	, m_videoMode({ window->getSize().x,window->getSize().y })
{
	m_sprite.setOrigin({ m_sprite.getLocalBounds().size.x / 2.0f, m_sprite.getLocalBounds().size.y / 2.0f });

	m_sprite.setScale({ 0.2f, 0.2f });

	const sf::Vector2u windowSize = m_window->getSize();

	m_sprite.setPosition(sf::Vector2f{ windowSize.x / 2.0f,
		windowSize.y - m_sprite.getGlobalBounds().size.y });

	m_position = m_sprite.getPosition();

}

void Player::update(float dt)
{
	//Input step
	handleInput(dt);
	updateJumpInput(dt);

	//Physic step
	updateGravity(dt);
	applyVelocity(dt);
	checkBoundaries();
	updateOrientation();

	m_sprite.setPosition(m_position);
}

void Player::draw()
{
	m_window->draw(m_sprite);
}

void Player::handleInput(float dt)
{
	const float SPEED_X = 1500.0f * dt;

	float deltaX = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		deltaX += -SPEED_X;
		m_newOrientationRequest = PlayerOrientation::Left;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		deltaX += SPEED_X;
		m_newOrientationRequest = PlayerOrientation::Right;
	}

	m_position.x += deltaX;
}

void Player::updateGravity(float dt)
{
	//Apply acceleration DOWN
	const float acceleration = 800.0f;

	m_velocity.y += acceleration * dt;
}

void Player::applyVelocity(float dt)
{
	const sf::Vector2f displacement{ m_velocity.x * dt, m_velocity.y * dt };
	m_position += displacement;
}

void Player::jumpImpulse(float dt)
{
	const float jumpImpulse = -50000.f * dt;

	//Apply INSTANT velocity UP
	m_velocity.y = jumpImpulse;
}

void Player::updateJumpInput(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_jumpCooldownTimer.getElapsedTime().asSeconds() > m_jumpCooldownSec)
	{
		jumpImpulse(dt);
		m_jumpCooldownTimer.restart();
	}
}

void Player::updateOrientation()
{
	if (m_newOrientationRequest != m_orientation)
	{
		m_sprite.setScale({ m_sprite.getScale().x * -1.0f, m_sprite.getScale().y });
		m_orientation = m_newOrientationRequest;
	}
}

const void Player::checkBoundaries()
{
	sf::FloatRect spriteBounds = m_sprite.getGlobalBounds();

	if (m_position.y + spriteBounds.size.y / 2 > m_videoMode.size.y)
	{
		m_position.y = m_videoMode.size.y - spriteBounds.size.y / 2;
	}
	if (m_position.x - spriteBounds.size.x / 2 < 0.0f)
	{
		m_position.x = spriteBounds.size.x / 2;
	}
	if (m_position.x + spriteBounds.size.x / 2 > m_videoMode.size.x)
	{
		m_position.x = m_videoMode.size.x - spriteBounds.size.x / 2;
	}
	//to jump from the right edge to the left and back
	/*if (m_position.x - spriteBounds.size.x / 2 < 0.0f)
	{
		m_position.x = m_videoMode.size.x- spriteBounds.size.x / 2;
	}
	if (m_position.x + spriteBounds.size.x / 2 > m_videoMode.size.x)
	{
		m_position.x = 0.0f + spriteBounds.size.x / 2;
	}ww*/
}


void Player::handleResize(const sf::VideoMode& newVideoMode)
{
	m_videoMode = newVideoMode;
	checkBoundaries();
	m_sprite.setPosition(m_position);
}

