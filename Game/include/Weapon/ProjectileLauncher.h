//
// Created by Tomas Tzorta on 09/12/2023.
//

#ifndef BULLETSHOOTER_H
#define BULLETSHOOTER_H

#include <SFML/System.hpp>
#include "Launcher.h"

namespace labyrinth_engine
{
    class ProjectileLauncher : public Launcher
    {
    public:
        ProjectileLauncher(Actor* a_owner, float a_cooldownTime = 1.0f, const sf::Vector2f& a_selfPositionOffset = {0.0f, 0.0f}, float a_selfRotationOffset = {0.0f});
        bool IsOnCooldown() const override;
    private:
        void OnFire() override;
        sf::Clock m_cooldown;
        float m_cooldownTime;
        sf::Vector2f m_selfPositionOffset;
        float m_selfRotationOffset;
    };
}

#endif //BULLETSHOOTER_H
