#pragma once
#include "SFML/Audio.hpp"

class SoundManager
{
public:
	void playDamage() { m_collisionSound.play(); }
	void playJump() { m_jumpSound.play(); }

	void playInGameMusic() { m_inGameMusic.play(); }
	void pauseInGameMusic() { m_inGameMusic.pause(); }

	void playTitleMusic() { m_titleMusic.play(); }
	void stopTitleMusic() { m_titleMusic.stop(); }

	void playPause() { m_pauseSound.play(); }
	void playUnpause() { m_unpauseSound.play(); }

	static SoundManager& getInstance()
	{
		static SoundManager instance;
		return instance;
	}

	void setMasterVolume(float volume)
	{
		m_masterVolume = std::clamp(volume, 0.0f, 100.0f);
		updateAllVolumes();
	}
	void setMusicVolume(float volume)
	{
		m_musicVolume = std::clamp(volume, 0.0f, 100.0f);
		updateAllVolumes();
	}

	void setSFXVolume(float volume)
	{
		m_sfxVolume = std::clamp(volume, 0.0f, 100.0f);
		updateAllVolumes();
	}
	void playShoot() { m_shootSound.play(); }
	void playCollision() { m_collisionSound.play(); }
	void playPhaseChange() { m_phaseChangeSound.play(); }

private:
	SoundManager()
		: m_damageBuffer("resources/damage.wav")
		, m_jumpBuffer("resources/jump.wav")
		, m_collisionSound(m_damageBuffer)
		, m_jumpSound(m_jumpBuffer)
		, m_inGameMusic("resources/background_music.ogg")
		, m_titleMusic("resources/title_music.ogg")
		, m_pauseBuffer("resources/pause.wav")
		, m_unpauseBuffer("resources/unpause.wav")
		, m_pauseSound(m_pauseBuffer)
		, m_unpauseSound(m_unpauseBuffer)
		, m_masterVolume(100.0f)
		, m_musicVolume(100.0f)
		, m_sfxVolume(100.0f)
		, m_shootBuffer("resources/shoot.wav")
		, m_phaseChangeBuffer("resources/phase_change.wav")
		, m_shootSound(m_shootBuffer)
		, m_phaseChangeSound(m_phaseChangeBuffer)
	{
		m_inGameMusic.setLooping(true);
	}
	void updateAllVolumes()
	{
		m_inGameMusic.setVolume(m_musicVolume * (m_masterVolume / 100.0f));
		m_titleMusic.setVolume(m_musicVolume * (m_masterVolume / 100.0f));

		m_jumpSound.setVolume(m_sfxVolume * (m_masterVolume / 100.0f));
		m_collisionSound.setVolume(m_sfxVolume * (m_masterVolume / 100.0f));
		m_pauseSound.setVolume(m_sfxVolume * (m_masterVolume / 100.0f));
		m_unpauseSound.setVolume(m_sfxVolume * (m_masterVolume / 100.0f));
	}

	float m_masterVolume;
	float m_musicVolume;
	float m_sfxVolume;
	sf::SoundBuffer m_jumpBuffer;
	sf::SoundBuffer m_damageBuffer;

	sf::SoundBuffer m_pauseBuffer;
	sf::SoundBuffer m_unpauseBuffer;

	sf::Sound m_jumpSound;
	sf::Sound m_collisionSound;

	sf::Sound m_pauseSound;
	sf::Sound m_unpauseSound;

	sf::Music m_inGameMusic;
	sf::Music m_titleMusic;

	sf::SoundBuffer m_shootBuffer;
	sf::SoundBuffer m_phaseChangeBuffer;

	sf::Sound m_shootSound;
	sf::Sound m_phaseChangeSound;
};