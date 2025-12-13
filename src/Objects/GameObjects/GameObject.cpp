#include "GameObject.h"
#include "GameObject.h"

#include <random>

#include "../Items/Potions/DamagePotion.h"
#include "../Items/Potions/HealthPotion.h"
#include "../Items/Potions/SpeedPotion.h"

GameObject::GameObject(int x, int y, float size, ObjectType type)
    : Object(x, y, size, GetTexturePath(type)), type(type) {
    if (type == ObjectType::Rock || type == ObjectType::Log || type == ObjectType::Bush1 || type == ObjectType::Bush2 ||
        type == ObjectType::Berries) {
        bLootable = true;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, maxInventorySize);
    int inventorySpace = dist(gen);

    if (bLootable)
        FillInventory(inventorySpace);
    else
        FillInventory(0);
}

void GameObject::Draw(sf::RenderWindow &window) const {
    Object::Draw(window);
    window.draw(sprite);
}

sf::FloatRect GameObject::GetCollisionBounds() const {
    sf::FloatRect bounds = sprite.getGlobalBounds();

    float size = std::max(bounds.size.x, bounds.size.y);

    float offsetX = (bounds.size.x - size) / 2.f;
    float offsetY = (bounds.size.y - size) / 2.f;

    return sf::FloatRect(
        {
            bounds.position.x + offsetX,
            bounds.position.y + offsetY
        },
        {size, size}
    );
}

std::string GameObject::GetTypeTextAsString() const {
    switch (type) {
        case ObjectType::Rock: return "Rock";
        case ObjectType::Log: return "Log";
        case ObjectType::Bush1: return "Bush1";
        case ObjectType::Bush2: return "Bush2";
        case ObjectType::Grass1: return "Grass1";
        case ObjectType::Grass2: return "Grass2";
        case ObjectType::Flower1: return "Flower1";
        case ObjectType::Flower2: return "Flower2";
        case ObjectType::Flower3: return "Flower3";
        case ObjectType::Flower4: return "Flower4";
        case ObjectType::Berries: return "Berries";
        case ObjectType::Fruit: return "Fruit";
        case ObjectType::PurpleShrooms: return "PurpleShrooms";
        case ObjectType::RedShrooms: return "RedShrooms";
        default: return "Unknown";
    }
}

bool GameObject::IsLootable() const {
    return bLootable;
}

void GameObject::FillInventory(int inventorySpace) {
    objectInventory.clear();

    if (inventorySpace <= 0) return;
    enum class LootType { HealthPotion, SpeedPotion, DamagePotion };
    std::vector<LootType> allowedLoot;

    switch (type) {
        case ObjectType::Rock:
        case ObjectType::Log:
            allowedLoot.push_back(LootType::DamagePotion);
            allowedLoot.push_back(LootType::SpeedPotion);
            break;
        case ObjectType::Bush1:
        case ObjectType::Bush2:
            allowedLoot.push_back(LootType::HealthPotion);
            allowedLoot.push_back(LootType::SpeedPotion);
            break;
        case ObjectType::Berries:
            allowedLoot.push_back(LootType::HealthPotion);
            break;
        default:
            return;
    }

    if (allowedLoot.empty()) return;

    for (int i = 0; i < inventorySpace; ++i) {
        // Random pick
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, static_cast<int>(allowedLoot.size()) - 1);

        LootType type = allowedLoot[dist(gen)];

        Item *newItem = nullptr;
        switch (type) {
            case LootType::HealthPotion: newItem = new HealthPotion();
                break;
            case LootType::SpeedPotion: newItem = new SpeedPotion();
                break;
            case LootType::DamagePotion: newItem = new DamagePotion();
                break;
        }

        if (newItem) objectInventory.push_back(newItem);
    }
}
