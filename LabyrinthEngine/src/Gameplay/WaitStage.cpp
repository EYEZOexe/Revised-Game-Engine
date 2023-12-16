//
// Created by Tomas Tzorta on 16/12/2023.
//

#include "Gameplay/WaitStage.h"
#include "LabyrinthFramework/TimeManager.h"

namespace labyrinth_engine
{
    WaitStage::WaitStage(World* a_world, float a_waitDuration)
        : GameStage(a_world)
        , m_waitDuration(a_waitDuration)
    {

    }

    void WaitStage::StartStage()
    {
        TimeManager::GetInstance().SetTimer(GetWeakReference(), &WaitStage::EndStage, m_waitDuration);
    }
}
