#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SoundManager.h"
#include "Background.h"
#include "GameWorld.h"
#include "GameHUD.h"
#include "WindowManager.h"
#include <vector>


class GameOptions
{
public:
	static GameOptions& getInstance()
	{
		static GameOptions instance;
		return instance;
	}


	void setMasterVolume(float volume);
	void setMusicVolume(float volume);
	void setSFXVolume(float volume);


	void setResolution(unsigned int width, unsigned int height);
	void setFullscreen(bool enabled) { m_fullscreen = enabled; }
	void setVSync(bool enabled) { m_vsync = enabled; }
	void setBlurEffect(bool enabled) { m_blurEffect = enabled; }
	void setParticleEffects(bool enabled) { m_particleEffects = enabled; }


	float getMasterVolume() const { return m_masterVolume; }
	float getMusicVolume() const { return m_musicVolume; }
	float getSFXVolume() const { return m_sfxVolume; }
	sf::Vector2u getResolution() const { return m_resolution; }
	bool isFullscreen() const { return m_fullscreen; }
	bool isVSync() const { return m_vsync; }
	bool isBlurEffectEnabled() const { return m_blurEffect; }
	bool isParticleEffectsEnabled() const { return m_particleEffects; }

	const std::vector<sf::Vector2u>& getAvailableResolutions() const { return m_availableResolutions; }
	void applyVideoSettings(sf::RenderWindow& window);

private:
	GameOptions()
		: m_masterVolume(75.0f)
		, m_musicVolume(50.0f)
		, m_sfxVolume(75.0f)
		, m_resolution(1920, 1080)
		, m_fullscreen(false)
		, m_vsync(true)
		, m_blurEffect(true)
		, m_particleEffects(true)
	{
		m_availableResolutions =
		{
			{800, 600},
			{1280, 720},
			{1920, 1080},
			{2560, 1440},
			{1920, 1080},
			{1280, 720},
			{1024, 768},
			{1280,1024},
			{1360,768},
			{1366,768},
			{1440,900},
			{1440,1080},
			{1600,900},
			{1600,1024},
			{1680,1050},
			{1920,1200},
			{1920,1440},
			{2560,1440}
		};
	}
	void updateAllVolumes();
	float m_masterVolume;
	float m_musicVolume;
	float m_sfxVolume;
	sf::Vector2u m_resolution;
	bool m_fullscreen;
	bool m_vsync;
	bool m_blurEffect;
	bool m_particleEffects;
	std::vector<sf::Vector2u> m_availableResolutions;
};