//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef TWINBLADEGAMESTAGE_H
#define TWINBLADEGAMESTAGE_H

#include "Gameplay/GameStage.h"
#include "LabyrinthFramework/TimeManager.h"
#include <SFML/Graphics.hpp>

namespace labyrinth_engine
{
    class TwinBladeGameStage : public GameStage
    {
    public:
        /* Constructors and Destructors */
        TwinBladeGameStage(World* a_world);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void StartStage() override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void SpawnEnemy(); // Spawn an enemy
        void FinishStage() override;

        float m_enemySpawnInterval; // Time between spawning enemies
        float m_enemySpawnLocationDistanceFromCenter; // Distance from the center of the screen to spawn enemies

        sf::Vector2f m_enemySpawnLocationLeft; // Left spawn location
        sf::Vector2f m_enemySpawnLocationRight; // Right spawn location
        sf::Vector2f m_enemySpawnLocation; // Current spawn location

        int m_enemySpawnAmount; // Number of enemies to spawn
        int m_enemyCurrentSpawnCount; // Number of enemies to spawn

        TimerHandler m_spawnTimerHandler; // Timer handler for spawning enemies
    };
}


#endif //TWINBLADEGAMESTAGE_H
