//
// Created by NAT20 on 07/12/2023.
//

#include "Framework/Actor.h"
#include "Framework/Core.h"
#include "Framework/AssetManager.h"

namespace Framework
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
        GE_LOG("Actor Begin Play");
    }

    void Actor::ActorTick(float a_deltaTime)
    {
        GE_LOG("Actor Tick");
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
    }

    void Actor::Render(sf::RenderWindow& a_window)
    {
        if (IsPendingKill()) //if the actor is pending kill, we don't want to render it
            return;

        a_window.draw(m_sprite);
    }
}
