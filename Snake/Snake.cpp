#include "Snake.h"

snake::snake()
{
}

snake::~snake()
{
}

void snake::SetHead(point punct)
{
	this->head = punct;
}

void snake::SetTail(point punct)
{
	this->tail = punct;
}

point snake::GetHead()
{
	return this->head;
}

point snake::GetTail()
{
	return this->tail;
}

void snake::PlaceSnake(int board[30][20])
{
    this->head.y = rand() % 29 + 1;
    this->head.x = rand() % 20;

    this->tail.y = this->head.y - 1;
    this->tail.x = this->head.x;

    board[this->head.y][this->head.x] = 2;
    board[this->tail.y][this->tail.x] = 3;
}

bool snake::Move(int board[30][20], int& scor, char direction)
{
    switch (direction)
    {
    case 'r':
        board[this->head.y][this->head.x] = 3;
        if (this->head.y == 29)
            this->head.y = 0;
        else this->head.y += 1;

        this->Cut(board);

        return this->Grow(board, scor);
    
    case 'd':
        board[this->head.y][this->head.x] = 4;
        if (this->head.x == 19)
            this->head.x = 0;
        else this->head.x += 1;

        this->Cut(board);

        return this->Grow(board, scor);

    case 'l':
        board[this->head.y][this->head.x] = 5;
        if (this->head.y == 0)
            this->head.y = 29;
        else this->head.y -= 1;

        this->Cut(board);

        return this->Grow(board, scor);

    case 'u':
        board[this->head.y][this->head.x] = 6;
        if (this->head.x == 0)
            this->head.x = 19;
        else this->head.x -= 1;

        if (this->Cut(board) == false)
            return this->Grow(board, scor);
        else return false;
    }
}

bool snake::CalculateTail(int board[30][20])
{
    switch (board[this->tail.y][this->tail.x])
    {
    case 3:     //dreapta
        board[this->tail.y][this->tail.x] = 0;
        if (this->tail.y == 29)
            this->tail.y = 0;
        else this->tail.y += 1;
        return false;

    case 4:     //jos
        board[this->tail.y][this->tail.x] = 0;
        if (this->tail.x == 19)
            this->tail.x = 0;
        else this->tail.x += 1;
        return false;
    
    case 5:     //stanga
        board[this->tail.y][this->tail.x] = 0;
        if (this->tail.y == 0)
            this->tail.y = 29;
        else this->tail.y -= 1;
        return false;

    case 6:     //sus
        board[this->tail.y][this->tail.x] = 0;
        if (this->tail.x == 0)
            this->tail.x = 19;
        else this->tail.x -= 1;
        return false;
    default:    //se taie
        return true;
    }
}

bool snake::Grow(int board[30][20], int& scor)
{
    if (board[this->head.y][this->head.x] != 1)
    {
        this->CalculateTail(board);
        board[this->head.y][this->head.x] = 2;
        return false;
    }
    board[this->head.y][this->head.x] = 2;
    scor++;
    return true; //Trebuie sa plaseze iar marul
}

bool snake::Cut(int board[30][20])
{
    if (board[this->head.y][this->head.x] != 0 && board[this->head.y][this->head.x] != 1) 
    {
        int newTail = board[this->head.y][this->head.x];

        board[this->head.y][this->head.x] = 0;

        while (this->CalculateTail(board) == false);

        board[this->head.y][this->head.x] = newTail;
        this->CalculateTail(board);
        
        board[this->head.y][this->head.x] = 2;
        
        return true;
    }
    return false;
}
