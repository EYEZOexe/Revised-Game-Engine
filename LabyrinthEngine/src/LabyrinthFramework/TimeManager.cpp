//
// Created by Tomas Tzorta on 11/12/2023.
//

#include "LabyrinthFramework/TimeManager.h"

namespace labyrinth_engine
{
    Uptr<TimeManager> TimeManager::m_timeManager{nullptr};

    TimeManager& TimeManager::GetInstance()
    {
        if (!m_timeManager)
        {
            m_timeManager = Uptr<TimeManager>(new TimeManager{});
        }

        return *m_timeManager;
    }

    TimeManager::TimeManager()
    {

    }
}
