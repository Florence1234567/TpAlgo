#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <map>

enum Tile {
	EdgeUpLeft, EdgeUp, EdgeUpRight,
	EdgeLeft, Grass, EdgeRight,
	EdgeDownLeft, EdgeDown, EdgeDownRight,
	Water, None
};

enum Objects {
	FenceUpLeft, FenceUpRight,
	FenceLeftRight, FenceUpDown,
	FenceDownLeft, FenceDownRight,
	ObjectNone
};

class GameMap
{
public:
	GameMap(int width, int height);

	void Display(sf::RenderTarget& target);
	void DisplayObjects(sf::RenderWindow& window);

	int GetWidth() { return Width; };
	int GetHeight() { return Height; };

	sf::FloatRect GetGrassBounds() const;

private:
	int Width;
	int Height;
	static const int PixelsPerSquare = 64;

	Tile DecideTile(int x, int y);
	Objects DecideObject(int x, int y);

	std::vector<std::vector<Tile>> map;
	std::vector<std::vector<Objects>> objectsMap;

	std::map<Tile, std::string> textureFiles = {
		{EdgeUpLeft, "Images/Ground/E_UL.png"},
		{EdgeUp, "Images/Ground/E_U.png"},
		{EdgeUpRight, "Images/Ground/E_UR.png"},
		{EdgeLeft, "Images/Ground/E_L.png"},
		{Grass, "Images/Ground/Grass.png"},
		{EdgeRight, "Images/Ground/E_R.png"},
		{EdgeDownLeft, "Images/Ground/E_DL.png"},
		{EdgeDown, "Images/Ground/E_D.png"},
		{EdgeDownRight, "Images/Ground/E_DR.png"},
		{Water, "Images/Ground/Water.png"}
	};

	std::map<Objects, std::string> objectsTextureFiles = {
		{ FenceUpLeft, "Images/Fences/F_CornerUL.png" },
		{ FenceUpRight, "Images/Fences/F_CornerUR.png" },
		{ FenceLeftRight, "Images/Fences/F_CornerLR.png" },
		{ FenceUpDown, "Images/Fences/F_CornerUD.png" },
		{ FenceDownLeft, "Images/Fences/F_CornerDL.png" },
		{ FenceDownRight, "Images/Fences/F_CornerDR.png" }
	};

	std::map<Tile, sf::Texture> textures;
	std::map<Tile, std::unique_ptr<sf::Sprite>> sprites;

	std::map<Objects, sf::Texture> objectsTextures;
	std::map<Objects, std::unique_ptr<sf::Sprite>> objectsSprites;
};