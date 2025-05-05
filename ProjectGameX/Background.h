#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "IResizable.h"
#include "WindowManager.h"

class Background : public GameObject, public IResizable
{
public:
	Background(sf::RenderWindow* window);

	void update(float dt) override {}
	void draw() override;

	void resize(const sf::Vector2u& windowSize);
	void onResize(sf::Vector2u newSize) override;
	~Background() override;
private:
	void updateSize(sf::Vector2u size);
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};