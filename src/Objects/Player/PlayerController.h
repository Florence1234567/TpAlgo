//
// Created by Antoine on 2025-12-05.
//
#pragma once
#include "../Controller.h"
#include <unordered_map>

class PlayerController : public Controller {
public:
    explicit PlayerController(Character* player, const GameMap* map) : Controller(player), gameMap(map){};

    void HandleEvent(const sf::Event& event, sf::FloatRect playingBounds, sf::RenderWindow* window) override;

    void Update(sf::Time dt) override;

    bool IsContextMenuOpen() const { return bShowContextMenu; }
    void CloseContextMenu() { bShowContextMenu = false; }
    sf::Vector2f GetContextMenuPosition() const { return contextMenuPosition; }

    void PerformAction(std::unique_ptr<Action> action);

private:
    const GameMap* gameMap;
    sf::Vector2f lastClickedPosition;

    // Context menu
    bool bShowContextMenu = false;
    bool bActionPerformed = false;
    sf::Vector2f contextMenuPosition;
};
