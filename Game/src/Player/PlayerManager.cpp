//
// Created by Tomas Tzorta on 24/12/2023.
//

#include "Player/PlayerManager.h"

namespace labyrinth_engine
{
    Unique<PlayerManager> PlayerManager::playerManager{nullptr};

    PlayerManager::PlayerManager()
    {

    }

    Player& PlayerManager::AddPlayer()
    {
        m_players.emplace(m_players.begin(), Player()); // Add a new player to the front of the list using emplace which is more efficient than push_back
        return m_players.back(); // Return the newly added player
    }

    Player* PlayerManager::GetPlayer(int a_playerIndex)
    {
        if (a_playerIndex >= 0 && a_playerIndex <= m_players.size())
        {
            return &(m_players[a_playerIndex]);
        }

        return nullptr;
    }

    const Player* PlayerManager::GetPlayer(int a_playerIndex) const
    {
        if (a_playerIndex >= 0 && a_playerIndex <= m_players.size())
        {
            return &(m_players[a_playerIndex]);
        }

        return nullptr;
    }

    PlayerManager& PlayerManager::GetInstance()
    {
        if (playerManager == nullptr)
        {
            playerManager = std::move(Unique<PlayerManager>{new PlayerManager{}});
        }
        return *playerManager;
    }
}
