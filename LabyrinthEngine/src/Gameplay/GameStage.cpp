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
        LE_LOG("Stage Updated");
    }

    void GameStage::EndStage()
    {
        onEndStageEvent.Broadcast();
        m_bIsStageFinished = true;
        OnEndStage();
    }

    void GameStage::OnEndStage()
    {
        LE_LOG("Stage Ended");
    }
}
