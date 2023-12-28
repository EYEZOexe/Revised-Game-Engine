//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef ROOKIEGAMESTAGE_H
#define ROOKIEGAMESTAGE_H

#include "Gameplay/GameStage.h"
#include "..\..\..\LabyrinthEngine\include\LabyrinthFramework\TimeKeeper.h"
#include <SFML/Graphics.hpp>



namespace labyrinth_engine
{
    class RookieGameStage : public GameStage
    {
    public:
        /* Constructors and Destructors */
        RookieGameStage(World* a_world);
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
        float m_enemySpawnInterval; // Time between spawning enemies
        float m_enemySwitchInterval; // Time between switching enemies
        float m_spawnLocationDistanceFromEdge; // Distance from the edge of the screen to spawn enemies

        sf::Vector2f m_enemyLeftSpawnLocation; // Left spawn location
        sf::Vector2f m_enemyRightSpawnLocation; // Right spawn location
        sf::Vector2f m_enemySpawnLocation; // Current spawn location

        TimeKeeper m_spawnTimerHandler; // Timer handler for spawning enemies
        TimeKeeper m_switchTimerHandler; // Timer handler for switching enemies

        int m_enemyRows; // Number of rows of enemies
        int m_enemySpawnCount; // Number of enemies to spawn

        int m_rookieCountPerRow; // Number of rookie enemy to spawn per row
        int m_currentRowRookieCount; // Number of rookie spawned in the current row

        void StageEnded() override;
        void SpawnEnemies();
        void SwitchEnemyRows();
    };
}


#endif //ROOKIEGAMESTAGE_H
