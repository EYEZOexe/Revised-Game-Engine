//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "LabyrinthFramework/Object.h"
#include "LabyrinthFramework/EventCallback.h"


namespace labyrinth_engine
{
    class PlayerSpaceship;
    class World;

    class Player : public Object
    {
    public:
        /* Constructors and Destructors */
        Player();
        /* End of Constructors and Destructors */

        /* Class Functions */
        Weak<PlayerSpaceship> SpawnPlayerSpaceship(World* a_world);
        void IncreasePlayerScore(unsigned int a_playerScore);

        EventCallback<int> OnPlayerLifeChange;
        EventCallback<int> OnPlayerScoreChange;
        EventCallback<> OnPlayerLifeLost;

        // Void Functions
        void IncreasePlayerLives(unsigned int a_playerLives);

        // Boolean Functions

        // Virtual Functions

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters


        // Getters
        Weak<PlayerSpaceship> GetPlayerSpaceship() const {return m_playerSpaceship;}
        unsigned int GetPlayerLives() const {return m_playerLives;}
        unsigned int GetPlayerScore() const {return m_playerScore;}

        /* End of Setters and getters */

    protected:

    private:
        unsigned int m_playerLives;
        unsigned int m_playerScore;
        Weak<PlayerSpaceship> m_playerSpaceship;
    };
}

#endif //PLAYER_H
