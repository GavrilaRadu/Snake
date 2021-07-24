#pragma once

#include "General.h"

class apple
{
public:
	apple();
	~apple();
	
	void PlaceApple(int board[30][20]);

private:
	point locatie;
};