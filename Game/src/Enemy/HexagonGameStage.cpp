//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Enemy/HexagonGameStage.h"

#include "Enemy/Hexagon.h"
#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    HexagonGameStage::HexagonGameStage(World* a_world)
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

    void HexagonGameStage::StartStage()
    {
        m_enemySpawnTimer = TimeManager::GetInstance().SetTimer(GetWeakReference(), &HexagonGameStage::SpawnEnemies, m_enemySpawnInterval, true);
    }

    void HexagonGameStage::StageEnded()
    {
        TimeManager::GetInstance().RemoveTimer(m_enemySpawnTimer);
    }

    void HexagonGameStage::SpawnEnemies()
    {
        Weak<Hexagon> newHexagon = GetWorld()->SpawnActor<Hexagon>();
        newHexagon.lock()->SetActorLocation(m_enemySpawnPositionMid);

        newHexagon = GetWorld()->SpawnActor<Hexagon>();
        newHexagon.lock()->SetActorLocation(m_enemySpawnPositionLeft);

        newHexagon = GetWorld()->SpawnActor<Hexagon>();
        newHexagon.lock()->SetActorLocation(m_enemySpawnPositionRight);

        if (++m_enemyCurrentSpawnSize >= m_enemySpawnGroupSize)
        {
            EndStage();
        }
    }
}
