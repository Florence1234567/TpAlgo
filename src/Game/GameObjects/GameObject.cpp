#include "GameObject.h"
#include "GameObject.h"

void GameObject::Draw(sf::RenderTarget& target)
{
	sprite.setPosition(GetPosition());
	target.draw(sprite);
}

sf::FloatRect GameObject::GetCollisionBounds() const
{
    sf::FloatRect bounds = sprite.getGlobalBounds();

    float size = std::max(bounds.size.x, bounds.size.y);

    float offsetX = (bounds.size.x - size) / 2.f;
    float offsetY = (bounds.size.y - size) / 2.f;

    return sf::FloatRect(
        { bounds.position.x + offsetX,
          bounds.position.y + offsetY },
        { size, size }
    );
}

std::string GameObject::GetTypeTextAsString() const
{
    switch (type)
    {
    case ObjectType::Rock:          return "Rock";
    case ObjectType::Log:           return "Log";
    case ObjectType::Bush1:         return "Bush1";
    case ObjectType::Bush2:         return "Bush2";
    case ObjectType::Grass1:        return "Grass1";
    case ObjectType::Grass2:        return "Grass2";
    case ObjectType::Flower1:       return "Flower1";
    case ObjectType::Flower2:       return "Flower2";
    case ObjectType::Flower3:       return "Flower3";
    case ObjectType::Flower4:       return "Flower4";
    case ObjectType::Berries:       return "Berries";
    case ObjectType::Fruit:         return "Fruit";
    case ObjectType::PurpleShrooms: return "PurpleShrooms";
    case ObjectType::RedShrooms:    return "RedShrooms";
    default:                        return "Unknown";
    }
}

bool GameObject::IsLootable() const
{
    return this->GetType() == ObjectType::Rock;
}
