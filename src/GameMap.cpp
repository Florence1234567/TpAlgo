#include "GameMap.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>

GameMap::GameMap(const std::string& fileName)
{
    map.resize(Height, std::vector<Tile>(Width));

    std::ifstream file(fileName);
    if (!file)
        throw std::runtime_error("Can't open file");

    std::string line;
    for (int i = 0; i < Width && std::getline(file, line); i++)
    {
        std::stringstream ss(line);
        std::string value;

        for (int j = 0; j < Height && std::getline(ss, value, ','); j++)
            map[i][j] = StringToTile(value);
    }
}

Tile GameMap::StringToTile(const std::string& value)
{
    if (value == "Wall") return Tile::Wall;
    if (value == "Grass") return Tile::Grass;

    throw std::invalid_argument("Unknown object : " + value);
}

void GameMap::Display(sf::RenderWindow& window, sf::Sprite& wallSprite, sf::Sprite& grassSprite)
{
    for (int row = 0; row < Height; row++)
        for (int col = 0; col < Width; col++)
        {
            sf::Vector2f position(col * PixelsPerSquare, row * PixelsPerSquare);

            if (map[row][col] == Tile::Wall)
            {
                wallSprite.setPosition(position);
                window.draw(wallSprite);
            }
            else if (map[row][col] == Tile::Grass)
            {
                grassSprite.setPosition(position);
                window.draw(grassSprite);
            }
        }
}