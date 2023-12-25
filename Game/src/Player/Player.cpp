//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "Player/Player.h"
#include "LabyrinthFramework/World.h"
#include "Player/PlayerSpaceship.h"

namespace labyrinth_engine
{
    Player::Player()
        : m_playerLives{3}
        , m_playerScore{0}
        , m_playerSpaceship{}
    {

    }

    Weak<PlayerSpaceship> Player::SpawnPlayerSpaceship(World* a_world)
    {
        if (m_playerLives > 0)
        {
            --m_playerLives;
            auto windowSize = a_world->GetWindowSize();
            m_playerSpaceship = a_world->SpawnActor<PlayerSpaceship>();
            m_playerSpaceship.lock()->SetActorLocation(sf::Vector2f(windowSize.x / 2.0f, windowSize.y - 50.0f));
            OnPlayerLifeChange.Broadcast(m_playerLives);
            return m_playerSpaceship;
        }
        else
        {
            m_playerSpaceship = Weak<PlayerSpaceship>{};
            OnPlayerLifeLost.Broadcast();
        }
        return Weak<PlayerSpaceship>{};
    }

    void Player::IncreasePlayerScore(unsigned a_playerScore)
    {
        if (a_playerScore > 0)
        {
            m_playerScore += a_playerScore;
            OnPlayerScoreChange.Broadcast(m_playerScore);
        }
    }

    void Player::IncreasePlayerLives(unsigned a_playerLives)
    {
        if (a_playerLives > 0)
        {
            m_playerLives += a_playerLives;
            OnPlayerLifeChange.Broadcast(m_playerLives);
        }

    }
}
