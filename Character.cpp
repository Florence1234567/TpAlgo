#include "Character.h"

Character::Character(float x, float y)
{
	row = x;
	col = y;
	currentDir = Direction::Down;
	isWalkFrame1 = true;
}

void Character::SetPos(float newRow, float newCol)
{
	row = newRow;
	col = newCol;
}

void Character::SetDir(Direction dir)
{
	currentDir = dir;
}

void Character::Move()
{
	float nextRow = row, nextCol = col;
		
	switch (currentDir) {
	case Direction::Up:
		nextRow--;
		break;
	case Direction::Down:
		nextRow++;
		break;
	case Direction::Left:
		nextCol--;
		break;
	case Direction::Right:
		nextCol++;
		break;
	}

	if (nextRow < 5 && nextRow >= 0 && (nextCol < 5 && nextCol >= 0))
	{
		row = nextRow;
		col = nextCol;
		isWalkFrame1 = !isWalkFrame1;
	}
}
