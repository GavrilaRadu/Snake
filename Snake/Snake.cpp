#include "Snake.h"

snake::snake()
{
    if (!this->texturaCap.loadFromFile("images/Head.png"))
        std::cout << "EROARE CAP SARPE !!!";
    
    this->spriteCap.setTexture(this->texturaCap);

    if (!this->texturaCorp.loadFromFile("images/Body.png"))
        std::cout << "EROARE CORP SARPE !!!";
}

snake::~snake()
{
    delete[] body;
}

void snake::SetHead(point punct)
{
	this->head = punct;
}

point snake::GetHead()
{
	return this->head;
}

void snake::PlaceSnake()
{
    this->head.y = rand() % 29 + 1;
    this->head.x = rand() % 20;

    this->spriteCap.setPosition(this->head.y * 16, this->head.x * 16);

    this->body[0].setTexture(this->texturaCorp);
    this->body[0].setPosition((this->head.y - 1) * 16, this->head.x * 16);
}

void snake::PrintSnake(sf::RenderWindow *window)
{
    window->draw(this->spriteCap);

    int i;
    for (i = 0; i < length; i++) {
        window->draw(this->body[i]);
    }
}

void snake::Move(char direction)
{
    this->CalculateBody();

    switch (direction)
    {
    case 'u':
        this->head.x -= 1;
        if (this->head.x == -1) {
            this->head.x = 19;
            this->spriteCap.setPosition(this->head.y * 16, this->head.x * 16);
        }
        else this->spriteCap.move(0, -16.f);
        break;

    case 'r':
        this->head.y += 1;
        if (this->head.y == 30) {
            this->head.y = 0;
            this->spriteCap.setPosition(this->head.y * 16, this->head.x * 16);
        }
        else this->spriteCap.move(16.f, 0);
        break;
    
    case 'd':
        this->head.x += 1;
        if (this->head.x == 20) {
            this->head.x = 0;
            this->spriteCap.setPosition(this->head.y * 16, this->head.x * 16);
        }
        else this->spriteCap.move(0, 16.f);
        break;

    case 'l':
        this->head.y -= 1;
        if (this->head.y == -1) {
            this->head.y = 29;
            this->spriteCap.setPosition(this->head.y * 16, this->head.x * 16);
        }
        else this->spriteCap.move(-16.f, 0);
        break;
    }
}

void snake::CalculateBody()
{
    int i;
    for (i = this->length - 1; i >= 1; i--) {
        if (this->body[i].getPosition() == this->spriteCap.getPosition())
            this->length = i;
        this->body[i] = this->body[i - 1];
    }
    this->body[0].setPosition(this->spriteCap.getPosition());
}

void snake::IncreaseLength()
{
    this->length++;
    
    if (this->length == this->maxLength) {
        this->maxLength = this->maxLength * 2;
        sf::Sprite* newBody = new sf::Sprite[this->maxLength];

        memcpy(newBody, this->body, this->maxLength / 2 * sizeof(sf::Sprite));
        delete[] this->body;
        this->body = newBody;
    }
}
