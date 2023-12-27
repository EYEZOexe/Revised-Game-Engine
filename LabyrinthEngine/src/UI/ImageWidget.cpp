//
// Created by Tomas Tzorta on 25/12/2023.
//

#include "UI/ImageWidget.h"
#include "LabyrinthFramework/AssetManager.h"

namespace labyrinth_engine
{
    ImageWidget::ImageWidget(const std::string& a_imagePath)
        : m_imageTexture{AssetManager::GetInstance().LoadTexture(a_imagePath)}
        , m_imageSprite{*(m_imageTexture.get())}
    {

    }

    sf::FloatRect ImageWidget::GetWidgetBounds() const
    {
        return m_imageSprite.getGlobalBounds();
    }

    void ImageWidget::SetWidgetImage(const Shared<sf::Texture>& a_imageTexture)
    {
        if (a_imageTexture)
        {
            m_imageTexture = a_imageTexture;
            m_imageSprite.setTexture(*m_imageTexture.get());
        }
    }

    void ImageWidget::UpdateWidgetLocation(const sf::Vector2f& a_position)
    {
        m_imageSprite.setPosition(a_position);
    }

    void ImageWidget::UpdateWidgetRotation(float& a_rotation)
    {
        m_imageSprite.setRotation(a_rotation);
    }

    void ImageWidget::DrawWidget(SDL_Window& window)
    {
        //TODO: Fix this
        //window.draw(m_imageSprite);
    }
}
