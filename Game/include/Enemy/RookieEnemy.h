//
// Created by s5216712 on 11/12/2023.
//

#ifndef VANGUARD_H
#define VANGUARD_H
#include "EnemySpaceship.h"

namespace labyrinth_engine
{
    class ProjectileLauncher;
    class RookieEnemy : public EnemySpaceship
    {
    public:
        RookieEnemy(World* a_owningWorld, const std::string& a_texturePath = "PNG/Enemies/enemyBlue1.png", const sf::Vector2f& a_velocity = {0.0f, 150.0f});
        void ActorTick(float a_deltaTime) override;
    private:
        void Fire() override;
        Unique<ProjectileLauncher> m_projectileLauncher;
    };
}



#endif //VANGUARD_H
