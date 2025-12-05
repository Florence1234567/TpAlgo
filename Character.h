#pragma once

enum Direction { Left, Right, Up, Down };

class Character {
public:
	Character(float x, float y);
	float GetRow() { return row; };
	float GetCol() { return col; };
	void SetPos(float newRow, float newCol);
	Direction GetDir() { return currentDir; };
	void SetDir(Direction dir);
	void Move();
	bool GetWalkFrame() { return isWalkFrame1; };
private:
	float row, col;
	bool isWalkFrame1;
	Direction currentDir;
};