#include "GameMap.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>

GameMap::GameMap(const std::string& fileName, int width, int height)
{
	Width = width;
	Height = height;

	map.resize(Width, std::vector<Tile>(Height));

	std::ifstream file(fileName);
	if (!file)
		throw std::runtime_error("Can't open file " + fileName);

	std::string line;
	for (int x = 0; x < Width && std::getline(file, line); x++)
	{
		std::stringstream ss(line);
		std::string value;

		for (int y = 0; y < Height && std::getline(ss, value, ','); y++)
			map[x][y] = StringToTile(value);
	}

	for (const auto& [tile, path] : textureFiles)
		if (!textures[tile].loadFromFile(path))
			std::cerr << "Error loading " << path << std::endl;

	for (auto& [tile, texture] : textures)
	{
		sprites[tile] = std::make_unique<sf::Sprite>(texture);

		sf::Vector2u textureSize = texture.getSize();
		float scaleX = static_cast<float>(PixelsPerSquare) / textureSize.x;
		float scaleY = static_cast<float>(PixelsPerSquare) / textureSize.y;
		sprites[tile]->setScale(sf::Vector2f(scaleX, scaleY));
	}

	//Character
	for (const auto& [name, path] : characterTextureFiles)
		if (!characterTextures[name].loadFromFile(path))
			std::cerr << "Error loading " << path << std::endl;

	for (auto& [name, texture] : characterTextures)
	{
		characterSprites[name] = std::make_unique<sf::Sprite>(texture);

		sf::Vector2u textureSize = texture.getSize();
		float scaleX = static_cast<float>(PixelsPerSquare) / textureSize.x;
		float scaleY = static_cast<float>(PixelsPerSquare) / textureSize.y;
		characterSprites[name]->setScale(sf::Vector2f(scaleX, scaleY));
	}
}

void GameMap::Display(sf::RenderWindow& window)
{
	for (int row = 0; row < Height; row++)
		for (int col = 0; col < Width; col++)
		{
			sf::Vector2f position(col * PixelsPerSquare, row * PixelsPerSquare);
			Tile currentTile = map[row][col];

			auto it = sprites.find(currentTile);
			if (it != sprites.end())
			{
				it->second->setPosition(position);
				window.draw(*it->second);
			}
		}

	//Decide with character sprite to display.
	auto it = characterSprites.find("Front");
	if (it != characterSprites.end())
	{
		float characterRow = Height / 2;
		float characterCol = Width / 2;

		sf::Vector2f characterPos(characterCol * PixelsPerSquare, characterRow * PixelsPerSquare);
		it->second->setPosition(characterPos);
		window.draw(*it->second);
	}
}

Tile GameMap::StringToTile(const std::string& value)
{
	if (value == "E_UL") return Tile::EdgeUpLeft;
	if (value == "E_U") return Tile::EdgeUp;
	if (value == "E_UR") return Tile::EdgeUpRight;
	if (value == "E_L") return Tile::EdgeLeft;
	if (value == "G") return Tile::Grass;
	if (value == "E_R") return Tile::EdgeRight;
	if (value == "E_DL") return Tile::EdgeDownLeft;
	if (value == "E_D") return Tile::EdgeDown;
	if (value == "E_DR") return Tile::EdgeDownRight;

	throw std::invalid_argument("Unknown object : " + value);
}