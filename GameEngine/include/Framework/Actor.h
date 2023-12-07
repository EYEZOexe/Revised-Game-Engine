//
// Created by NAT20 on 07/12/2023.
//

#ifndef ACTOR_H
#define ACTOR_H

#include "SFML/Graphics.hpp"
#include "Framework/Core.h"
#include "Framework/Object.h"


namespace Framework
{
    class World;

    class Actor : public Object
    {
    public:
        Actor(World* a_owningWorld, const std::string& a_texturePath = "");
        virtual ~Actor();

        void ActorBeginPlayFramework();
        void ActorTickFramework(float a_deltaTime);
        virtual void ActorBeginPlay();
        virtual void ActorTick(float a_deltaTime);
        void SetActorTexture(const std::string& a_texturePath);
        void Render(sf::RenderWindow& a_window);

    private:
        World* m_owningWorld;
        bool m_bIsPlaying;

        sf::Sprite m_sprite;
        Sptr<sf::Texture> m_texture;
    };
}




#endif //ACTOR_H
