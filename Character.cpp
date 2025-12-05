#include "Character.h"

Character::Character(float x, float y)
{
	row = x;
	col = y;
	currentDir = Direction::Down;
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

void Character::Move(Direction dir)
{
	switch (dir) {
	case Direction::Up:
		row++;
		break;
	case Direction::Down:
		row--;
		break;
	case Direction::Left:
		col--;
		break;
	case Direction::Right:
		col++;
		break;
	}

	isWalkFrame1 = !isWalkFrame1;
}
