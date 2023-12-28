//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "LabyrinthFramework/AudioManager.h"

namespace labyrinth_engine
{
    AudioManager::AudioManager()
        : m_sfx{}
        , m_sfxPlayer{}
        , m_music{}
        , m_globalVolume{100.0f}
    {

    }

    void AudioManager::LoadSFX(const std::string& a_audioName, const std::string& a_audioPath)
    {
        sf::SoundBuffer buffer;
        if (buffer.loadFromFile(a_audioPath))
        {
            m_sfx[a_audioName] = buffer;
            m_sfxPlayer[a_audioName].setBuffer(m_sfx[a_audioName]);
        }
    }

    void AudioManager::PlaySFX(const std::string& a_audioName)
    {
        auto itteration = m_sfxPlayer.find(a_audioName);
        if (itteration != m_sfxPlayer.end())
        {
            itteration->second.play();
        }
    }

    void AudioManager::StopSFX(const std::string& a_audioName)
    {
        auto itteration = m_sfxPlayer.find(a_audioName);
        if (itteration != m_sfxPlayer.end())
        {
            itteration->second.stop();
        }
    }

    bool AudioManager::LoadMusic(const std::string& a_audioName, const std::string& a_audioPath)
    {
        return m_music[a_audioName].openFromFile(a_audioPath);
    }

    void AudioManager::PlayMusic(const std::string& a_audioName)
    {
        auto itteration = m_music.find(a_audioName);
        if (itteration != m_music.end())
        {
            itteration->second.play();
        }
    }

    void AudioManager::StopMusic(const std::string& a_audioName)
    {
        auto itteration = m_music.find(a_audioName);
        if (itteration != m_music.end())
        {
            itteration->second.stop();
        }
    }

    void AudioManager::SetMusicLoop(const std::string& a_audioName, bool a_bLoop)
    {
        auto itteration = m_music.find(a_audioName);
        if (itteration != m_music.end())
        {
            itteration->second.setLoop(a_bLoop);
        }
    }

    void AudioManager::SetGlobalVolume(float a_volume)
    {
        m_globalVolume = a_volume;
        for (auto& i : m_sfxPlayer)
        {
            i.second.setVolume(m_globalVolume);
        }
        for (auto& i : m_music)
        {
            i.second.setVolume(m_globalVolume);
        }
    }
}
