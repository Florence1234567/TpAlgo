//
// Created by Antoine on 2025-12-06.
//

#include "ActionContextMenuUI.h"
#include "../../Actions/MoveAction.h"


/// Boutton pour menu contextuel
ActionButton::ActionButton(const Action *Action, const sf::Vector2f &Position, const sf::Font &font)
    : action(Action), label(font, sf::String(action->getName()), fontSize) {
    label.setFillColor(textColor);
    label.setPosition(Position);
    float lenght = Action->getName().length();
    float size = label.getCharacterSize();

    sf::Vector2f bgSize(lenght * size, size + padding * 2);
    button.setSize(bgSize);
    button.setFillColor(buttonColor);
    button.setPosition({Position.x - padding, Position.y - padding});
}

void ActionButton::Draw(sf::RenderWindow &window) const {
    window.draw(button);
    window.draw(label);
}

bool ActionButton::contains(sf::Vector2f point) const {
    return button.getGlobalBounds().contains(point);
}


/// Menu contextuel
ActionContextMenuUI::ActionContextMenuUI(const PlayerController *controller, sf::Vector2f position)
    : PlayerUIComponent(position, sf::Vector2f(4, 3), 20, 280), playerController(controller) {
    title = sf::Text(font, "Perform Action", 15);
    title.setFillColor(mainTextColor);
}

void ActionContextMenuUI::Draw(sf::RenderWindow &window) {
    if (!playerController->IsContextMenuOpen()) return;

    position = playerController->GetContextMenuPosition();

    background.setPosition({position.x - 15, position.y - 10});
    title.setPosition({position.x + contentMargin, position.y + contentMargin});

    PlayerUIComponent::Draw(window);

    items.clear();

    const std::vector<std::unique_ptr<Action> > &executable_actions = playerController->GetExecutableActions();;

    if (executable_actions.empty()) return;

    float x = title.getPosition().x;
    float y = title.getPosition().y + title.getCharacterSize() + contentMargin;

    for (const auto &action: executable_actions) {
        ActionButton button(action.get(), sf::Vector2f(x, y), font);
        button.Draw(window);
        buttons.push_back(button);
        y += button.getCharacterSize() + contentMargin;
    }

    for (const auto &item: items)
        window.draw(item);
}

void ActionContextMenuUI::Update(sf::Time dt) {
}

void ActionContextMenuUI::HandleEvent(const sf::Event &event, sf::RenderWindow *window) {
    if (!playerController->IsContextMenuOpen()) return;
    if (const auto *mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
        sf::Vector2i mousePos = mouseButtonPressed->position;
        sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

        if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
            if (background.getGlobalBounds().contains(worldPos)) {
                for (const auto &button: buttons) {
                    if (button.contains(worldPos)) {
                        const std::vector<std::unique_ptr<Action> > &actions = playerController->GetExecutableActions();
                        const auto &action = button.getAction();
                        const_cast<PlayerController *>(playerController)->PerformAction(action->Clone());
                        return;
                    }
                }
            }
            else {
                const_cast<PlayerController *>(playerController)->CloseContextMenu();
            }
        }

        if (mouseButtonPressed->button == sf::Mouse::Button::Right) {
            const_cast<PlayerController *>(playerController)->CloseContextMenu();
        }
    }
}