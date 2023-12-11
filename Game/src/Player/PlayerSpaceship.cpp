//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Player/PlayerSpaceship.h"

#include "LabyrinthFramework/MathUtility.h"
#include "SFML/System.hpp"
#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    PlayerSpaceship::PlayerSpaceship(World* a_owningWorld, const std::string& a_path)
        : Spaceship{a_owningWorld, a_path}
        , m_playerMoveInput{}
        , m_playerSpeed{200.0f}
        , m_projectileLauncher{new ProjectileLauncher{this, 0.1f}}
    {
        SetActorCollisionLayer(GetPlayerCollisionLayer());
    }

    void PlayerSpaceship::ActorTick(const float a_deltaTime)
    {
        Spaceship::ActorTick(a_deltaTime);
        HandlePlayerInput();
        HandlePlayerMovementInput(a_deltaTime);
    }

    void PlayerSpaceship::Fire()
    {
        if (m_projectileLauncher)
        {
            m_projectileLauncher->Fire();
        }
    }

    void PlayerSpaceship::HandlePlayerInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_playerMoveInput.y = -1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_playerMoveInput.y = 1.0f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_playerMoveInput.x = -1.0f;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_playerMoveInput.x = 1.0f;
        }

        HandlePlayerClampPosition();
        NormalisePlayerInput();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Fire();
        }
    }

    void PlayerSpaceship::NormalisePlayerInput()
    {
        NormalizeVector(m_playerMoveInput);
    }

    void PlayerSpaceship::HandlePlayerMovementInput(float a_deltaTime)
    {
        SetVelocity(m_playerMoveInput * m_playerSpeed);
        m_playerMoveInput.x = m_playerMoveInput.y = 0.0f; // Reset the input
    }

    void PlayerSpaceship::HandlePlayerClampPosition()
    {
        sf::Vector2f playerLocation = GetActorLocation();
        if (playerLocation.x < 0.0f && m_playerMoveInput.x == -1.0f)
        {
            m_playerMoveInput.x = 0;
        }

        if (playerLocation.x > GetWindowSize().x && m_playerMoveInput.x == 1.0f)
        {
            m_playerMoveInput.x = 0.0f;
        }

        if (playerLocation.y < 0.0f && m_playerMoveInput.y == -1)
        {
            m_playerMoveInput.y = 0.0f;
        }

        if (playerLocation.y > GetWindowSize().y && m_playerMoveInput.y == 1.0f)
        {
            m_playerMoveInput.y = 0.0f;
        }
    }
}

