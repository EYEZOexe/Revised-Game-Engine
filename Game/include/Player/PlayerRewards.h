//
// Created by Tomas Tzorta on 18/12/2023.
//

#ifndef PLAYERREWARDS_H
#define PLAYERREWARDS_H

#include "LabyrinthFramework/Actor.h"
#include <functional>



namespace labyrinth_engine
{
    class PlayerRewards;

    class PlayerSpaceship;
    using RewardFunction = std::function<void(PlayerSpaceship*)>; // a_rewardFunction is a function that takes a PlayerSpaceship as a parameter and returns void
    using RewardInternalFunction = std::function<Weak<PlayerRewards>(World*)>;

    class PlayerRewards : public Actor
    {
    public:
        /* Constructors and Destructors */
        PlayerRewards(World* a_world, const std::string& a_rewardTexturePath, RewardFunction a_rewardFunction, float a_rewardSpeed = 200.0f);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void ActorBeginPlay() override;
        void ActorTick(float a_deltaTime) override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void OnActorBeginOverlap(Actor* m_actor) override;
        float m_rewardSpeed;
        RewardFunction m_rewardFunction;
    };

    Weak<PlayerRewards> CreateHealthReward(World* a_world);
    Weak<PlayerRewards> CreateThreewayShooterReward(World* a_world);
    Weak<PlayerRewards> CreateWiperShooterReward(World* a_world);
    Weak<PlayerRewards> CreateLifeReward(World* a_world);

    Weak<PlayerRewards> CreateReward(World* a_world, const std::string& a_rewardTexturePath, RewardFunction a_rewardFunction);

    void AddHealthReward(PlayerSpaceship* a_playerSpaceship);
    void AddThreewayShooterReward(PlayerSpaceship* a_playerSpaceship);
    void AddWiperShooterReward(PlayerSpaceship* a_playerSpaceship);
    void AddLifeReward(PlayerSpaceship* a_playerSpaceship);
}

#endif //PLAYERREWARDS_H
