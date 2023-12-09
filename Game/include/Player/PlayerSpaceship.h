//
// Created by NAT20 on 09/12/2023.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Spaceship/Spaceship.h"

namespace GameFramework
{
    class PlayerSpaceship : public Spaceship
    {
    public:
        PlayerSpaceship(Framework::World* a_owningWorld, const std::string& a_path = "PNG/playerShip1_blue.png");

        void ActorTick(float a_deltaTime) override;

        void SetPlayerSpeed(const float a_speed) { m_playerSpeed = a_speed; }
        float GetPlayerSpeed() const { return m_playerSpeed; }

    private:
        void HandlePlayerInput();
        void HandlePlayerMovementInput(float a_deltaTime);
        sf::Vector2f m_playerMoveInput;
        float m_playerSpeed;
    };

}



#endif //PLAYER_H
