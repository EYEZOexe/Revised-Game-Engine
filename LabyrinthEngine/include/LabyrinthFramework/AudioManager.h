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
        void LoadSFX(const std::string& a_audioName, const std::string& a_audioPath); // Loads a sound effect
        void PlaySFX(const std::string& a_audioName); // Plays a sound effect
        void StopSFX(const std::string& a_audioName); // Stops a sound effect

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetSFXLoop(const std::string& a_audioName, bool a_bLoop); // Sets the loop of a sound effect
        void SetGlobalVolume(float a_volume); // Sets the global volume
        void SetSFXVolume(const std::string& a_audioName, float a_volume); // Sets the volume of a sound effect

        // Getters
        static AudioManager& GetInstance(); // Returns the instance of the audio manager

        /* End of Setters and getters */

    protected:
        AudioManager();
    private:
        Map<std::string, Shared<sf::SoundBuffer>> m_sfx; // Map of sound effects
        Map<std::string, sf::Sound> m_sfxPlayer; // Map of sound effect players
        float m_globalVolume;   // Global volume
        float m_sfxVolume;     // Sound effect volume
        static Unique<AudioManager> audioManager; // Instance of the audio manager
    };
}

#endif //AUDIOMANAGER_H
