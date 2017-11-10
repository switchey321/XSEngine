#include "..\Sprite.hpp"


Sprite::Sprite()
{
	this->position = Point(0, 0);
	this->origin = Point(0, 0);
	this->rotation = 0;
}

Sprite::Sprite(char *filename) : Sprite()
{
	_sprite = load_bitmap(filename, NULL);
	this->origin = Point(_sprite->w, _sprite->h);
	size = 1;
}

Sprite::Sprite(char *filename, Point position) : Sprite(filename){
	this->position = position;
}

Sprite::Sprite(char *filename, Point position, double size) : Sprite(filename, position)
{
	this->size = size;
}

Sprite::Sprite(char *filename, Point position, double size, Point origin) : Sprite(filename, position, size)
{
	this->origin = origin;
}

Sprite::~Sprite()
{
}

void Sprite::draw(BITMAP *bmp)
{
	auto angle = ftofix(60) + ftofix(this->rotation);
	//draw_sprite(bmp, _sprite, position.getX(), position.getY());
	//rotate_sprite(bmp, _sprite, position.getX(), position.getY(), angle);
	rotate_scaled_sprite(bmp, _sprite, position.getX(), position.getY(), angle, ftofix(1));
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

void Sprite::rotate(double angle)
{
	this->rotation = angle * rad_to_adeg;
}

void Sprite::followMouseRotation()
{
	auto dx = (mouse_x - (position.getX() + _sprite->w/2));
	auto dy = (mouse_y - (position.getY() + _sprite->h/2));
	auto angle = atan2(dy, dx);

	this->rotation = angle * rad_to_adeg;
}

void Sprite::followMouse()
{
	auto velocity = 0.1;
	Point real_position = Point(position.getX() + origin.getX(), position.getY() + origin.getY());

	auto x_diff = abs(mouse_x - position.getX());
	auto y_diff = abs(mouse_y - position.getY());

	auto goto_x_plus =(position.getX()) + velocity * x_diff;
	auto goto_y_plus = (position.getY()) + velocity * y_diff;
	auto goto_x_minus = (position.getX()) -velocity *  x_diff;
	auto goto_y_minus = (position.getY()) -velocity *  y_diff;



	if (x_diff > 80 || y_diff > 80) {
		if (mouse_x >= real_position.getX()) position.setX(goto_x_plus);
		else position.setX(goto_x_minus);
		if (mouse_y >= real_position.getY()) position.setY(goto_y_plus);
		else position.setY(goto_y_minus);
	}
}


