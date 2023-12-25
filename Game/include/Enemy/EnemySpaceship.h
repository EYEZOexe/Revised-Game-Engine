//
// Created by s5216712 on 11/12/2023.
//

#ifndef ENEMYSPACESHIP_H
#define ENEMYSPACESHIP_H

#include "Spaceship/Spaceship.h"
#include "Player/PlayerRewards.h"

namespace labyrinth_engine
{
    class EnemySpaceship : public Spaceship
    {
    public:
        EnemySpaceship(World* a_owningWorld,
            const std::string& a_texturePath,
            float a_spaceshipCollisionDamage = 200.0f,
            float a_rewardSpawnChance = 0.5f,
            const List<RewardInternalFunction> a_rewards =
            {
                CreateHealthReward,
                CreateThreewayShooterReward,
                CreateWiperShooterReward,
                CreateLifeReward
            }
       );
        void ActorTick(float a_deltaTime) override;
        void SetEnemyScoreValue(unsigned int a_scoreValue) { m_scoreValue = a_scoreValue; }
    private:
        void InstantiateReward();
        void OnActorBeginOverlap(Actor* m_actor) override;
        void OnDeath() override;
        List<RewardInternalFunction> m_rewardFunctions;
        float m_spaceshipCollisionDamage;
        float m_rewardSpawnChance;
        unsigned int m_scoreValue;

    };
}




#endif //ENEMYSPACESHIP_H
