//
// Created by Tomas Tzorta on 24/12/2023.
//

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "Player.h"
#include "LabyrinthFramework/Core.h"

namespace labyrinth_engine
{
    class PlayerManager
    {
    public:
        Player& AddPlayer();
        Player* GetPlayer(int a_playerIndex = 0);
        const Player* GetPlayer(int a_playerIndex = 0) const;
        static PlayerManager& GetInstance();
    protected:
        PlayerManager();

    private:
        List<Player> m_players;
        static Unique<PlayerManager> playerManager;
    };
}

#endif //PLAYERMANAGER_H
