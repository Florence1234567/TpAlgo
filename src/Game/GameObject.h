#pragma once

#include "../Base/Object.h"

enum class ObjectType {
	Rock, Chest
};

class GameObject : public Object {
public:
	GameObject(int x, int y, float size, ObjectType type);

    void Draw(sf::RenderTarget& target);

    sf::FloatRect GetCollisionBounds() const;
    ObjectType GetType() const { return type; }

private:
	ObjectType type;

    static std::string GetTexturePath(ObjectType type) {
        switch (type) {
        case ObjectType::Rock: return "Images/Objects/Rock.png";
        case ObjectType::Chest: return "Images/Objects/Bush.png";
        default: return "";
        }
    }
};