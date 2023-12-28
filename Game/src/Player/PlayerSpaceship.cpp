//
// Created by Tomas Tzorta on 09/12/2023.
//

#include "Player/PlayerSpaceship.h"

#include "LabyrinthFramework/MathUtility.h"
#include "SFML/System.hpp"
#include "Weapon/Launcher.h"
#include "Weapon/ProjectileLauncher.h"

namespace labyrinth_engine
{
    PlayerSpaceship::PlayerSpaceship(World* a_owningWorld, const std::string& a_path)
        : Spaceship{a_owningWorld, a_path}
        , m_playerMoveInput{}
        , m_playerSpeed{200.0f}
        , m_projectileLauncher{new ProjectileLauncher{this, 0.1f, {50.0f, 0.0f}, 0.0f, "ss/Shoot/4.png"}}
        , m_playerInvincibilityFrames{2.0f}
        , m_bIsPlayerInvincible{true}
        , m_playerInvincibilityFrameBlinkInterval{0.5f}
        , m_playerInvincibilityFrameBlinkTime{0.0f}
        , m_playerInvincibilityFrameBlinkReveal{1.0f}
        , m_playerLastTimeFired{0.0f}
    {
        SetActorCollisionLayer(GetPlayerCollisionLayer());
        GetSprite().setScale({3.0f, 3.0f});
    }

    void PlayerSpaceship::ActorTick(const float a_deltaTime)
    {
        Spaceship::ActorTick(a_deltaTime);
        m_playerLastTimeFired += a_deltaTime;
        HandlePlayerInput();
        HandlePlayerMovementInput(a_deltaTime);
        HandlePlayerInvincibilityFrames(a_deltaTime);
    }

    void PlayerSpaceship::Fire()
    {
        if (m_projectileLauncher)
        {
            m_projectileLauncher->Fire();
            if (m_playerLastTimeFired >= m_projectileLauncher->GetCooldownTime())
            {
                AudioManager::GetInstance().PlaySFX("PlayerShoot");
                m_playerLastTimeFired = 0.0f;
            }
        }
    }

    void PlayerSpaceship::SetProjectileLauncher(Unique<ProjectileLauncher>&& a_projectileLauncher)
    {
        if (m_projectileLauncher && typeid(*m_projectileLauncher.get()) == typeid(*a_projectileLauncher.get()))
        {
            m_projectileLauncher->IncreaseLauncherLevel();
            return;
        }

        m_projectileLauncher = std::move(a_projectileLauncher);
    }

    void PlayerSpaceship::DoDamage(float a_damage)
    {
        if (!m_bIsPlayerInvincible)
        {
            Spaceship::DoDamage(a_damage);
        }
    }

    void PlayerSpaceship::ActorBeginPlay()
    {
        Spaceship::ActorBeginPlay();
        TimeManager::GetInstance().SetTimer(GetWeakReference(), &PlayerSpaceship::EndPlayerInvinsibilityFrames, m_playerInvincibilityFrames, false);
    }

    void PlayerSpaceship::HandlePlayerInput()
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_playerMoveInput.y = -1.0f; // Set the player move input to -1 if the W key is pressed
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            m_playerMoveInput.y = 1.0f; // Set the player move input to 1 if the S key is pressed
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_playerMoveInput.x = -1.0f; // Set the player move input to -1 if the A key is pressed
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_playerMoveInput.x = 1.0f; // Set the player move input to 1 if the D key is pressed
        }

        HandlePlayerClampPosition(); // Handle the player clamp position
        NormalisePlayerInput(); // Normalise the player input

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            Fire(); // Fire if the space key is pressed
        }
    }

    void PlayerSpaceship::NormalisePlayerInput()
    {
        NormalizeVector(m_playerMoveInput);
    }

    void PlayerSpaceship::HandlePlayerMovementInput(float a_deltaTime)
    {
        SetSpaceshipVelocity(m_playerMoveInput * m_playerSpeed); // Set the spaceship velocity to the player move input multiplied by the player speed
        m_playerMoveInput.x = m_playerMoveInput.y = 0.0f; // Reset the input
    }

    void PlayerSpaceship::HandlePlayerClampPosition()
    {
        sf::Vector2f playerLocation = GetActorLocation(); // Get the player location
        if (playerLocation.x < 0.0f && m_playerMoveInput.x == -1.0f)
        {
            m_playerMoveInput.x = 0; // Set the player move input to 0 if the player location is less than 0 and the player move input is -1
        }

        if (playerLocation.x > GetWindowSize().x && m_playerMoveInput.x == 1.0f)
        {
            m_playerMoveInput.x = 0.0f; // Set the player move input to 0 if the player location is greater than the window size and the player move input is 1
        }

        if (playerLocation.y < 0.0f && m_playerMoveInput.y == -1)
        {
            m_playerMoveInput.y = 0.0f; // Set the player move input to 0 if the player location is less than 0 and the player move input is -1
        }

        if (playerLocation.y > GetWindowSize().y && m_playerMoveInput.y == 1.0f)
        {
            m_playerMoveInput.y = 0.0f; // Set the player move input to 0 if the player location is greater than the window size and the player move input is 1
        }
    }

    void PlayerSpaceship::EndPlayerInvinsibilityFrames()
    {
        GetSprite().setColor({255, 255, 255, 255}); // Set the player sprite to be visible
        m_bIsPlayerInvincible = false; // Set the player to be not invincible
    }

    void PlayerSpaceship::HandlePlayerInvincibilityFrames(float a_deltaTime)
    {
        if (!m_bIsPlayerInvincible) return;

        m_playerInvincibilityFrameBlinkTime += a_deltaTime * m_playerInvincibilityFrameBlinkReveal; // Add the delta time to the player invincibility frame blink time
        if (m_playerInvincibilityFrameBlinkTime < 0 || m_playerInvincibilityFrameBlinkTime > m_playerInvincibilityFrameBlinkInterval)
        {
            m_playerInvincibilityFrameBlinkReveal *= -1; // Set the player invincibility frame blink reveal to be the opposite
        }

        GetSprite().setColor(InterpolateColour({255, 255, 255, 64}, {255, 255, 255, 128}, m_playerInvincibilityFrameBlinkTime / m_playerInvincibilityFrameBlinkInterval)); // Set the player sprite to be visible
    }
}

