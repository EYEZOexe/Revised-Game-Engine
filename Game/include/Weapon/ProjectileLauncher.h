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
        ProjectileLauncher(Actor* a_owner, float a_cooldownTime = 1.0f, const sf::Vector2f& a_selfPositionOffset = {0.0f, 0.0f}, float a_selfRotationOffset = {0.0f}, const std::string& a_projectileTexturePath = "ss/Shoot/3.png");
        bool IsOnCooldown() const override; // Returns true if the launcher is on cooldown
        void IncreaseLauncherLevel(int a_increaseAmount = 1) override; // Increases the launcher level by the amount specified
        float GetCooldownTime() const {return m_cooldownTime;} // Returns the cooldown time
        void SetProjectileTexturePath(const std::string& a_projectileTexturePath) {m_projectileTexturePath = a_projectileTexturePath;} // Sets the projectile texture path
    private:
        void OnFire() override; // Fires the projectile
        sf::Clock m_cooldown; // Clock for the cooldown
        float m_cooldownTime; // Cooldown time
        sf::Vector2f m_selfPositionOffset; // Offset for the projectile spawn position
        float m_selfRotationOffset; // Offset for the projectile spawn rotation
        std::string m_projectileTexturePath; // Projectile texture path
    };
}

#endif //BULLETSHOOTER_H
