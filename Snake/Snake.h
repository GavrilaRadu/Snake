#pragma once

#include "General.h"

class snake
{
public:
	snake();
	~snake();

	void SetHead(point punct);
	void SetTail(point punct);

	point GetHead();
	point GetTail();

	void PlaceSnake(int board[30][20]);
	bool Move(int board[30][20], int& scor, char direction);
	bool CalculateTail(int board[30][20]);
	bool Grow(int board[30][20], int& scor);
	bool Cut(int board[30][20]);

private:
	struct point head;
	struct point tail;

};