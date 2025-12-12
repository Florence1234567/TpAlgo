#pragma once
#include "PlayerUIComponent.h"
#include "../UIComponent.h"
#include "../../Objects/Player/PlayerCharacter.h"
#include <iostream>

class HealthBar : UIComponent {
public:
    HealthBar(sf::Vector2f position, sf::Vector2f size, sf::Vector2u windowSize, PlayerCharacter& player);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    PlayerCharacter& playerRef;

    float fullWidth;
    sf::RectangleShape background;
    sf::RectangleShape foreground;

    //sf::Texture heartTexture;
    //sf::Sprite heartSprite;
    //float spacing = 5;
};