//
// Created by Tomas Tzorta on 11/12/2023.
//

#include "LabyrinthFramework/TimeManager.h"

namespace labyrinth_engine
{
    Uptr<TimeManager> TimeManager::m_timeManager{nullptr};

    Timer::Timer(Wptr<Object> a_weakObject, std::function<void()> a_function, float a_time, bool a_repeat)
        : m_function{a_weakObject, a_function}
        , m_time{a_time}
        , m_bRepeat{a_repeat}
        , m_currentTime{0.0f}
        , m_bIsFinished{false}
    {

    }

    TimeManager::TimeManager()
        : m_timers{}
    {

    }

    void Timer::Update(float a_deltaTime)
    {
        if (IsFinished()) return;

        m_currentTime += a_deltaTime;

        if (m_currentTime >= m_time)
        {
            m_function.second();
            if (m_bRepeat)
            {
                m_currentTime = 0.0f;
            }
            else
            {
                SetToFinish();
            }
        }
    }

    bool Timer::IsFinished() const
    {
        return m_bIsFinished || m_function.first.expired() || m_function.first.lock()->IsPendingKill();
    }


    void TimeManager::UpdateTimerManager(float a_deltaTime)
    {
        for (Timer& timer : m_timers)
        {
            timer.Update(a_deltaTime);
        }
    }

    TimeManager& TimeManager::GetInstance()
    {
        if (!m_timeManager)
        {
            m_timeManager = Uptr<TimeManager>(new TimeManager{});
        }

        return *m_timeManager;
    }
}
