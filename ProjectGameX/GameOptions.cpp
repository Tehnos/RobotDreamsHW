#include "GameOptions.h"

void GameOptions::setMasterVolume(float volume)
{
	m_masterVolume = std::clamp(volume, 0.0f, 100.0f);
	updateAllVolumes();
}

void GameOptions::setMusicVolume(float volume)
{
	m_musicVolume = std::clamp(volume, 0.0f, 100.0f);
	updateAllVolumes();
}

void GameOptions::setSFXVolume(float volume)
{
	m_sfxVolume = std::clamp(volume, 0.0f, 100.0f);
	updateAllVolumes();
}

void GameOptions::setResolution(unsigned int width, unsigned int height)
{
	m_resolution = { width, height };
}

void GameOptions::applyVideoSettings(sf::RenderWindow& window)
{
	sf::VideoMode newMode;
	if (m_fullscreen)
	{
		newMode = sf::VideoMode::getDesktopMode();
		m_resolution = { newMode.size.x, newMode.size.y };
	}
	else
	{
		newMode = sf::VideoMode({ m_resolution.x, m_resolution.y }, 32);
	}

	window.close();

	if (m_fullscreen)
	{
		window.create(newMode, "Project_Game_X", sf::State::Fullscreen);
	}
	else
	{
		window.create(newMode, "Project_Game_X", sf::Style::Resize | sf::Style::Close);
	}

	window.setVerticalSyncEnabled(m_vsync);

	sf::View newView(sf::FloatRect({ 0, 0 }, { static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y) }));
	window.setView(newView);
	WindowManager::getInstance().initialize(&window);
	WindowManager::getInstance().notifyResize(window.getSize());
}

void GameOptions::updateAllVolumes()
{
	SoundManager& sound = SoundManager::getInstance();
	sound.setMasterVolume(m_masterVolume);
	sound.setMusicVolume(m_musicVolume);
	sound.setSFXVolume(m_sfxVolume);
}