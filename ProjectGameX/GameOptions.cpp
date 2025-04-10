#include "GameOptions.h"

GameOptions::GameOptions() :
    m_masterVolume(75.0f),
    m_musicVolume(50.0f),
    m_sfxVolume(75.0f),
    m_resolution(1920, 1080),
    m_fullscreen(false),
    m_vsync(true),
    m_blurEffect(true),
    m_particleEffects(true) {
    // Ініціалізація доступних розширень
    m_availableResolutions = {
        {800, 600}, {1024, 768}, {1280, 720}, {1280, 1024},
        {1360, 768}, {1366, 768}, {1440, 900}, {1600, 900},
        {1680, 1050}, {1920, 1080}, {1920, 1200}, {2560, 1440}
    };
}

void GameOptions::setMasterVolume(float volume) {
    m_masterVolume = std::clamp(volume, 0.0f, 100.0f);
    updateAllVolumes();
}

void GameOptions::setMusicVolume(float volume) {
    m_musicVolume = std::clamp(volume, 0.0f, 100.0f);
    updateAllVolumes();
}

void GameOptions::setSFXVolume(float volume) {
    m_sfxVolume = std::clamp(volume, 0.0f, 100.0f);
    updateAllVolumes();
}

void GameOptions::setResolution(unsigned int width, unsigned int height) {
    m_resolution = { width, height };
}

void GameOptions::setFullscreen(bool enabled) {
    m_fullscreen = enabled;
}

void GameOptions::setVSync(bool enabled) {
    m_vsync = enabled;
}

void GameOptions::setBlurEffect(bool enabled) {
    m_blurEffect = enabled;
}

void GameOptions::setParticleEffects(bool enabled) {
    m_particleEffects = enabled;
}

void GameOptions::applyVideoSettings(sf::RenderWindow& window) {
    sf::VideoMode newMode;
    if (m_fullscreen) {
        newMode = sf::VideoMode::getDesktopMode();
        m_resolution = { newMode.size.x, newMode.size.y };
    }
    else {
        newMode = sf::VideoMode({ m_resolution.x, m_resolution.y });
    }

    window.close();
    window.create(newMode, "ProjectGameX",
        m_fullscreen ? sf::State::Fullscreen : sf::State::Windowed);
    window.setVerticalSyncEnabled(m_vsync);

    sf::View newView(sf::FloatRect({ 0, 0 },
        { static_cast<float>(window.getSize().x),
        static_cast<float>(window.getSize().y) }));
    window.setView(newView);
    WindowManager::getInstance().notifyResize(window.getSize());
}

void GameOptions::updateAllVolumes() {
    SoundManager::getInstance().setMasterVolume(m_masterVolume);
    SoundManager::getInstance().setMusicVolume(m_musicVolume);
    SoundManager::getInstance().setSFXVolume(m_sfxVolume);
}

void GameOptions::loadSettings() {
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
                m_vsync = (line.substr(6) == "On");
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
    updateAllVolumes();
}

void GameOptions::saveSettings() {
    std::ofstream outFile("settings.txt");
    if (outFile.is_open())
    {
        outFile << "MasterVolume=" << m_masterVolume << "\n";
        outFile << "MusicVolume=" << m_musicVolume << "\n";
        outFile << "SFXVolume=" << m_sfxVolume << "\n";
        outFile << "Resolution=" << m_resolution.x << "x" << m_resolution.y << "\n";
        outFile << "Fullscreen=" << (m_fullscreen ? "On" : "Off") << "\n";
        outFile << "VSync=" << (m_vsync ? "On" : "Off") << "\n";
        outFile << "BlurEffect=" << (m_blurEffect ? "On" : "Off") << "\n";
        outFile << "ParticleEffects=" << (m_particleEffects ? "On" : "Off") << "\n";

        outFile.close();
    }
}