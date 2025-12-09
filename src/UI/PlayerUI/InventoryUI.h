#pragma once
#include "PlayerUIComponent.h"
#include "../../Player/PlayerController.h"
#include "../../Player/PlayerCharacter.h"

struct InventorySlot {
    sf::Sprite sprite;
    sf::String name;
    int count;

    InventorySlot(const sf::Sprite& s, const sf::String& name, int c)
        : sprite(s), name(name), count(c) {}
};

class InventoryUI : public PlayerUIComponent {
public:
    InventoryUI(PlayerController& controller, PlayerCharacter& character, sf::Vector2u& windowSize, float margin = 20, float rightPadding = 280);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

private:
    PlayerController& controller;
    PlayerCharacter& character;
    std::vector<InventorySlot> items;
};
