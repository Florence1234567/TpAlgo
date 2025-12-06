#include "GameMap.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <map>
#include <iostream>
#include <random>
#include <cmath>        
#include <memory>       

GameMap::GameMap(int width, int height) {
    Width = width;
    Height = height;

    map.resize(Height, std::vector<Tile>(Width, Tile::Grass));
    objectsMap.resize(Height, std::vector<Objects>(Width, Objects::ObjectNone));

    // Build the map
    for (int y = 0; y < Height; y++) 
        for (int x = 0; x < Width; x++)
        {
            map[y][x] = DecideTile(x, y);
            objectsMap[y][x] = DecideObject(x, y);
        }

    // Load textures
    for (const auto &[tile, path]: textureFiles)
        if (!textures[tile].loadFromFile(path))
            std::cerr << "Error loading " << path << std::endl;

    for (const auto& [object, path] : objectsTextureFiles)
        if (!objectsTextures[object].loadFromFile(path))
            std::cerr << "Error loading " << path << std::endl;

    for (auto &[tile, texture]: textures) {
        sprites[tile] = std::make_unique<sf::Sprite>(texture);

        sf::Vector2u textureSize = texture.getSize();
        float scaleX = static_cast<float>(PixelsPerSquare) / textureSize.x;
        float scaleY = static_cast<float>(PixelsPerSquare) / textureSize.y;
        sprites[tile]->setScale(sf::Vector2f(scaleX, scaleY));
    }

    for (auto& [object, texture] : objectsTextures) {
        objectsSprites[object] = std::make_unique<sf::Sprite>(texture);

        sf::Vector2u textureSize = texture.getSize();
        float scaleX = static_cast<float>(PixelsPerSquare) / textureSize.x;
        float scaleY = static_cast<float>(PixelsPerSquare) / textureSize.y;
        objectsSprites[object]->setScale(sf::Vector2f(scaleX, scaleY));
    }

    //PlaceRandomObjects(15);
}

Tile GameMap::DecideTile(int x, int y) {
    const int rightPadding = 320;
    const int tilesX = (Width - rightPadding) / PixelsPerSquare;
    const int tilesY = Height / PixelsPerSquare;
    const int minX = 1;
    const int minY = 1;
    const int maxX = tilesX - 2;
    const int maxY = tilesY - 1;

    // Outer empty border
    if (x == 0 || x >= tilesX - 1 || y == 0 || y == tilesY)
        return Tile::Water;

    //Corners
    if (x == minX && y == minY) return Tile::EdgeUpLeft;
    if (x == maxX && y == minY) return Tile::EdgeUpRight;
    if (x == minX && y == maxY) return Tile::EdgeDownLeft;
    if (x == maxX && y == maxY) return Tile::EdgeDownRight;

    //Edges
    if (x == minX) return Tile::EdgeLeft;
    if (x == maxX) return Tile::EdgeRight;
    if (y == minY) return Tile::EdgeUp;
    if (y == maxY) return Tile::EdgeDown;

    //Middle
    return Tile::Grass;
}

Objects GameMap::DecideObject(int x, int y)
{
    const int tilesX = (Width - rightPadding) / PixelsPerSquare;
    const int tilesY = Height / PixelsPerSquare;
    const int minX = 1;
    const int minY = 1;
    const int maxX = tilesX - 2;
    const int maxY = tilesY - 1;

    // Outer empty border
    if (x == 0 || x >= tilesX - 1 || y == 0 || y == tilesY)
        return Objects::ObjectNone;

    //Corners
    if (x == minX && y == minY) return Objects::FenceUpLeft;
    if (x == maxX && y == minY) return Objects::FenceUpRight;
    if (x == minX && y == maxY) return Objects::FenceDownLeft;
    if (x == maxX && y == maxY) return Objects::FenceDownRight;

    //Edges
    if (x == minX || x == maxX) return Objects::FenceLeftRight;
    if (y == minY || y == maxY) return Objects::FenceUpDown;

    return Objects::ObjectNone;
}

/*void GameMap::PlaceRandomObjects(int count)
{
    const int tilesX = (Width - rightPadding) / PixelsPerSquare;
    const int tilesY = Height / PixelsPerSquare;
    const int minX = 2;
    const int minY = 2;
    const int maxX = tilesX - 3;
    const int maxY = tilesY - 2;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distX(minX, maxX);
    std::uniform_int_distribution<> distY(minY, maxY);
    std::uniform_int_distribution<> distObject(0, 2);

    int placed = 0;
    int attemps = 0;
    const int maxAttemps = count * 10;

    while (placed < count && attemps < maxAttemps)
    {
        attemps++;

        int tileX = distX(gen);
        int tileY = distY(gen);

        if (!IsValidObjectPosition(tileX, tileY))
            continue;

        ObjectType objectType;
        int objChoice = distObject(gen);

        switch (objChoice) 
        {
        case 0:
            objectType = ObjectType::Rock;
            break;
        case 1:
            objectType = ObjectType::Chest;
            break;
        default:
            objectType = ObjectType::Rock;
            break;
        }

        //Center of tile.
        int pixelX = tileX * PixelsPerSquare + PixelsPerSquare / 2;
        int pixelY = tileY * PixelsPerSquare + PixelsPerSquare / 2;

        gameObjects.push_back(std::make_unique<GameObject>(pixelX, pixelY, 2, objectType));
        placed++;
    }
}

bool GameMap::IsValidObjectPosition(int x, int y) const
{
    const int tilesX = (Width - rightPadding) / PixelsPerSquare;
    const int tilesY = Height / PixelsPerSquare;

    if (x < 2 || x >= tilesX - 3 || y < 2 || y >= tilesY - 2)
        return false;

    if (map[y][x] != Tile::Grass)
        return false;

    int pixelX = x * PixelsPerSquare + PixelsPerSquare / 2;
    int pixelY = y * PixelsPerSquare + PixelsPerSquare / 2;

    for (const auto& obj : gameObjects)
    {
        sf::Vector2f objPos = obj->GetPosition();

        float dx = pixelX - objPos.x;
        float dy = pixelY - objPos.y;
        float distSq = dx * dx + dy * dy;

        float minDist = PixelsPerSquare * 2;

        if (distSq < minDist * minDist)
            return false;
    }

    return true;
}*/

void GameMap::Display(sf::RenderTarget &target) {
    for (int row = 0; row < Height; row++) {
        for (int col = 0; col < Width; col++) {
            sf::Vector2f position(col * PixelsPerSquare, row * PixelsPerSquare);
            Tile currentTile = map[row][col];

            if (currentTile == Tile::EdgeUp || currentTile == Tile::EdgeDown || currentTile == Tile::EdgeLeft ||
                currentTile == Tile::EdgeRight || currentTile == Tile::EdgeUpLeft || currentTile == Tile::EdgeUpRight ||
                currentTile == Tile::EdgeDownLeft || currentTile == Tile::EdgeDownRight)
            {
                auto waterIt = sprites.find(Tile::Water);
                if (waterIt != sprites.end())
                {
                    waterIt->second->setPosition(position);
                    target.draw(*waterIt->second);
                }
            }
            
            auto it = sprites.find(currentTile);
            if (it != sprites.end()) {
                it->second->setPosition(position);
                target.draw(*it->second);
            }

            Objects currentObject = objectsMap[row][col];

            auto objectIt = objectsSprites.find(currentObject);
            if (objectIt != objectsSprites.end()) {
                objectIt->second->setPosition(position);
                target.draw(*objectIt->second);
            }
        }
    }
}

void GameMap::DisplayObjects(sf::RenderWindow& window) {
    for (int row = 0; row < Height; row++) {
        for (int col = 0; col < Width; col++) {
            sf::Vector2f position(col * PixelsPerSquare, row * PixelsPerSquare);
            Objects currentObject = objectsMap[row][col];

            auto objectIt = objectsSprites.find(currentObject);
            if (objectIt != objectsSprites.end()) {
                objectIt->second->setPosition(position);
                window.draw(*objectIt->second);
            }
        }
    }

    /*for (const auto& obj : gameObjects) {
        obj->Draw(window);
    }*/
}

sf::FloatRect GameMap::GetFenceBounds() const {
    const int tilesX = (Width - rightPadding) / PixelsPerSquare;
    const int tilesY = Height / PixelsPerSquare;

    const int minX = 1;
    const int minY = 1;
    const int maxX = tilesX - 2;
    const int maxY = tilesY - 1;

    const int grassStartX = minX + 1;
    const int grassStartY = minY + 1;
    const int grassEndX = maxX - 1;
    const int grassEndY = maxY - 1;

    float left = grassStartX * PixelsPerSquare;
    float top = grassStartY * PixelsPerSquare;
    float width = (grassEndX - grassStartX + 1) * PixelsPerSquare;
    float height = (grassEndY - grassStartY + 1) * PixelsPerSquare;

    sf::FloatRect bounds(sf::Vector2f(left, top), sf::Vector2f(width, height));

    return bounds;
}

std::vector<sf::FloatRect> GameMap::GetObjectBounds() const
{
    std::vector<sf::FloatRect> boundsList;

    for (const auto& obj : gameObjects)
        boundsList.push_back(obj->GetCollisionBounds());

    return boundsList;
}

/*bool GameMap::IsPositionBlocked(float x, float y, float width, float height) const
{
    sf::FloatRect fenceBounds = GetFenceBounds();
    sf::FloatRect playerBounds(sf::Vector2f(x - width / 2, y - height / 2), sf::Vector2f(width, height));

    if (!fenceBounds.contains(sf::Vector2f(x, y)))
        return true;

    for (const auto& obj : gameObjects)
    {
        sf::FloatRect objBounds = obj->GetCollisionBounds();

        if (auto intersection = playerBounds.findIntersection(objBounds))
            return true;
    }

    return false;
}*/
