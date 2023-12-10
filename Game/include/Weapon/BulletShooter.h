//
// Created by NAT20 on 09/12/2023.
//

#ifndef BULLETSHOOTER_H
#define BULLETSHOOTER_H

#include <SFML/System.hpp>
#include "ProjectileLauncher.h"

namespace GameFramework
{
    class BulletShooter : public ProjectileLauncher
    {
    public:
        BulletShooter(Framework::Actor* a_owner, float a_cooldownTime = 1.0f);
        bool IsOnCooldown() const override;
    private:
        void OnFire() override;
        sf::Clock m_cooldown;
        float m_cooldownTime;
    };
}

#endif //BULLETSHOOTER_H
