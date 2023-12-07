//
// Created by NAT20 on 07/12/2023.
//

#ifndef GAMEAPPLICATION_H
#define GAMEAPPLICATION_H

#include "Framework/Application.h"
#include "Framework/Core.h"

namespace GameFramework
{
    class Actor;

    class GameApplication : public Framework::Application
    {
    public:
        GameApplication();
        virtual void Tick(float a_deltaTime) override;
    private:
        float m_counter;
        Framework::Wptr<Framework::Actor> m_actorToDestroy;
    };
}



#endif //GAMEAPPLICATION_H
