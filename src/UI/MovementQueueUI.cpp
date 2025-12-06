#include "MovementQueueUI.h"
#include "../DataStructures/Queue/ActionQueue.h"
#include <iostream>

MovementQueueUI::MovementQueueUI(PlayerController& controller, sf::Vector2u& windowSize,
	float width, float height, const std::string& titleText)
	: PlayerUI(width, height, titleText), playerController(controller)
{
	float x = static_cast<float>(windowSize.x) - rightPadding - panelWidth;
	float y = margin;

	background.setPosition({ x, y });
	title.setPosition({ x + 10, y + 5 });
}

void MovementQueueUI::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(title);

	for (const auto& item : items)
		window.draw(item);
}

void MovementQueueUI::Update(sf::Time dt)
{
	timeSinceLastUpdate += dt.asSeconds();

	if (timeSinceLastUpdate < interval)
		return;

	timeSinceLastUpdate = 0;

	items.clear();

	const auto queue = playerController.GetMovementQueue();

	if (queue.empty())
		return;

	float x = background.getPosition().x + 10;
	float y = background.getPosition().y + 30;

	for (const auto& action : queue)
	{
		sf::Text text(font, sf::String(action), 14);
		text.setFillColor(sf::Color::White);
		text.setPosition({ x, y });
		items.push_back(text);
		y += 20;
	}
}
