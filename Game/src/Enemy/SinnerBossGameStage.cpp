//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "Enemy/SinnerBossGameStage.h"
#include "Enemy/Sinner.h"
#include "LabyrinthFramework/Actor.h"

namespace labyrinth_engine
{
    SinnerBossGameStage::SinnerBossGameStage(World* a_world)
        : GameStage{a_world}
    {

    }

    void SinnerBossGameStage::StartStage()
    {
        Weak<Sinner> sinner = GetWorld()->SpawnActor<Sinner>();
        auto windowSize = GetWorld()->GetWindowSize();
        sinner.lock()->SetActorLocation({windowSize.x / 2.0f, 200.0f});
        sinner.lock()->OnActorDestroy.Bind(GetWeakReference(), &SinnerBossGameStage::FinalEnemyDestroyed);
    }

    void SinnerBossGameStage::FinalEnemyDestroyed(Actor* a_actor)
    {
        EndStage();
    }
}
