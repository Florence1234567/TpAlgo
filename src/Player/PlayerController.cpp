//
// Created by Antoine on 2025-12-05.
//

#include "PlayerController.h"

#include "../Actions/AttackAction.h"
#include "../Player//PlayerCharacter.h"
#include "../Actions/MoveAction.h"
#include "../Actions/WaitAction.h"

void PlayerController::HandleEvent(const sf::Event& event, sf::FloatRect playingBounds, sf::RenderWindow* window) {
	if (const auto* mouseButtonPressed = event.getIf<sf::Event::MouseButtonPressed>()) {
		sf::Vector2i mousePos = mouseButtonPressed->position;
		sf::Vector2f worldPos = window->mapPixelToCoords(mousePos);

		if (!playingBounds.contains(worldPos))
			return;

		for (const auto& objBounds : gameMap->GetObjectBounds())
			if (objBounds.contains(worldPos))
				return;

		switch (mouseButtonPressed->button)
		{
		case sf::Mouse::Button::Left: {
			auto moveAction = std::make_unique<MoveAction>(owner, worldPos);
			PushAction(std::move(moveAction));
			break;
		}
		case sf::Mouse::Button::Right: {
			auto attackAction = std::make_unique<AttackAction>(owner, worldPos);
			PushAction(std::move(attackAction));
			break;
		}
		default:
			break;
		}
	}
}

void PlayerController::Update(sf::Time dt) {
	Controller::Update(dt);
}
