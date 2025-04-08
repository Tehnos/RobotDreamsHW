#include "GameState.h"
#include "Boundaries.h"
#include "GameStateManager.h"
#include "FontManager.h"
#include "SoundManager.h"
#include<fstream>

void GameState_Playing::onEnter()
{
	SoundManager::getInstance().playInGameMusic();
	WindowManager::getInstance().registerResizable(this);
}

void GameState_Playing::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		if (!m_pressedLastFrame)
		{
			m_pressedLastFrame = true;
			m_gameStateManager.setGameState(GameStateId::Pause);
		}
	}
	else
	{
		m_pressedLastFrame = false;
	}
}

void GameState_Playing::update(float DeltaTime)
{
	m_GameWorld->update(DeltaTime);
}

void GameState_Playing::draw()
{
	m_GameWorld->draw();
}

void GameState_Playing::onResize(sf::Vector2u newSize)
{
	if (m_GameWorld) {
		m_GameWorld->onResize(newSize);
	}
}

GameState_Pause::GameState_Pause(GameStateManager& context, GameWorld* gameWorld, sf::RenderWindow* window)
	: GameState(context, window), m_GameWorld(gameWorld), m_pauseText(FontManager::getInstance().getDefaultFont())
	, m_continueText(FontManager::getInstance().getDefaultFont())
	, m_optionsText(FontManager::getInstance().getDefaultFont())
	, m_exitText(FontManager::getInstance().getDefaultFont())
	, m_selectedItem(0)
{
	m_pauseText.setCharacterSize(240);
	m_pauseText.setFillColor(sf::Color::Blue);
	m_pauseText.setString("PAUSED");
	m_pauseText.setRotation(sf::degrees(45));
	m_pauseText.setPosition({ m_window->getSize().x / 2.0f - m_pauseText.getGlobalBounds().size.x / 2.0f
		, m_window->getSize().y / 2.0f - m_pauseText.getGlobalBounds().size.y / 2.0f - 150.0f });

	m_continueText.setString("CONTINUE GAME");
	m_continueText.setCharacterSize(50);
	m_continueText.setFillColor(sf::Color::Cyan);
	m_continueText.setOrigin({ m_continueText.getGlobalBounds().size.x / 2, m_continueText.getGlobalBounds().size.y / 2 });
	m_continueText.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f - 30.0f });

	m_optionsText.setString("OPTIONS");
	m_optionsText.setCharacterSize(50);
	m_optionsText.setFillColor(sf::Color::Cyan);
	m_optionsText.setOrigin({ m_optionsText.getGlobalBounds().size.x / 2, m_optionsText.getGlobalBounds().size.y / 2 });
	m_optionsText.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f + 30.0f });

	m_exitText.setString("EXIT GAME");
	m_exitText.setCharacterSize(50);
	m_exitText.setFillColor(sf::Color::Cyan);
	m_exitText.setOrigin({ m_exitText.getGlobalBounds().size.x / 2, m_exitText.getGlobalBounds().size.y / 2 });
	m_exitText.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f + 90.0f });

	updateSelection();
}

void GameState_Pause::updateState()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !m_pressedLastFrame)
	{
		m_selectedItem = (m_selectedItem - 1 + 3) % 3;
		updateSelection();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !m_pressedLastFrame)
	{
		m_selectedItem = (m_selectedItem + 1) % 3;
		updateSelection();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !m_pressedLastFrame)
	{
		if (m_selectedItem == 0)
		{
			m_gameStateManager.setGameState(GameStateId::Playing);
		}
		else if (m_selectedItem == 1)
		{
			m_gameStateManager.setGameState(GameStateId::Options);
		}
		else if (m_selectedItem == 2)
		{
			m_window->close();
		}
	}

	m_pressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter);
}

void GameState_Pause::update(float DeltaTime)
{
	constexpr unsigned int BlinkPeriod = 500;
	bool needUpdate = false;

	if (m_textLoopClock.getElapsedTime().asMilliseconds() > BlinkPeriod)
	{
		m_textLoopClock.restart();
		m_isVisible = !m_isVisible;
		needUpdate = true;
	}

	if (needUpdate)
	{
		sf::Color color = m_pauseText.getFillColor();
		color.a = (m_isVisible) ? 255 : 0;
		m_pauseText.setFillColor(color);
	}
}

void GameState_Pause::draw()
{
	m_GameWorld->draw();
	m_window->draw(m_pauseText);
	m_window->draw(m_continueText);
	m_window->draw(m_optionsText);
	m_window->draw(m_exitText);
}

void GameState_Pause::onEnter()
{
	m_isVisible = true;
	m_textLoopClock.restart();
	m_GameWorld->blur();
	SoundManager::getInstance().playPause();
	WindowManager::getInstance().registerResizable(this);
	m_pressedLastFrame = false;
}

void GameState_Pause::onExit()
{
	m_GameWorld->unblur();
	SoundManager::getInstance().playUnpause();
	WindowManager::getInstance().unregisterResizable(this);
}

void GameState_Pause::updateSelection()
{
	m_continueText.setFillColor(m_selectedItem == 0 ? sf::Color::Red : sf::Color::Cyan);
	m_optionsText.setFillColor(m_selectedItem == 1 ? sf::Color::Red : sf::Color::Cyan);
	m_exitText.setFillColor(m_selectedItem == 2 ? sf::Color::Red : sf::Color::Cyan);
}

void GameState_Pause::onResize(sf::Vector2u newSize)
{
	unsigned int pauseTextSize = static_cast<unsigned int>(newSize.y * 0.15f);
	unsigned int menuTextSize = static_cast<unsigned int>(newSize.y * 0.04f);

	m_pauseText.setCharacterSize(pauseTextSize);
	m_continueText.setCharacterSize(menuTextSize);
	m_optionsText.setCharacterSize(menuTextSize);
	m_exitText.setCharacterSize(menuTextSize);

	m_pauseText.setOrigin({ m_pauseText.getLocalBounds().size.x / 2, m_pauseText.getLocalBounds().size.y / 2 });
	m_continueText.setOrigin({ m_continueText.getLocalBounds().size.x / 2, m_continueText.getLocalBounds().size.y / 2 });
	m_optionsText.setOrigin({ m_optionsText.getLocalBounds().size.x / 2, m_optionsText.getLocalBounds().size.y / 2 });
	m_exitText.setOrigin({ m_exitText.getLocalBounds().size.x / 2, m_exitText.getLocalBounds().size.y / 2 });

	float verticalSpacing = newSize.y * 0.1f;
	float startY = newSize.y * 0.3f;

	m_pauseText.setPosition({ newSize.x / 2.0f, startY });
	m_continueText.setPosition({ newSize.x / 2.0f, startY + verticalSpacing * 2 });
	m_optionsText.setPosition({ newSize.x / 2.0f, startY + verticalSpacing * 3 });
	m_exitText.setPosition({ newSize.x / 2.0f, startY + verticalSpacing * 4 });
}

GameState_TitleScreen::GameState_TitleScreen(GameStateManager& context, sf::RenderWindow* window)
	: GameState(context, window)
	, m_startTexture("resources/title_screen.jpg")
	, m_startSprite(m_startTexture)
	, m_startText(FontManager::getInstance().getDefaultFont())
	, m_optionsText(FontManager::getInstance().getDefaultFont())
	, m_exitText(FontManager::getInstance().getDefaultFont())
	, m_selectedItem(0)
{
	m_startText.setString("START GAME");
	m_startText.setCharacterSize(100);
	m_startText.setFillColor(sf::Color::Cyan);
	m_startText.setOrigin({ m_startText.getGlobalBounds().size.x / 2, m_startText.getGlobalBounds().size.y / 2 });
	m_startText.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f - 60.0f });

	m_optionsText.setString("OPTIONS");
	m_optionsText.setCharacterSize(100);
	m_optionsText.setFillColor(sf::Color::Cyan);
	m_optionsText.setOrigin({ m_optionsText.getGlobalBounds().size.x / 2, m_optionsText.getGlobalBounds().size.y / 2 });
	m_optionsText.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f + 60.0f });
	m_startSprite.setScale({ static_cast<float>(window->getSize().x) / m_startTexture.getSize().x,static_cast<float>(window->getSize().y) / m_startTexture.getSize().y });

	m_exitText.setString("EXIT GAME");
	m_exitText.setCharacterSize(100);
	m_exitText.setFillColor(sf::Color::Cyan);
	m_exitText.setOrigin({ m_exitText.getLocalBounds().size.x / 2, m_exitText.getLocalBounds().size.y / 2 });
	m_exitText.setPosition({ m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f + 60.0f });
	m_exitText.setScale({ static_cast<float>(window->getSize().x) / m_startTexture.getSize().x,static_cast<float>(window->getSize().y) / m_startTexture.getSize().y });


	unsigned int baseFontSize = static_cast<unsigned int>(window->getSize().y * 0.1f);
	m_startText.setCharacterSize(baseFontSize);
	m_optionsText.setCharacterSize(baseFontSize);

	updatePositions(window->getSize());
	updateSelection();
}

void GameState_TitleScreen::onEnter()
{
	WindowManager::getInstance().registerResizable(this);
	m_pressedLastFrame = false;
	SoundManager::getInstance().playTitleMusic();
}
void GameState_TitleScreen::onResize(sf::Vector2u newSize)
{
	m_startSprite.setScale({ static_cast<float>(newSize.x) / m_startTexture.getSize().x,static_cast<float>(newSize.y) / m_startTexture.getSize().y }
	);

	const unsigned int baseFontSize = static_cast<unsigned int>(newSize.y * 0.06f);
	m_startText.setCharacterSize(baseFontSize);
	m_optionsText.setCharacterSize(baseFontSize);
	m_exitText.setCharacterSize(baseFontSize);

	updatePositions(newSize);
}

void GameState_TitleScreen::updatePositions(sf::Vector2u windowSize)
{
	m_startText.setOrigin({ m_startText.getLocalBounds().size.x / 2.0f,m_startText.getLocalBounds().size.y / 2.0f });
	m_startText.setPosition(
		{ windowSize.x / 2.0f,
				windowSize.y * 0.4f
		});

	m_optionsText.setOrigin({ m_optionsText.getLocalBounds().size.x / 2.0f,m_optionsText.getLocalBounds().size.y / 2.0f });
	m_optionsText.setPosition({ windowSize.x / 2.0f,windowSize.y * 0.55f });

	if (m_exitText.getString() != "")
	{
		m_exitText.setOrigin({ m_exitText.getLocalBounds().size.x / 2.0f,	m_exitText.getLocalBounds().size.y / 2.0f });
		m_exitText.setPosition({ windowSize.x / 2.0f,windowSize.y * 0.7f });
	}
}

void GameState_TitleScreen::onExit()
{
	WindowManager::getInstance().unregisterResizable(this);
	SoundManager::getInstance().stopTitleMusic();
	m_pressedLastFrame = false;
}

void GameState_TitleScreen::updateState()
{
	static bool keyWasPressed = false;

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
	{
		keyWasPressed = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !keyWasPressed)
	{
		m_selectedItem = (m_selectedItem - 1 + 3) % 3;
		updateSelection();
		keyWasPressed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !keyWasPressed)
	{
		m_selectedItem = (m_selectedItem + 1) % 3;
		updateSelection();
		keyWasPressed = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !m_pressedLastFrame)
	{
		m_pressedLastFrame = true;

		if (m_selectedItem == 0)
		{
			m_gameStateManager.setGameState(GameStateId::Playing);
		}
		else if (m_selectedItem == 1)
		{
			m_gameStateManager.setGameState(GameStateId::Options);
		}
		else if (m_selectedItem == 2)
		{
			m_window->close();
		}
	}
	else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
	{
		m_pressedLastFrame = false;
	}
}

void GameState_TitleScreen::update(float DeltaTime)
{

}

void GameState_TitleScreen::draw()
{
	m_window->clear(sf::Color::White);
	m_window->draw(m_startSprite);
	m_window->draw(m_startText);
	m_window->draw(m_optionsText);
	m_window->draw(m_exitText);
}

void GameState_TitleScreen::updateSelection()
{
	m_startText.setFillColor(m_selectedItem == 0 ? sf::Color::Yellow : sf::Color::Cyan);
	m_optionsText.setFillColor(m_selectedItem == 1 ? sf::Color::Yellow : sf::Color::Cyan);
	m_exitText.setFillColor(m_selectedItem == 2 ? sf::Color::Yellow : sf::Color::Cyan);
}

void GameState_Options::update(float dt)
{
}

void GameState_Options::draw()
{
	m_window->clear(sf::Color::Black);
	m_window->draw(m_titleText);
	for (const auto& item : m_menuItems)
	{
		m_window->draw(item);
	}
}

void GameState_Options::updateState()
{
	handleInput();
}

void GameState_Options::onEnter()
{
	WindowManager::getInstance().registerResizable(this);
	m_menuItems.clear();
	setupMenu();
	m_pressedLastFrame = false;
}

void GameState_Options::onExit()
{
	WindowManager::getInstance().unregisterResizable(this);
	saveSettings();
	m_pressedLastFrame = false;
}
void GameState_Options::onResize(sf::Vector2u newSize)
{
	updateMenuPositions();
}
void GameState_Options::updateMenuPositions()
{
	sf::Vector2u windowSize = m_window->getSize();

	m_titleText.setPosition({
		windowSize.x / 2.0f - m_titleText.getGlobalBounds().size.x / 2.0f,
		50.0f * (windowSize.y / 1080.0f)
		});

	float yPos = 200.0f * (windowSize.y / 1080.0f);
	const float step = 70.0f * (windowSize.y / 1080.0f);

	for (auto& item : m_menuItems)
	{
		item.setPosition({
			windowSize.x / 2.0f - item.getGlobalBounds().size.x / 2.0f,
			yPos
			});
		yPos += step;
	}
}
void GameState_Options::handleInput()
{
	bool keyProcessed = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !m_pressedLastFrame)
	{
		m_selectedItem = (m_selectedItem - 1 + m_menuItems.size()) % m_menuItems.size();
		updateMenuColors();
		keyProcessed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !m_pressedLastFrame)
	{
		m_selectedItem = (m_selectedItem + 1) % m_menuItems.size();
		updateMenuColors();
		keyProcessed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !m_pressedLastFrame)
	{
		switch (m_selectedItem)
		{
		case 0: // Master Volume
			m_options.setMasterVolume(std::max(0.f, m_options.getMasterVolume() - 10.f));
			break;
		case 1: // Music Volume
			m_options.setMusicVolume(std::max(0.f, m_options.getMusicVolume() - 10.f));
			break;
		case 2: // SFX Volume
			m_options.setSFXVolume(std::max(0.f, m_options.getSFXVolume() - 10.f));
			break;
		case 3: // Resolution 
			changeResolution(-1);
			break;
		case 4: // Fullscreen 
			m_options.setFullscreen(!m_options.isFullscreen());
			m_options.applyVideoSettings(*m_window);
			WindowManager::getInstance().notifyResize(m_window->getSize());
			m_gameStateManager.handleResize(m_window->getSize());
			break;
		case 5: // VSync 
			m_options.setVSync(!m_options.isVSync());
			m_options.applyVideoSettings(*m_window);
			m_gameStateManager.handleResize(m_window->getSize());
			break;
		case 6: // Blur Effect 
			m_options.setBlurEffect(!m_options.isBlurEffectEnabled());
			break;
		case 7: // Particle Effects 
			m_options.setParticleEffects(!m_options.isParticleEffectsEnabled());
			break;
		}
		setupMenu();
		keyProcessed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !m_pressedLastFrame)
	{
		switch (m_selectedItem)
		{
		case 0: // Master Volume
			m_options.setMasterVolume(std::min(100.f, m_options.getMasterVolume() + 10.f));
			break;
		case 1: // Music Volume
			m_options.setMusicVolume(std::min(100.f, m_options.getMusicVolume() + 10.f));
			break;
		case 2: // SFX Volume
			m_options.setSFXVolume(std::min(100.f, m_options.getSFXVolume() + 10.f));
			break;
		case 3: // Resolution 
			changeResolution(1);
			break;
		case 4: // Fullscreen 
			m_options.setFullscreen(!m_options.isFullscreen());
			m_options.applyVideoSettings(*m_window);
			WindowManager::getInstance().notifyResize(m_window->getSize());
			m_gameStateManager.handleResize(m_window->getSize());
			break;
		case 5: // VSync 
			m_options.setVSync(!m_options.isVSync());
			m_options.applyVideoSettings(*m_window);
			m_gameStateManager.handleResize(m_window->getSize());
			break;
		case 6: // Blur Effect 
			m_options.setBlurEffect(!m_options.isBlurEffectEnabled());
			break;
		case 7: // Particle Effects 
			m_options.setParticleEffects(!m_options.isParticleEffectsEnabled());
			break;
		}
		setupMenu();
		keyProcessed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !m_pressedLastFrame)
	{
		handleSelection();
		keyProcessed = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape) && !m_pressedLastFrame)
	{
		m_gameStateManager.returnToPreviousState();
		keyProcessed = true;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) &&
		!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		m_pressedLastFrame = false;
	}
	else if (keyProcessed)
	{
		m_pressedLastFrame = true;
	}
}

void GameState_Options::changeResolution(int direction)
{
	const auto& resolutions = m_options.getAvailableResolutions();
	if (resolutions.empty()) return;

	auto current = m_options.getResolution();
	auto it = std::find(resolutions.begin(), resolutions.end(), current);

	size_t index = 0;
	if (it != resolutions.end())
	{
		index = (std::distance(resolutions.begin(), it) + direction);
		if (index >= resolutions.size()) index = 0;
		else if (index < 0) index = resolutions.size() - 1;
	}

	m_options.setResolution(resolutions[index].x, resolutions[index].y);
	m_options.applyVideoSettings(*m_window);
	WindowManager::getInstance().notifyResize(m_window->getSize());
	m_gameStateManager.handleResize(m_window->getSize());
}

void GameState_Options::setupMenu()
{
	m_menuItems.clear();

	std::vector<std::string> menuOptions = {
		"Master Volume: " + std::to_string(static_cast<int>(m_options.getMasterVolume())),
		"Music Volume: " + std::to_string(static_cast<int>(m_options.getMusicVolume())),
		"SFX Volume: " + std::to_string(static_cast<int>(m_options.getSFXVolume())),
		"Resolution: " + std::to_string(m_options.getResolution().x) + "x" + std::to_string(m_options.getResolution().y),
		"Fullscreen: " + std::string(m_options.isFullscreen() ? "On" : "Off"),
		"VSync: " + std::string(m_options.isVSync() ? "On" : "Off"),
		"Blur Effect: " + std::string(m_options.isBlurEffectEnabled() ? "On" : "Off"),
		"Particle Effects: " + std::string(m_options.isParticleEffectsEnabled() ? "On" : "Off"),
		"Back"
	};

	m_titleText.setString("OPTIONS");
	m_titleText.setCharacterSize(static_cast<unsigned int>(120 * (m_window->getSize().y / 1080.0f)));
	m_titleText.setFillColor(sf::Color::White);

	const unsigned int baseFontSize = 50;
	for (const auto& option : menuOptions)
	{
		sf::Text text(FontManager::getInstance().getDefaultFont());
		text.setString(option);
		text.setCharacterSize(static_cast<unsigned int>(baseFontSize * (m_window->getSize().y / 1080.0f)));
		text.setFillColor(sf::Color::White);
		m_menuItems.push_back(text);
	}
	updateMenuPositions();
	updateMenuColors();
}

void GameState_Options::updateMenuColors()
{
	for (size_t i = 0; i < m_menuItems.size(); ++i)
	{
		m_menuItems[i].setFillColor(i == m_selectedItem ? sf::Color::Red : sf::Color::White);
	}
}

void GameState_Options::handleSelection()
{
	switch (m_selectedItem)
	{
	case 0: // Master Volume

		m_options.setMasterVolume(std::min(100.f, m_options.getMasterVolume() + 10.f));
		break;
	case 1: // Music Volume
		m_options.setMusicVolume(std::min(100.f, m_options.getMusicVolume() + 10.f));
		break;
	case 2: // SFX Volume
		m_options.setSFXVolume(std::min(100.f, m_options.getSFXVolume() + 10.f));
		break;
	case 3: // Resolution
		changeResolution(1); // 1 - ïåðåõ³ä äî íàñòóïíîãî ðîçøèðåííÿ
		break;
	case 4: // Fullscreen
		m_options.setFullscreen(!m_options.isFullscreen());
		m_options.applyVideoSettings(*m_window);
		WindowManager::getInstance().notifyResize(m_window->getSize());
		m_gameStateManager.handleResize(m_window->getSize());
		break;
	case 5: // VSync
		m_options.setVSync(!m_options.isVSync());
		m_options.applyVideoSettings(*m_window);
		m_gameStateManager.handleResize(m_window->getSize());
		break;
	case 6: // Blur Effect
		m_options.setBlurEffect(!m_options.isBlurEffectEnabled());
		break;
	case 7: // Particle Effects
		m_options.setParticleEffects(!m_options.isParticleEffectsEnabled());
		break;
	case 8: // Back
		m_gameStateManager.returnToPreviousState();
		return;
	}
	setupMenu();
}


void GameState_Options::loadSettings()
{
	std::ifstream inFile("settings.txt");

	if (inFile.is_open())
	{
		std::string line;
		while (std::getline(inFile, line)) {
			if (line.find("MasterVolume=") == 0) {
				m_masterVolume = std::stof(line.substr(13));
			}
			else if (line.find("MusicVolume=") == 0) {
				m_musicVolume = std::stof(line.substr(12));
			}
			else if (line.find("SFXVolume=") == 0) {
				m_sfxVolume = std::stof(line.substr(10));
			}
			else if (line.find("Resolution=") == 0) {
				std::string res = line.substr(11);
				size_t pos = res.find('x');
				if (pos != std::string::npos) {
					m_resolution.x = std::stoi(res.substr(0, pos));
					m_resolution.y = std::stoi(res.substr(pos + 1));
				}
			}
			else if (line.find("Fullscreen=") == 0) {
				m_fullscreen = (line.substr(11) == "On");
			}
			else if (line.find("VSync=") == 0) {
				m_vSync = (line.substr(6) == "On");
			}
			else if (line.find("BlurEffect=") == 0) {
				m_blurEffect = (line.substr(11) == "On");
			}
			else if (line.find("ParticleEffects=") == 0) {
				m_particleEffects = (line.substr(17) == "On");
			}
		}

		inFile.close();
	}
}
void GameState_Options::saveSettings()
{
	std::ofstream outFile("settings.txt");

	if (outFile.is_open())
	{
		outFile << "MasterVolume=" << m_masterVolume << "\n";
		outFile << "MusicVolume=" << m_musicVolume << "\n";
		outFile << "SFXVolume=" << m_sfxVolume << "\n";
		outFile << "Resolution=" << m_resolution.x << "x" << m_resolution.y << "\n";
		outFile << "Fullscreen=" << (m_fullscreen ? "On" : "Off") << "\n";
		outFile << "VSync=" << (m_vSync ? "On" : "Off") << "\n";
		outFile << "BlurEffect=" << (m_blurEffect ? "On" : "Off") << "\n";
		outFile << "ParticleEffects=" << (m_particleEffects ? "On" : "Off") << "\n";

		outFile.close();
	}
}
