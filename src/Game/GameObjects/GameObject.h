#pragma once

#include "../../Base/Object.h"

enum class ObjectType {
    Berries, Bush1, Bush2, Flower1, Flower2, Flower3, Flower4,
    Fruit, Grass1, Grass2, Log, PurpleShrooms, RedShrooms, Rock
};

class GameObject : public Object {
public:
	GameObject(int x, int y, float size, ObjectType type);

    void Draw(sf::RenderTarget& target);

    sf::FloatRect GetCollisionBounds() const;
    ObjectType GetType() const { return type; }
    std::string GetTypeAsString() const { return std::to_string(static_cast<int>(type)); }

private:
	ObjectType type;

    static std::string GetTexturePath(ObjectType type) {
        switch (type) {
        case ObjectType::Berries:        return "Assets/Images/Objects/Berries.png";
        case ObjectType::Bush1:          return "Assets/Images/Objects/Bush1.png";
        case ObjectType::Bush2:          return "Assets/Images/Objects/Bush2.png";
        case ObjectType::Flower1:        return "Assets/Images/Objects/Flower1.png";
        case ObjectType::Flower2:        return "Assets/Images/Objects/Flower2.png";
        case ObjectType::Flower3:        return "Assets/Images/Objects/Flower3.png";
        case ObjectType::Flower4:        return "Assets/Images/Objects/Flower4.png";
        case ObjectType::Fruit:          return "Assets/Images/Objects/Fruit.png";
        case ObjectType::Grass1:         return "Assets/Images/Objects/Grass1.png";
        case ObjectType::Grass2:         return "Assets/Images/Objects/Grass2.png";
        case ObjectType::Log:            return "Assets/Images/Objects/Log.png";
        case ObjectType::PurpleShrooms:  return "Assets/Images/Objects/PurpleShrooms.png";
        case ObjectType::RedShrooms:     return "Assets/Images/Objects/RedShrooms.png";
        case ObjectType::Rock:           return "Assets/Images/Objects/Rock.png";
        default:                         return "";
        }
    }
};