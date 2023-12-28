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
        ProjectileLauncher(Actor* a_owner, float a_cooldownTime = 1.0f, const sf::Vector2f& a_selfPositionOffset = {0.0f, 0.0f}, float a_selfRotationOffset = {0.0f}, const std::string& a_projectileTexturePath = "PNG/Lasers/laserBlue01.png");
        bool IsOnCooldown() const override;
        void IncreaseLauncherLevel(int a_increaseAmount = 1) override;
        float GetCooldownTime() const {return m_cooldownTime;}
        void SetProjectileTexturePath(const std::string& a_projectileTexturePath) {m_projectileTexturePath = a_projectileTexturePath;}
    private:
        void OnFire() override;
        sf::Clock m_cooldown;
        float m_cooldownTime;
        sf::Vector2f m_selfPositionOffset;
        float m_selfRotationOffset;
        std::string m_projectileTexturePath;
    };
}

#endif //BULLETSHOOTER_H
