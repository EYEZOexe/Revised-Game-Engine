//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/DancerGameStage.h"
#include "LabyrinthFramework/MathUtility.h"
#include "LabyrinthFramework/World.h"
#include "Enemy/DancerEnemy.h"

namespace labyrinth_engine
{
    DancerGameStage::DancerGameStage(World* a_world)
        : GameStage{a_world}
        , m_enemySpawnInterval{4.0f}
        , m_enemySpawnAmount{10}
        , m_enemyCurrentSpawnAmount{0}
        , m_dancerSpeed{200.0f}
    {

    }

    void DancerGameStage::StartStage()
    {
        m_enemySpawnTimer = TimeManager::GetInstance().SetTimer(GetWeakReference(), &DancerGameStage::SpawnEnemies, m_enemySpawnInterval, true);
    }

    void DancerGameStage::StageEnded()
    {
        TimeManager::GetInstance().RemoveTimer(m_enemySpawnTimer);
    }

    sf::Vector2f DancerGameStage::GetRandomSpawnLocation()
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

    void DancerGameStage::SpawnEnemies()
    {
        sf::Vector2f spawnLocation = GetRandomSpawnLocation();
        auto windowSize = GetWorld()->GetWindowSize();

        sf::Vector2f center{windowSize.x/2.0f , windowSize.y/2.0f};
        sf::Vector2f direction{ center.x - spawnLocation.x, center.y - spawnLocation.y};
        NormalizeVector(direction);

        sf::Vector2f spawnVelocity = direction * m_dancerSpeed;


        Weak<DancerEnemy> newDancer = GetWorld()->SpawnActor<DancerEnemy>(spawnVelocity);
        newDancer.lock()->SetActorLocation(spawnLocation);

        if (++m_enemyCurrentSpawnAmount >= m_enemySpawnAmount)
        {
            EndStage();
        }
    }
}
