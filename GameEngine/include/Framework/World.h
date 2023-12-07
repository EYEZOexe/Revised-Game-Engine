//
// Created by NAT20 on 07/12/2023.
//

#ifndef WORLD_H
#define WORLD_H


namespace Framework
{
    class Application;

    class World
    {
    public:
        explicit World(Application* a_owningApplication);

        void BeginPlayFramework();
        void WorldTickFramework(float a_deltaTime);

        virtual ~World(); //whenever you need something to be inherited you have a virtual destructor to make sure that the destructor of the child class is called first and then the destructor of the parent class is called

    private:
        void BeginPlay();
        void WorldTick(float a_deltaTime);

        Application* m_owningApplication;
        bool m_bIsPlaying;
    };
}



#endif //WORLD_H
