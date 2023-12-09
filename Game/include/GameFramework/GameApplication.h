//
// Created by NAT20 on 07/12/2023.
//

#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include "Framework/Application.h"
#include "Framework/Core.h"

namespace GameFramework
{
    class PlayerSpaceship;

    class GameApplication : public Framework::Application
    {
    public:
        GameApplication();
        virtual void Tick(float a_deltaTime) override;
    private:
        float m_counter;
        Framework::Wptr<PlayerSpaceship> testPlayerSpaceship;
    };
}



#endif //GAMEAPPLICATION_H
