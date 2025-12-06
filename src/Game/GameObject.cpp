#include "GameObject.h"
#include "GameObject.h"

GameObject::GameObject(int x, int y, float size, ObjectType type)
	: Object(x, y, size, GetTexturePath(type)), type(type)
{
}

void GameObject::Draw(sf::RenderTarget& target)
{
	sprite.setPosition(GetPosition());
	target.draw(sprite);
}

sf::FloatRect GameObject::GetCollisionBounds() const
{
	sf::FloatRect bounds = sprite.getGlobalBounds();

	//Adjust bounds if needed.
	switch (type)
	{
	case ObjectType::Rock:
		break;
	case ObjectType::Chest:
		break;
	}

	return bounds;
}
