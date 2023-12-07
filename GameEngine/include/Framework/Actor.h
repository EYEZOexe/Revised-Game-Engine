//
// Created by NAT20 on 07/12/2023.
//

#ifndef ACTOR_H
#define ACTOR_H


namespace Framework
{
    class World;

    class Actor
    {
    public:
        Actor(World* a_owningWorld);
        virtual ~Actor();

        void ActorBeginPlayFramework();
        virtual void ActorBeginPlay();

        virtual void ActorTick(float a_deltaTime);

    private:
        World* m_owningWorld;
        bool m_bIsPlaying;
    };
}




#endif //ACTOR_H
