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

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetSFXLoop(const std::string& a_audioName, bool a_bLoop);
        void SetGlobalVolume(float a_volume);
        void SetSFXVolume(const std::string& a_audioName, float a_volume);

        // Getters
        static AudioManager& GetInstance();

        /* End of Setters and getters */

    protected:
        AudioManager();
    private:
        Map<std::string, Shared<sf::SoundBuffer>> m_sfx;
        Map<std::string, sf::Sound> m_sfxPlayer;
        float m_globalVolume;
        float m_sfxVolume;
        static Unique<AudioManager> audioManager;
    };
}

#endif //AUDIOMANAGER_H
