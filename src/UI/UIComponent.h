//
// Created by Antoine on 2025-12-06.
//

#pragma once
#include "SFML/Graphics/Font.hpp"
#include <iostream>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"


class UIComponent {
public:
    UIComponent(sf::Vector2f position, sf::Vector2f panelSize);
    virtual ~UIComponent() = default;

    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void Update(sf::Time dt) = 0;

protected:
    sf::Font font;
    sf::Color mainTextColor;
    sf::Text::Style mainTextStyle;

    sf::Vector2f position;
    sf::Vector2f panelSize;
};
