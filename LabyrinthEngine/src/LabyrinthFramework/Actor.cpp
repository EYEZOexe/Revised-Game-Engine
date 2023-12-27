//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "box2d/b2_body.h"

#include "LabyrinthFramework/Actor.h"
#include "LabyrinthFramework/Core.h"
#include "LabyrinthFramework/AssetManager.h"
#include "LabyrinthFramework/MathUtility.h"
#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/PhysicsSystem.h"

namespace labyrinth_engine
{
    Actor::Actor(World* a_owningWorld, const std::string& a_texturePath)
        : m_owningWorld(a_owningWorld)
        , m_bIsPlaying(false)
        , m_sprite{}
        , m_texture{}
        , m_physicsBody{nullptr}
        , m_bIsPhysicsEnabled{false}
        , m_collisionLayer{GetDefaultCollisionLayer()}
    {
        SetActorTexture(a_texturePath);

    }

    Actor::~Actor()
    {

    }

    void Actor::ActorBeginPlayFramework()
    {
        if (!m_bIsPlaying)
        {
            m_bIsPlaying = true;
            ActorBeginPlay();
        }
    }

    void Actor::ActorTickFramework(const float a_deltaTime)
    {
        if (!IsPendingKill())
        {
            ActorTick(a_deltaTime);
        }
    }

    void Actor::ActorBeginPlay()
    {

    }

    void Actor::ActorTick(float a_deltaTime)
    {

    }

    void Actor::SetActorTexture(const std::string& a_texturePath)
    {
        AssetManager& assetManager = AssetManager::GetInstance();

        m_texture = assetManager.LoadTexture(a_texturePath);
        if (!m_texture) return;

        m_sprite.setTexture(*m_texture); // dereference the texture pointer to get the texture

        const int width = m_texture->getSize().x;
        const int height = m_texture->getSize().y;

        m_sprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{width, height}});
        CenterActorOrigin();
    }

    void Actor::Render(SDL_Window& a_window)
    {
        if (IsPendingKill()) //if the actor is pending kill, we don't want to render it
            return;


        //a_window.draw(m_sprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f& a_location)
    {
        m_sprite.setPosition(a_location);
        UpdatePhysicsTransform();
    }

    void Actor::SetActorRotation(float a_rotation)
    {
        m_sprite.setRotation(a_rotation);
        UpdatePhysicsTransform();
    }

    void Actor::AddActorLocationOffset(const sf::Vector2f& a_locationOffset)
    {
        SetActorLocation(GetActorLocation() + a_locationOffset);
    }

    void Actor::AddActorRotationOffset(float a_rotationOffset)
    {
        SetActorRotation(GetActorRotation() + a_rotationOffset);
    }

    sf::Vector2f Actor::GetActorForwardVector() const
    {
        return RotationToVector(GetActorRotation() - 90.0f);
    }

    sf::Vector2f Actor::GetActorRightVector() const
    {
        return RotationToVector(GetActorRotation());
    }

    sf::FloatRect Actor::GetActorBounds() const
    {
        return m_sprite.getGlobalBounds();
    }

    sf::Vector2u Actor::GetWindowSize() const
    {
        return m_owningWorld->GetWindowSize();
    }

    bool Actor::IsHostileTo(const Actor* a_otherActor) const
    {
        if (a_otherActor == nullptr) return false;

        if (GetCollisionLayer() == GetDefaultCollisionLayer() || a_otherActor->GetCollisionLayer() == GetDefaultCollisionLayer())
        {
            return false;
        }

        return GetCollisionLayer() != a_otherActor->GetCollisionLayer();
    }

    void Actor::DoDamage(float a_damage)
    {

    }

    bool Actor::IsActorOutOfBounds(float a_border) const
    {
        float windowWidth = GetWorld()->GetWindowSize().x;
        float windowHeight = GetWorld()->GetWindowSize().y;

        float width = GetActorBounds().width;
        float height = GetActorBounds().height;

        sf::Vector2f actorLocation = GetActorLocation();

        if (actorLocation.x < -width - a_border)
        {
            return true;
        }

        if (actorLocation.x > windowWidth + width + a_border)
        {
            return true;
        }

        if (actorLocation.y < -height - a_border)
        {
            return true;
        }

        if (actorLocation.y > windowHeight + height + a_border)
        {
            return true;
        }

        return false;
    }

    void Actor::SetEnableActorPhysics(const bool a_bIsEnabled)
    {
        m_bIsPhysicsEnabled = a_bIsEnabled;

        if (m_bIsPhysicsEnabled)
        {
            InitialiseActorPhysics();
        }
        else
        {
            RemoveActorPhysics();
        }

    }

    void Actor::OnActorBeginOverlap(Actor* m_actor)
    {
    }

    void Actor::OnActorEndOverlap(Actor* m_actor)
    {
    }

    void Actor::Destroy()
    {
        RemoveActorPhysics();
        OnActorDestroy.Broadcast(this);
        Object::Destroy();
    }

    void Actor::InitialiseActorPhysics()
    {
        if (!m_physicsBody)
        {
           m_physicsBody = PhysicsSystem::GetInstance().AddListener(this); //add actor to physics world
        }
    }

    void Actor::RemoveActorPhysics()
    {
        if (m_physicsBody)
        {
           PhysicsSystem::GetInstance().RemoveListener(m_physicsBody); //remove actor from physics world
           m_physicsBody = nullptr;
        }
    }

    void Actor::UpdatePhysicsTransform()
    {
        if (m_physicsBody)
        {
            float physicsScale = PhysicsSystem::GetInstance().GetPhysicsScale();
            b2Vec2 physicsPosition{GetActorLocation().x * physicsScale, GetActorLocation().y * physicsScale};
            float physicsRotation = DegreesToradians(GetActorRotation());

            m_physicsBody->SetTransform(physicsPosition, physicsRotation);
        }
    }

    void Actor::CenterActorOrigin()
    {
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        m_sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    }
}
