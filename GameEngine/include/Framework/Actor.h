//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef ACTOR_H
#define ACTOR_H

#include "SFML/Graphics.hpp"
#include "Framework/Core.h"
#include "Framework/Object.h"


namespace labyrinth_engine
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

        void SetActorLocation(const sf::Vector2f& a_location);
        void SetActorRotation(float a_rotation);
        void AddActorLocationOffset(const sf::Vector2f& a_locationOffset);
        void AddActorRotationOffset(float a_rotationOffset);

        sf::Vector2f GetActorLocation() const { return m_sprite.getPosition();};
        float GetActorRotation() const {return m_sprite.getRotation();};
        sf::Vector2f GetActorForwardVector() const;
        sf::Vector2f GetActorRightVector() const;

        sf::Vector2u GetWindowSize() const;

        World* GetWorld() const { return m_owningWorld; };

    private:
        void CenterActorOrigin();

        World* m_owningWorld;
        bool m_bIsPlaying;

        sf::Sprite m_sprite;
        Sptr<sf::Texture> m_texture;
    };

}




#endif //ACTOR_H
