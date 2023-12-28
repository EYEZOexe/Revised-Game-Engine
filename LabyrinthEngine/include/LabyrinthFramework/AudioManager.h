//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <SFML/Audio.hpp>
#include "LabyrinthFramework/Core.h"

namespace labyrinth_engine
{
    class AudioManager
    {
    public:
        /* Constructors and Destructors */
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions
        void LoadSFX(const std::string& a_audioName, const std::string& a_audioPath);
        void PlaySFX(const std::string& a_audioName);
        void StopSFX(const std::string& a_audioName);
        bool LoadMusic(const std::string& a_audioName, const std::string& a_audioPath);
        void PlayMusic(const std::string& a_audioName);
        void StopMusic(const std::string& a_audioName);

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetMusicLoop(const std::string& a_audioName, bool a_bLoop);
        void SetGlobalVolume(float a_volume);

        // Getters
        static AudioManager& GetInstance();

        /* End of Setters and getters */

    protected:
        AudioManager();
    private:
        Map<std::string, Shared<sf::SoundBuffer>> m_sfx;
        Map<std::string, sf::Sound> m_sfxPlayer;
        Map<std::string, sf::Music> m_music;
        float m_globalVolume;
        static Unique<AudioManager> audioManager;
    };
}

#endif //AUDIOMANAGER_H
