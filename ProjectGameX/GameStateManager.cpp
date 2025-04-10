#include "GameStateManager.h"
#include "GameState.h"

GameStateManager::GameStateManager(GameWorld* gameWorld, GameStateId initialGameStateId, sf::RenderWindow* window)
    : m_window(window)
{
    m_gameStates[static_cast<std::size_t>(GameStateId::TitleScreen)] = new GameState_TitleScreen(*this, window);
    m_gameStates[static_cast<std::size_t>(GameStateId::Pause)] = new GameState_Pause(*this, gameWorld, window);
    m_gameStates[static_cast<std::size_t>(GameStateId::Playing)] = new GameState_Playing(*this, gameWorld, window);
    m_gameStates[static_cast<std::size_t>(GameStateId::Options)] = new GameState_Options(*this, window);

    m_currentGameState = m_gameStates[static_cast<std::size_t>(initialGameStateId)];
    m_currentGameState->onEnter();
}

void GameStateManager::setGameState(GameStateId newGameState)
{
    if (m_currentGameState)
    {
        GameStateId currentStateId = GameStateId::Count;
        for (int i = 0; i < static_cast<int>(GameStateId::Count); ++i)
        {
            if (m_gameStates[i] == m_currentGameState)
            {
                currentStateId = static_cast<GameStateId>(i);
                break;
            }
        }

        m_currentGameState->onExit();
        if (currentStateId != GameStateId::Count)
        {
            m_stateStack.push(currentStateId);
        }
    }
    m_currentGameState = m_gameStates[static_cast<std::size_t>(newGameState)];
    m_currentGameState->onEnter();
}

void GameStateManager::returnToPreviousState()
{
    if (!m_stateStack.empty())
    {
        m_currentGameState->onExit();
        m_currentGameState = m_gameStates[static_cast<std::size_t>(m_stateStack.top())];
        m_stateStack.pop();
        m_currentGameState->onEnter();
    }
    else
    {
        m_currentGameState->onExit();
        m_currentGameState = m_gameStates[static_cast<std::size_t>(GameStateId::TitleScreen)];
        m_currentGameState->onEnter();
    }
}

void GameStateManager::update(float deltaTime)
{
    m_currentGameState->update(deltaTime);
    m_currentGameState->updateState();
}

void GameStateManager::draw()
{
    m_currentGameState->draw();
}

void GameStateManager::handleResize(sf::Vector2u newSize)
{
    if (m_currentGameState)
    {
        m_currentGameState->onResize(newSize);
    }

    for (auto& state : m_gameStates)
    {
        if (state) state->onResize(newSize);
    }
}
GameStateId GameStateManager::getCurrentStateId() const
{
    for (int i = 0; i < static_cast<int>(GameStateId::Count); ++i)
    {
        if (m_gameStates[i] == m_currentGameState)
        {
            return static_cast<GameStateId>(i);
        }
    }
    return GameStateId::TitleScreen;
}
GameStateManager::~GameStateManager()
{
    while (!m_stateStack.empty())
        m_stateStack.pop();
    for (int i = 0; i < static_cast<unsigned int>(GameStateId::Count); i++)
    {
        delete m_gameStates[i];
    }
}