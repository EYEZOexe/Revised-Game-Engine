//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "Framework/Actor.h"
#include "Framework/Core.h"
#include "Framework/AssetManager.h"
#include "Framework/MathUtility.h"
#include "Framework/World.h"

namespace labyrinth_engine
{
    Actor::Actor(World* a_owningWorld, const std::string& a_texturePath)
        : m_owningWorld(a_owningWorld)
        , m_bIsPlaying(false)
        , m_sprite{}
        , m_texture{}
    {
        SetActorTexture(a_texturePath);
    }

    Actor::~Actor()
    {
        GE_LOG("Actor Destroyed");
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
        AssetManager& assetManager = AssetManager::Get();

        m_texture = assetManager.LoadTexture(a_texturePath);
        if (!m_texture) return;

        m_sprite.setTexture(*m_texture); // dereference the texture pointer to get the texture

        const int width = m_texture->getSize().x;
        const int height = m_texture->getSize().y;

        m_sprite.setTextureRect(sf::IntRect{sf::Vector2i{}, sf::Vector2i{width, height}});
        CenterActorOrigin();
    }

    void Actor::Render(sf::RenderWindow& a_window)
    {
        if (IsPendingKill()) //if the actor is pending kill, we don't want to render it
            return;

        a_window.draw(m_sprite);
    }

    void Actor::SetActorLocation(const sf::Vector2f& a_location)
    {
        m_sprite.setPosition(a_location);
    }

    void Actor::SetActorRotation(float a_rotation)
    {
        m_sprite.setRotation(a_rotation);
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

    bool Actor::IsActorOutOfBounds() const
    {
        float windowWidth = GetWorld()->GetWindowSize().x;
        float windowHeight = GetWorld()->GetWindowSize().y;

        float width = GetActorBounds().width;
        float height = GetActorBounds().height;

        sf::Vector2f actorLocation = GetActorLocation();

        if (actorLocation.x < -width)
        {
            return true;
        }

        if (actorLocation.x > windowWidth + width)
        {
            return true;
        }

        if (actorLocation.y < -height)
        {
            return true;
        }

        if (actorLocation.y > windowHeight + height)
        {
            return true;
        }

        return false;
    }

    void Actor::CenterActorOrigin()
    {
        sf::FloatRect bounds = m_sprite.getGlobalBounds();
        m_sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    }
}
