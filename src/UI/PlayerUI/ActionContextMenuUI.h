//
// Created by Antoine on 2025-12-06.
//

#pragma once
#include "PlayerUIComponent.h"
#include "../../Objects/Player/PlayerController.h"

/// Bouton pour le menu contextuel
class ActionButton {
public:
    ActionButton(const Action* Action, const sf::Vector2f& Position, const sf::Font& font);

    void Draw(sf::RenderWindow& window) const;
    bool contains(sf::Vector2f point) const;
    int getCharacterSize() const { return label.getCharacterSize(); };
    const Action* getAction() const { return action; };

private:
    const Action* action;
    sf::RectangleShape button;
    sf::Text label;

    static constexpr sf::Color buttonColor = sf::Color(100, 100, 100, 50);
    static constexpr sf::Color textColor = sf::Color::Black;
    static constexpr int fontSize = 14;
    static constexpr float padding = 5;
};



/// Menu contextuel
class ActionContextMenuUI : public PlayerUIComponent {
public:
    ActionContextMenuUI(PlayerController* controller, sf::Vector2f position);

    void Draw(sf::RenderWindow& window) override;
    void Update(sf::Time dt) override;

    void HandleEvent(const sf::Event& event, sf::RenderWindow* window);

private:
    const PlayerController* playerController;
    std::vector<sf::Text> items;
    std::vector<ActionButton> buttons;

    float contentMargin = 15;
    float contentPadding = 5;
};
