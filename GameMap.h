#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

enum Tile { Wall, Grass };
enum Direction { Left, Right, Up, Down };

class GameMap
{
public:
    static const int Width = 10;
    static const int Height = 10;
    static const int PixelsPerSquare = 24;

    GameMap(const std::string& fileName);

    void Display(sf::RenderWindow& window,
        sf::Sprite& wallSprite,
        sf::Sprite& grassSprite);

private:
    std::vector<std::vector<Tile>> map;

    Tile StringToTile(const std::string& value);
};