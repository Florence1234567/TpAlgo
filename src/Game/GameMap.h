#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <map>

enum Tile {
	EdgeUpLeft, EdgeUp, EdgeUpRight,
	EdgeLeft, Grass, EdgeRight,
	EdgeDownLeft, EdgeDown, EdgeDownRight
};

class GameMap
{
public:
	GameMap(int width, int height);

	void Display(sf::RenderWindow& window);

	int GetWidth() { return Width; };
	int GetHeight() { return Height; };

private:
	int Width;
	int Height;
	static const int PixelsPerSquare = 64;

	Tile DecideTile(int x, int y);

	std::vector<std::vector<Tile>> map;

	std::map<Tile, std::string> textureFiles = {
		{EdgeUpLeft, "Images/Ground/E_UL.png"},
		{EdgeUp, "Images/Ground/E_U.png"},
		{EdgeUpRight, "Images/Ground/E_UR.png"},
		{EdgeLeft, "Images/Ground/E_L.png"},
		{Grass, "Images/Ground/Grass.png"},
		{EdgeRight, "Images/Ground/E_R.png"},
		{EdgeDownLeft, "Images/Ground/E_DL.png"},
		{EdgeDown, "Images/Ground/E_D.png"},
		{EdgeDownRight, "Images/Ground/E_DR.png"}
	};

	std::map<Tile, sf::Texture> textures;
	std::map<Tile, std::unique_ptr<sf::Sprite>> sprites;

};