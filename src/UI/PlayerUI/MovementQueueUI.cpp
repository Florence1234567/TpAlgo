#include "MovementQueueUI.h"
#include "../../DataStructures/Queue/ActionQueue.h"
#include <iostream>

MovementQueueUI::MovementQueueUI(PlayerController& controller, sf::Vector2u& windowSize,
	float width, float height, const std::string& titleText)
	: PlayerUIComponent(width, height, titleText), playerController(controller)
{
	position.x = static_cast<float>(windowSize.x) - panelSize.x - margin;
	position.y = margin;

	background.setPosition(position);
	title.setPosition({ position.x + contentMargin, position.y + contentMargin - 5 });
}

void MovementQueueUI::Draw(sf::RenderWindow& window)
{
	PlayerUIComponent::Draw(window);

	for (const auto& item : items)
		window.draw(item);
}

void MovementQueueUI::Update(sf::Time dt)
{
	items.clear();

	const auto queue = playerController.GetMovementQueue();

	if (queue.empty())
		return;

	float x = background.getPosition().x + contentMargin;
	float y = background.getPosition().y + contentMargin + 20;

	for (const auto& action : queue)
	{
		sf::Text text(font, sf::String(action), 16);
		text.setFillColor(mainTextColor);
		text.setPosition({ x, y });
		items.push_back(text);
		y += 20;
	}
}
