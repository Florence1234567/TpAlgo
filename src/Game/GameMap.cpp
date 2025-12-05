#include "GameMap.h"
#include <SFML/Graphics.hpp>
#include <sstream>
#include <map>
#include <iostream>

GameMap::GameMap(int width, int height) {
    Width = width;
    Height = height;

    map.resize(Height, std::vector<Tile>(Width, Tile::Grass));

    // Build the map
    for (int y = 0; y < Height; y++) 
        for (int x = 0; x < Width; x++) 
            map[y][x] = DecideTile(x, y);

    // Load textures
    for (const auto &[tile, path]: textureFiles)
        if (!textures[tile].loadFromFile(path))
            std::cerr << "Error loading " << path << std::endl;

    for (auto &[tile, texture]: textures) {
        sprites[tile] = std::make_unique<sf::Sprite>(texture);

        sf::Vector2u textureSize = texture.getSize();
        float scaleX = static_cast<float>(PixelsPerSquare) / textureSize.x;
        float scaleY = static_cast<float>(PixelsPerSquare) / textureSize.y;
        sprites[tile]->setScale(sf::Vector2f(scaleX, scaleY));
    }
}

Tile GameMap::DecideTile(int x, int y) {
    const int tilesX = Width / PixelsPerSquare;
    const int tilesY = Height / PixelsPerSquare;
    const int minX = 1;
    const int minY = 1;
    const int maxX = tilesX - 2;
    const int maxY = tilesY - 1;

    // Outer empty border
    if (x == 0 || x == tilesX - 1 || y == 0 || y == tilesY)
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
        }
    }
}