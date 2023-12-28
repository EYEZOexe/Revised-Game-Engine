//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef MADMAXGAMESTAGE_H
#define MADMAXGAMESTAGE_H

#include "Gameplay/GameStage.h"
#include <SFML/Graphics.hpp>
#include "..\..\..\LabyrinthEngine\include\LabyrinthFramework\TimeKeeper.h"

namespace labyrinth_engine
{
    class MadMaxGameStage : public GameStage
    {
    public:
        /* Constructors and Destructors */
        MadMaxGameStage(World* a_world);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void StartStage() override; // Called when the stage starts

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void StageEnded() override; // Called when the stage ends
        void SpawnRookie(); // Spawn a rookie enemy
        void SpawnCopyCat(); // Spawn a copy cat enemy
        void SpawnEnforcer(); // Spawn an enforcer enemy
        void SpawnDancer(); // Spawn a dancer enemy

        void IncreaseStageDifficulty(); // Increase the difficulty of the stage
        void StageDurationEnded(); // Increase the difficulty of the stage

        sf::Vector2f GetEnemyRandomSpawnPosition() const; // Get a random spawn position for an enemy
        sf::Vector2f GetEnemyRandomSpawnPositionEdge() const; // Get a random spawn position for an enemy on the left side

        float m_enemySpawnInterval; // Time between spawning enemies
        float m_enemyMinimumSpawnInterval; // Minimum time between spawning enemies

        float m_enemySpawnDecreaseFactor; // Multiplier for decreasing the spawn interval
        float m_enemySpawnDecreaseRate; // Time between decreasing the spawn interval

        float m_madMaxStageDuration; // Duration of the stage

        TimeKeeper m_difficultyIncreaseTimerHandler; // Timer handler for increasing the difficulty
        TimeKeeper m_enemySpawnTimerHandler; // Timer handler for spawning enemies
    };
}

#endif //MADMAXGAMESTAGE_H
