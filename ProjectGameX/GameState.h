#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameWorld.h"
#include "GameOptions.h"
#include "FontManager.h"
#include "GameStateManager.h"

class GameStateManager;

class GameState : public IResizable
{
public:
	GameState(GameStateManager& context, sf::RenderWindow* window)
		: m_gameStateManager(context), m_window(window) {
	}
	virtual void onEnter() {}
	virtual void onExit() {}

	virtual void updateState() = 0;
	virtual void update(float DeltaTime) = 0;
	virtual void draw() = 0;

	virtual void onResize(sf::Vector2u newSize) override {}

protected:
	sf::RenderWindow* m_window;
	GameStateManager& m_gameStateManager;
};

class GameState_Playing : public GameState
{
public:
	GameState_Playing(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window)
		: GameState(context, window), m_GameWorld(gameWorld) {
	}
	void onEnter() override;
	void updateState() override;
	void update(float DeltaTime) override;
	void draw() override;

	void onResize(sf::Vector2u newSize) override;

private:
	GameWorld* m_GameWorld;
	bool m_pressedLastFrame = true;
};

class GameState_Pause : public GameState
{
public:
	GameState_Pause(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window);

	void updateState() override;
	void update(float DeltaTime) override;
	void draw() override;

	void onEnter() override;
	void onExit() override;

	void updateSelection();
	void onResize(sf::Vector2u newSize) override;


private:
	GameWorld* m_GameWorld;
	bool m_pressedLastFrame = true;
	sf::Text m_pauseText;
	sf::Text m_continueText;
	sf::Text m_optionsText;
	sf::Text m_exitText;
	sf::Clock m_textLoopClock;
	int m_selectedItem;
	bool m_isVisible = true;
};

class GameState_TitleScreen : public GameState
{
public:
	GameState_TitleScreen(GameStateManager& context, sf::RenderWindow* window);

	void onEnter() override;
	void onResize(sf::Vector2u newSize);
	void updatePositions(sf::Vector2u windowSize);
	void onExit() override;

	void updateState() override;
	void update(float DeltaTime) override;
	void draw() override;

private:
	void updateSelection();

	sf::Texture m_startTexture;
	sf::Sprite m_startSprite;
	sf::Text m_startText;
	sf::Text m_optionsText;
	sf::Text m_exitText;
	int m_selectedItem;
	bool m_pressedLastFrame = false;
};



class GameState_Options : public GameState
{
public:
	GameState_Options(GameStateManager& context, sf::RenderWindow* window)
		: GameState(context, window)
		, m_options(GameOptions::getInstance())
		, m_titleText(FontManager::getInstance().getDefaultFont())
		, m_selectedItem(0)
	{

	}
	void update(float dt) override;
	void draw() override;
	void updateState() override;
	void onEnter() override;
	void onExit() override;
	void onResize(sf::Vector2u newSize) override;
private:
	void handleInput();
	void changeResolution(int direction);
	void setupMenu();
	void updateMenuColors();
	void handleSelection();
	void updateMenuPositions();
private:
	GameOptions& m_options;
	sf::Text m_titleText;
	std::vector<sf::Text> m_menuItems;
	size_t m_selectedItem;
	bool m_pressedLastFrame = false;
};