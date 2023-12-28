//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef ENFORCERGAMESTAGE_H
#define ENFORCERGAMESTAGE_H
#include "Gameplay/GameStage.h"
#include <SFML/Graphics.hpp>
#include "..\..\..\LabyrinthEngine\include\LabyrinthFramework\TimeKeeper.h"

namespace labyrinth_engine
{
    class EnforcerGameStage : public GameStage
    {
    public:
        /* Constructors and Destructors */
        EnforcerGameStage(World* a_world);
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
        void StageEnded() override;
        void SpawnEnemies();

        float m_enemySpawnInterval;
        float m_enemySpawnOffset;
        int m_enemySpawnGroupSize;
        int  m_enemyCurrentSpawnSize;

        sf::Vector2f m_enemySpawnPositionLeft;
        sf::Vector2f m_enemySpawnPositionRight;
        sf::Vector2f m_enemySpawnPositionMid;

        TimeKeeper m_enemySpawnTimer;
    };
}

#endif //ENFORCERGAMESTAGE_H
