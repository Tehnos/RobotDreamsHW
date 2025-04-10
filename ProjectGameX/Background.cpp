#include "Background.h"

Background::Background(sf::RenderWindow* window) : GameObject(window), m_texture("resources/background.png"), m_sprite(m_texture)
{
	WindowManager::getInstance().registerResizable(this);
	m_texture.setRepeated(true);
	m_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(m_window->getSize().x), static_cast<int>(m_window->getSize().y) }));
}
void Background::draw()
{
	m_window->draw(m_sprite);
}
void Background::resize(const sf::Vector2u& windowSize)
{
	m_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(windowSize.x), static_cast<int>(windowSize.y) }));
}
void Background::onResize(sf::Vector2u newSize)
{
	updateSize(newSize);
}
Background::~Background()
{
	WindowManager::getInstance().unregisterResizable(this);
}

void Background::updateSize(sf::Vector2u size)
{
	m_sprite.setTextureRect(sf::IntRect({ 0, 0 }, { static_cast<int>(size.x), static_cast<int>(size.y) }));
}