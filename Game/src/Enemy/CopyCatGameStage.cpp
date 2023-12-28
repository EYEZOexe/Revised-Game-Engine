//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/CopyCatGameStage.h"

#include "Enemy/CopyCatEnemy.h"
#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    CopyCatGameStage::CopyCatGameStage(World* a_world)
        : GameStage{a_world}
        , m_enemySpawnInterval{1.5f}
        , m_enemySpawnLocationDistanceFromCenter{100.0f}
        , m_enemySpawnLocationLeft{a_world->GetWindowSize().x/2.0f - m_enemySpawnLocationDistanceFromCenter, -100}
        , m_enemySpawnLocationRight{a_world->GetWindowSize().x/2.0f + m_enemySpawnLocationDistanceFromCenter, -100}
        , m_enemySpawnLocation{m_enemySpawnLocationLeft}
        , m_enemySpawnAmount{10}
        , m_enemyCurrentSpawnCount{0}
    {
    }

    void CopyCatGameStage::StartStage()
    {
        m_spawnTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &CopyCatGameStage::SpawnEnemy, m_enemySpawnInterval, true);
    }

    void CopyCatGameStage::SpawnEnemy()
    {
        Weak<CopyCatEnemy> newTwinBlade = GetWorld()->SpawnActor<CopyCatEnemy>();
        newTwinBlade.lock()->SetActorLocation(m_enemySpawnLocation);

        if (m_enemySpawnLocation == m_enemySpawnLocationLeft)
        {
            m_enemySpawnLocation = m_enemySpawnLocationRight;
        }
        else
        {
            m_enemySpawnLocation = m_enemySpawnLocationLeft;
        }

        ++m_enemyCurrentSpawnCount;
        if (m_enemyCurrentSpawnCount == m_enemySpawnAmount)
        {
            EndStage();
        }
    }

    void CopyCatGameStage::StageEnded()
    {
        TimeManager::GetInstance().RemoveTimer(m_spawnTimerHandler);
    }
}
