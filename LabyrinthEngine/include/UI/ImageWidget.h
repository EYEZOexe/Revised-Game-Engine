//
// Created by Tomas Tzorta on 25/12/2023.
//

#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <SFML/Graphics.hpp>
#include "UI/Widget.h"

namespace labyrinth_engine
{
    class ImageWidget : public Widget
    {
    public:
        /* Constructors and Destructors */
        ImageWidget(const std::string& a_imagePath);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        sf::FloatRect GetWidgetBounds() const override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters
        void SetWidgetImage(const Shared<sf::Texture>& a_imageTexture);

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void UpdateWidgetLocation(const sf::Vector2f& a_position) override;
        void UpdateWidgetRotation(float& a_rotation) override;
        void DrawWidget(sf::RenderWindow& window) override;
        Shared<sf::Texture> m_imageTexture;
        sf::Sprite m_imageSprite;
    };
}

#endif //IMAGEWIDGET_H
