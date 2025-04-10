#pragma once
#include <cstddef>
#include <SFML/Graphics.hpp>
#include <stack>

class GameState;
class GameWorld;

enum class GameStateId
{
    TitleScreen,
    Pause,
    Playing,
    Options,
    Count
};

class GameStateManager
{
public:
    GameStateManager(GameWorld* gameWorld, GameStateId initialGameStateId, sf::RenderWindow* window);
    ~GameStateManager();

    void setGameState(GameStateId newGameState);
    void returnToPreviousState();
    void update(float deltaTime);
    void draw();
    void handleResize(sf::Vector2u newSize);
    GameStateId getCurrentStateId() const;
private:
    GameState* m_gameStates[static_cast<unsigned int>(GameStateId::Count)];
    GameState* m_currentGameState;
    std::stack<GameStateId> m_stateStack;
    sf::RenderWindow* m_window;
};