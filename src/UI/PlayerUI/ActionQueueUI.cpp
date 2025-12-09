#include "ActionQueueUI.h"
#include "../../DataStructures/Queue/ActionQueue.h"
#include <iostream>

ActionQueueUI::ActionQueueUI(PlayerController& controller, sf::Vector2u& windowSize, float margin, float rightPadding)
	: PlayerUIComponent(position, sf::Vector2f(5, 7), 20, 280), playerController(controller)
{
	title = sf::Text(font, "Movement Queue", 20);
	title.setFillColor(mainTextColor);

	position = sf::Vector2f(static_cast<float>(windowSize.x) - background.getSize().x - margin, margin) ;

	background.setPosition(position);
	title.setPosition({ position.x + contentMargin, position.y + contentMargin - 5 });
}

void ActionQueueUI::Draw(sf::RenderWindow& window)
{
	PlayerUIComponent::Draw(window);

	for (const auto& item : items)
		window.draw(item);
}

void ActionQueueUI::Update(sf::Time dt)
{
	items.clear();

	const auto queue = playerController.GetActionQueue();

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
