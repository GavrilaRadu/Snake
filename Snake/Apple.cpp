#include "Apple.h"

apple::apple()
{
}

apple::~apple()
{
}

void apple::PlaceApple(int board[30][20])
{
	this->locatie.y = rand() % 30;
	this->locatie.x = rand() % 20;
	if (board[this->locatie.y][this->locatie.x] != 0)
		this->PlaceApple(board);
	else board[this->locatie.y][this->locatie.x] = 1;
}