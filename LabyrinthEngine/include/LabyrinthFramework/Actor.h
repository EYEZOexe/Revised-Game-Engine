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
        void ActorBeginPlayFramework(); // This function is called by the World class when the actor is added to the world and runs the ActorBeginPlay function
        void ActorTickFramework(float a_deltaTime); // This function is called by the World class every frame and runs the ActorTick function
        void Render(sf::RenderWindow& a_window);  // This function is called by the World class every frame and renders the actor
        void AddActorLocationOffset(const sf::Vector2f& a_locationOffset);  // This function is called by the World class every frame and adds the location offset to the actor
        void AddActorRotationOffset(float a_rotationOffset);  // This function is called by the World class every frame and adds the rotation offset to the actor

        EventCallback<Actor*> OnActorDestroy; // This event is called when the actor is destroyed
        /* End of Framework functions */

        /* Boolean functions */
        bool IsHostileTo(const Actor* a_otherActor) const; // This function is called by the World class every frame and checks if the actor is hostile to the other actor
        bool IsActorOutOfBounds(float a_border = 10.0f) const; // This function is called by the World class every frame and checks if the actor is out of bounds
        /* End of Boolean functions */

        /* Virtual functions */
        virtual void ActorBeginPlay();
        virtual void ActorTick(float a_deltaTime);
        virtual void DoDamage(float a_damage); // This function is called by the World class every frame and does damage to the actor
        virtual void OnActorBeginOverlap(Actor* m_actor);  // This function is called by the World class every frame and checks if the actor is overlapping with another actor
        virtual void OnActorEndOverlap(Actor* m_actor); // This function is called by the World class every frame and checks if the actor is not overlapping with another actor
        /* End of Virtual functions */

        /* override functions */
        void Destroy() override; // This function is called by the World class every frame and destroys the actor
        /* End of override functions */

        /* Setters and Getters */

        // Setters
        void SetActorTexture(const std::string& a_texturePath); //Sets the texture of the actor
        void SetActorLocation(const sf::Vector2f& a_location); //Sets the location of the actor
        void SetActorRotation(float a_rotation); //Sets the rotation of the actor
        void SetActorCollisionLayer(const uint8 a_collisionLayer) {m_collisionLayer = a_collisionLayer;} //Sets the collision layer of the actor
        void SetEnableActorPhysics(bool a_bIsEnabled); //Sets the physics of the actor
        // Getters
        sf::Vector2f GetActorForwardVector() const; //Gets the forward vector of the actor
        sf::Vector2f GetActorRightVector() const; //Gets the right vector of the actor
        sf::Vector2f GetActorLocation() const { return m_sprite.getPosition();}
        float GetActorRotation() const {return m_sprite.getRotation();} //Gets the rotation of the actor
        static uint8 GetDefaultCollisionLayer() { return m_defaultCollisionLayer; }
        static uint8 GetPlayerCollisionLayer() { return m_playerCollisionLayer; }
        static uint8 GetEnemyCollisionLayer() { return m_enemyCollisionLayer; }
        uint8 GetCollisionLayer() const { return m_collisionLayer; }
        sf::FloatRect GetActorBounds() const;
        sf::Vector2u GetWindowSize() const;
        const World* GetWorld() const { return m_owningWorld; }
        World* GetWorld() { return m_owningWorld; }
        const sf::Sprite& GetSprite() const { return m_sprite; }
        sf::Sprite& GetSprite() { return m_sprite; }
        /* End of Setters and Getters */

    private:
        void InitialiseActorPhysics(); //Initialises the physics of the actor
        void RemoveActorPhysics(); //Removes the physics of the actor
        void UpdatePhysicsTransform(); //Updates the physics transform of the actor
        void CenterActorOrigin(); //Centers the origin of the actor

        World* m_owningWorld; //The world that the actor is in

        bool m_bIsPlaying; //Checks if the actor is playing
        bool m_bIsPhysicsEnabled; //Checks if the physics of the actor is enabled

        sf::Sprite m_sprite; //The sprite of the actor
        Shared<sf::Texture> m_texture; //The texture of the actor
        b2Body* m_physicsBody; //The physics body of the actor

        uint8 m_collisionLayer; //The collision layer of the actor
        static constexpr uint8 m_defaultCollisionLayer = 255; //The default collision layer of the actor
        static constexpr uint8 m_playerCollisionLayer = 1; //The player collision layer of the actor
        static constexpr uint8 m_enemyCollisionLayer = 2; //The enemy collision layer of the actor
    };

}


#endif //ACTOR_H
