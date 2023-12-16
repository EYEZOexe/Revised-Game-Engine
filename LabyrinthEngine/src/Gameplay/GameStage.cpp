//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Gameplay/GameStage.h"
#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/Core.h"

namespace labyrinth_engine
{
    GameStage::GameStage(World* a_world)
        : m_world{a_world}
        , m_bIsStageFinished{false}
    {

    }

    void GameStage::StartStage()
    {
        LE_LOG("Stage Started");
    }

    void GameStage::UpdateStage(float a_deltaTime)
    {
    }

    void GameStage::EndStage()
    {
        m_bIsStageFinished = true;
        StageEnded();
        onEndStageEvent.Broadcast();

    }

    void GameStage::StageEnded()
    {
        LE_LOG("Stage Ended");
    }
}
