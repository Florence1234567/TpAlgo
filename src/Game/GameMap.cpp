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
    for (int y = 0; y < Height; y++) {
        for (int x = 0; x < Width; x++) {
            map[y][x] = DecideTile(x, y);
        }
    }

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
    const int maxX = tilesX - 1;
    const int maxY = tilesY;

    if (x == 0 && y == 0) return Tile::EdgeUpLeft;
    if (x == maxX && y == 0) return Tile::EdgeUpRight;
    if (x == 0 && y == maxY) return Tile::EdgeDownLeft;
    if (x == maxX && y == maxY) return Tile::EdgeDownRight;
    if (x == 0) return Tile::EdgeLeft;
    if (x == maxX) return Tile::EdgeRight;
    if (y == 0) return Tile::EdgeUp;
    if (y == maxY) return Tile::EdgeDown;
    return Tile::Grass;
}

void GameMap::Display(sf::RenderWindow &window) {
    for (int row = 0; row < Height; row++) {
        for (int col = 0; col < Width; col++) {
            sf::Vector2f position(col * PixelsPerSquare, row * PixelsPerSquare);
            Tile currentTile = map[row][col];

            auto it = sprites.find(currentTile);
            if (it != sprites.end()) {
                it->second->setPosition(position);
                window.draw(*it->second);
            }
        }
    }
}