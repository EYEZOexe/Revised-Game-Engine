//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/UFOGameStage.h"
#include "LabyrinthFramework/MathUtility.h"
#include "LabyrinthFramework/World.h"
#include "Enemy/UFO.h"

namespace labyrinth_engine
{
    UFOGameStage::UFOGameStage(World* a_world)
        : GameStage{a_world}
        , m_enemySpawnInterval{4.0f}
        , m_enemySpawnAmount{10}
        , m_enemyCurrentSpawnAmount{0}
        , m_ufoSpeed{200.0f}
    {

    }

    void UFOGameStage::StartStage()
    {
        m_enemySpawnTimer = TimeManager::GetInstance().SetTimer(GetWeakReference(), &UFOGameStage::SpawnEnemies, m_enemySpawnInterval, true);
    }

    void UFOGameStage::StageEnded()
    {
        TimeManager::GetInstance().RemoveTimer(m_enemySpawnTimer);
    }

    sf::Vector2f UFOGameStage::GetRandomSpawnLocation()
    {
        auto windowSize = GetWorld()->GetWindowSize();
        float enemySpawnLeft = RandomFloat(-1, 1);
        float EnemySpawnLeftX = 0;
        if (enemySpawnLeft < 0)
        {
            EnemySpawnLeftX = windowSize.x + 100;
        }
        else
        {
            EnemySpawnLeftX = -100;
        }

        float EnemySpawnLeftY = RandomFloat(0, windowSize.y);
        return {EnemySpawnLeftX, EnemySpawnLeftY};

    }

    void UFOGameStage::SpawnEnemies()
    {
        sf::Vector2f spawnLocation = GetRandomSpawnLocation();
        auto windowSize = GetWorld()->GetWindowSize();

        sf::Vector2f center{windowSize.x/2.0f , windowSize.y/2.0f};
        sf::Vector2f direction{ center.x - spawnLocation.x, center.y - spawnLocation.y};
        NormalizeVector(direction);

        sf::Vector2f spawnVelocity = direction * m_ufoSpeed;


        Weak<UFO> newUFO = GetWorld()->SpawnActor<UFO>(spawnVelocity);
        newUFO.lock()->SetActorLocation(spawnLocation);

        if (++m_enemyCurrentSpawnAmount >= m_enemySpawnAmount)
        {
            EndStage();
        }
    }
}
