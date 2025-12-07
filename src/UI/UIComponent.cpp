//
// Created by Antoine on 2025-12-06.
//

#include "UIComponent.h"

UIComponent::UIComponent(sf::Vector2f position, sf::Vector2f size) : position(position), panelSize(size) {
    mainTextColor = sf::Color::Black;
    mainTextStyle = sf::Text::Style::Regular;

    if (!font.openFromFile("Assets/Fonts/FiraCode/FiraCodeNerdFontMono-Regular.ttf"))
        std::cerr << "Failed to load font" << std::endl;
}