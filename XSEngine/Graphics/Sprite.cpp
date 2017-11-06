#include "..\Sprite.hpp"


Sprite::Sprite()
{
	this->position = Point(0, 0);
	this->origin = Point(0, 0);
	this->rotation = 0;
}

Sprite::Sprite(char *filename)
{
	Sprite();
	_sprite = load_bitmap(filename, NULL);
}

Sprite::Sprite(char *filename, Point position)
{
	Sprite();
	_sprite = load_bitmap(filename, NULL);
	this->position = position;
}

Sprite::Sprite(char *filename, Point position, Point origin)
{
	Sprite(filename, position);
	this->origin = origin;
}

Sprite::~Sprite()
{

}

void Sprite::draw(BITMAP *bmp)
{
	//draw_sprite(bmp, _sprite, position.getX(), position.getY());
	rotate_sprite(bmp, _sprite, position.getX(), position.getY(), ftofix(rotation * rad_to_adeg));
}

void Sprite::update()
{
	
}
void Sprite::setPosition(Point position)
{
	this->position = position;
}

void Sprite::setPosition(int x, int y)
{
	this->position.setX(x);
	this->position.setY(y);
}

Point Sprite::getPosition()
{
	return this->position;
}

int Sprite::getPositionX()
{
	return this->position.getX();
}

int Sprite::getPositionY()
{
	return this->position.getY();
}

void Sprite::move(Point howMuch)
{
	this->position.setX(position.getX() + howMuch.getX());
	this->position.setY(position.getY() + howMuch.getY());
}

void Sprite::rotate(int angle)
{
	this->rotation += angle;
}
