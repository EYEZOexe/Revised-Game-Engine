//
// Created by s5216712 on 11/12/2023.
//

#ifndef ENEMYSPACESHIP_H
#define ENEMYSPACESHIP_H

#include "Spaceship/Spaceship.h"

namespace labyrinth_engine
{
    class EnemySpaceship : public Spaceship
    {
    public:
        EnemySpaceship(World* a_owningWorld, const std::string& a_texturePath, float a_spaceshipCollisionDamage = 200.0f);
        void ActorTick(float a_deltaTime) override;
    private:
        void OnActorBeginOverlap(Actor* m_actor) override;
        float m_spaceshipCollisionDamage;

    };
}




#endif //ENEMYSPACESHIP_H
