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

    float shrinkX = bounds.size.x * 0.05f;
    float liftY = bounds.size.y * 0.05f;
    float heightAdjusted = bounds.size.y * 0.5f;

    return sf::FloatRect(
        { bounds.position.x + shrinkX, bounds.position.y + liftY },
        { bounds.size.x - shrinkX * 2.f, heightAdjusted }
    );
}