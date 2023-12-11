//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include "Core.h"
#include "Object.h"

class b2Body;

namespace labyrinth_engine
{
    class World;

    class Actor : public Object
    {
    public:
        /* Constructors and Destructors */
        Actor(World* a_owningWorld, const std::string& a_texturePath = "");
        virtual ~Actor();
        /* End of Constructors and Destructors */

        /* Framework functions */
        void ActorBeginPlayFramework();
        void ActorTickFramework(float a_deltaTime);
        void Render(sf::RenderWindow& a_window);
        void AddActorLocationOffset(const sf::Vector2f& a_locationOffset);
        void AddActorRotationOffset(float a_rotationOffset);
        /* End of Framework functions */

        /* Boolean functions */
        bool IsHostileTo(const Actor* a_otherActor) const;
        bool IsActorOutOfBounds(float a_border = 10.0f) const;
        /* End of Boolean functions */

        /* Virtual functions */
        virtual void ActorBeginPlay();
        virtual void ActorTick(float a_deltaTime);
        virtual void DoDamage(float a_damage);
        virtual void OnActorBeginOverlap(Actor* m_actor);
        virtual void OnActorEndOverlap(Actor* m_actor);
        /* End of Virtual functions */

        /* override functions */
        void Destroy() override;
        /* End of override functions */

        /* Setters and Getters */

        // Setters
        void SetActorTexture(const std::string& a_texturePath);
        void SetActorLocation(const sf::Vector2f& a_location);
        void SetActorRotation(float a_rotation);
        void SetActorCollisionLayer(const uint8 a_collisionLayer) {m_collisionLayer = a_collisionLayer;}
        void SetEnableActorPhysics(bool a_bIsEnabled);
        // Getters
        sf::Vector2f GetActorForwardVector() const;
        sf::Vector2f GetActorRightVector() const;
        sf::Vector2f GetActorLocation() const { return m_sprite.getPosition();}
        float GetActorRotation() const {return m_sprite.getRotation();};
        static uint8 GetDefaultCollisionLayer() { return m_defaultCollisionLayer; };
        static uint8 GetPlayerCollisionLayer() { return m_playerCollisionLayer; };
        static uint8 GetEnemyCollisionLayer() { return m_enemyCollisionLayer; };
        uint8 GetCollisionLayer() const { return m_collisionLayer; };
        sf::FloatRect GetActorBounds() const;
        sf::Vector2u GetWindowSize() const;
        const World* GetWorld() const { return m_owningWorld; };
        World* GetWorld() { return m_owningWorld; };
        const sf::Sprite& GetSprite() const { return m_sprite; };
        sf::Sprite& GetSprite() { return m_sprite; };
        /* End of Setters and Getters */

    private:
        void InitialiseActorPhysics();
        void RemoveActorPhysics();
        void UpdatePhysicsTransform();
        void CenterActorOrigin();

        World* m_owningWorld;

        bool m_bIsPlaying;
        bool m_bIsPhysicsEnabled;

        sf::Sprite m_sprite;
        Sptr<sf::Texture> m_texture;
        b2Body* m_physicsBody;

        uint8 m_collisionLayer;
        static constexpr uint8 m_defaultCollisionLayer = 255;
        static constexpr uint8 m_playerCollisionLayer = 1;
        static constexpr uint8 m_enemyCollisionLayer = 2;
    };

}


#endif //ACTOR_H
