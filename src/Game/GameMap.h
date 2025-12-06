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

	sf::FloatRect GetFenceBounds() const;

private:
	int Width;
	int Height;
	static const int PixelsPerSquare = 64;
	const int rightPadding = 320;

	Tile DecideTile(int x, int y);
	Objects DecideObject(int x, int y);

	std::vector<std::vector<Tile>> map;
	std::vector<std::vector<Objects>> objectsMap;

	std::map<Tile, std::string> textureFiles = {
		{EdgeUpLeft, "Assets/Images/Ground/E_UL.png"},
		{EdgeUp, "Assets/Images/Ground/E_U.png"},
		{EdgeUpRight, "Assets/Images/Ground/E_UR.png"},
		{EdgeLeft, "Assets/Images/Ground/E_L.png"},
		{Grass, "Assets/Images/Ground/Grass.png"},
		{EdgeRight, "Assets/Images/Ground/E_R.png"},
		{EdgeDownLeft, "Assets/Images/Ground/E_DL.png"},
		{EdgeDown, "Assets/Images/Ground/E_D.png"},
		{EdgeDownRight, "Assets/Images/Ground/E_DR.png"},
		{Water, "Assets/Images/Ground/Water.png"}
	};

	std::map<Objects, std::string> objectsTextureFiles = {
		{ FenceUpLeft, "Assets/Images/Fences/F_CornerUL.png" },
		{ FenceUpRight, "Assets/Images/Fences/F_CornerUR.png" },
		{ FenceLeftRight, "Assets/Images/Fences/F_CornerLR.png" },
		{ FenceUpDown, "Assets/Images/Fences/F_CornerUD.png" },
		{ FenceDownLeft, "Assets/Images/Fences/F_CornerDL.png" },
		{ FenceDownRight, "Assets/Images/Fences/F_CornerDR.png" }
	};

	std::map<Tile, sf::Texture> textures;
	std::map<Tile, std::unique_ptr<sf::Sprite>> sprites;

	std::map<Objects, sf::Texture> objectsTextures;
	std::map<Objects, std::unique_ptr<sf::Sprite>> objectsSprites;
};