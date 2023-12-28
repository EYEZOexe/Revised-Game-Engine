//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "Enemy/Sinner.h"

namespace labyrinth_engine
{
    Sinner::Sinner(World* a_world)
        : EnemySpaceship{a_world, "ss/Ship/7.png"}
        , m_sinnerSpeed{100.0f}
        , m_sinnerEdgeBoundaries{100.0f}
    {
        GetSprite().setScale({4.0f, 4.0f});
    }

    void Sinner::ActorTick(float a_deltaTime)
    {
        EnemySpaceship::ActorTick(a_deltaTime);

    }
}
