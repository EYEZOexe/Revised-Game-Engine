//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/EnforcerGameStage.h"

#include "Enemy/EnforcerEnemy.h"
#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    EnforcerGameStage::EnforcerGameStage(World* a_world)
        : GameStage{a_world}
        , m_enemySpawnInterval{5.0f}
        , m_enemySpawnOffset{80.0f}
        , m_enemySpawnGroupSize{5}
        , m_enemyCurrentSpawnSize{0}
        , m_enemySpawnPositionLeft{a_world->GetWindowSize().x/2.0f, -100.0f}
        , m_enemySpawnPositionRight{a_world->GetWindowSize().x/2.0f + m_enemySpawnOffset , -100.0f - m_enemySpawnOffset}
        , m_enemySpawnPositionMid{a_world->GetWindowSize().x/2.0f - m_enemySpawnOffset, -100.0f - m_enemySpawnOffset}
    {

    }

    void EnforcerGameStage::StartStage()
    {
        m_enemySpawnTimer = TimeManager::GetInstance().SetTimer(GetWeakReference(), &EnforcerGameStage::SpawnEnemies, m_enemySpawnInterval, true);
    }

    void EnforcerGameStage::StageEnded()
    {
        TimeManager::GetInstance().RemoveTimer(m_enemySpawnTimer);
    }

    void EnforcerGameStage::SpawnEnemies()
    {
        Weak<EnforcerEnemy> newEnforcer = GetWorld()->SpawnActor<EnforcerEnemy>();
        newEnforcer.lock()->SetActorLocation(m_enemySpawnPositionMid);

        newEnforcer = GetWorld()->SpawnActor<EnforcerEnemy>();
        newEnforcer.lock()->SetActorLocation(m_enemySpawnPositionLeft);

        newEnforcer = GetWorld()->SpawnActor<EnforcerEnemy>();
        newEnforcer.lock()->SetActorLocation(m_enemySpawnPositionRight);

        if (++m_enemyCurrentSpawnSize >= m_enemySpawnGroupSize)
        {
            EndStage();
        }
    }
}
