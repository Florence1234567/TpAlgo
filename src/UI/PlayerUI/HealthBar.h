#pragma once
#include "PlayerUIComponent.h"
#include "../UIComponent.h"
#include "../../Player/PlayerCharacter.h"

class HealthBar : UIComponent {
public:
    HealthBar(sf::Vector2f position, sf::Vector2f panelSize, sf::Vector2u windowSize, PlayerCharacter& player);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    PlayerCharacter& playerRef;

    sf::Texture heartTexture;
    sf::Sprite heartSprite;
    float spacing = 5;
};