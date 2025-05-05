#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SoundManager.h"
#include "WindowManager.h"
#include <vector>
#include <fstream>
#include <iostream>

class GameOptions {
public:
    static GameOptions& getInstance() {
        static GameOptions instance;
        return instance;
    }

    void setMasterVolume(float volume);
    void setMusicVolume(float volume);
    void setSFXVolume(float volume);
    void setResolution(unsigned int width, unsigned int height);
    void setFullscreen(bool enabled);
    void setVSync(bool enabled);
    void setBlurEffect(bool enabled);
    void setParticleEffects(bool enabled);

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
    void loadSettings();
    void saveSettings();

private:
    GameOptions();
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