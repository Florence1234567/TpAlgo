#include "PlayerUI.h"

void PlayerUI::Draw(sf::RenderWindow& window)
{
	BuildBackground();
	sf::Vector2f origin = background.getPosition();

	for (int row = 0; row < backgroundMap.size(); row++)
		for (int col = 0; col < backgroundMap[row].size(); col++) {
			sf::Vector2f position(origin.x + col * PixelsPerSquare, origin.y + row * PixelsPerSquare);
			Background tile = backgroundMap[row][col];

			auto it = backgroundSprites.find(tile);

			if (it != backgroundSprites.end())
			{
				it->second->setPosition(position);
				window.draw(*it->second);
			}
		}

	window.draw(title);
}

void PlayerUI::Update(sf::Time dt)
{
}

PlayerUI::PlayerUI(float width, float height, std::string titleText, float margin, float rightPadding) :
	UIComponent(sf::Vector2f(0, 0), sf::Vector2f(width, height)), title(sf::Text(font, "Title", 16)), margin(margin), rightPadding(rightPadding)
{
	background.setSize(panelSize);

	title = sf::Text(font, titleText, 16);
	title.setFillColor(mainTextColor);

	for (const auto& [object, path] : backgroundTextureFiles)
		if (!backgoundTextures[object].loadFromFile(path))
			std::cerr << "Error loading " << path << std::endl;

	for (auto& [object, texture] : backgoundTextures) {
		backgroundSprites[object] = std::make_unique<sf::Sprite>(texture);

		sf::Vector2u textureSize = texture.getSize();
		float scaleX = static_cast<float>(PixelsPerSquare) / textureSize.x;
		float scaleY = static_cast<float>(PixelsPerSquare) / textureSize.y;
		backgroundSprites[object]->setScale(sf::Vector2f(scaleX, scaleY));
	}

	BuildBackground();
}

void PlayerUI::BuildBackground()
{
	int cols = static_cast<int>(panelSize.x) / PixelsPerSquare;
	int rows = static_cast<int>(panelSize.y) / PixelsPerSquare;

	backgroundMap.resize(rows, std::vector<Background>(cols, Background::Middle));

	for (int y = 0; y < rows; ++y)
		for (int x = 0; x < cols; ++x)
		{
			bool top = (y == 0);
			bool bottom = (y == rows - 1);
			bool left = (x == 0);
			bool right = (x == cols - 1);

			if (top && left)         backgroundMap[y][x] = Background::P_UL;
			else if (top && right)   backgroundMap[y][x] = Background::P_UR;
			else if (bottom && left) backgroundMap[y][x] = Background::P_DL;
			else if (bottom && right)backgroundMap[y][x] = Background::P_DR;
			else if (top)            backgroundMap[y][x] = Background::P_U;
			else if (bottom)         backgroundMap[y][x] = Background::P_D;
			else if (left)           backgroundMap[y][x] = Background::P_L;
			else if (right)          backgroundMap[y][x] = Background::P_R;
			else                     backgroundMap[y][x] = Background::Middle;
		}
}

