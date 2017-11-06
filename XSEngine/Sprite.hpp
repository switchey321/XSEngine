#include "Primitives.hpp"
#include <allegro.h>
#include <math.h>


class Sprite
{
private:
	BITMAP *_buffer;
	BITMAP *_sprite;
	Point position;
	Point origin;
	int rotation;
	int rad_to_adeg = 128.0 / M_PI;

public:
	Sprite();
	Sprite(char *filename);
	Sprite(char *filename, Point position);
	Sprite(char *filename, Point position, Point origin);
	~Sprite();
	void draw(BITMAP *bmp);
	void update();
	void setPosition(Point position);
	void setPosition(int x, int y);
	Point getPosition();
	int getPositionX();
	int getPositionY();
	void move(Point howMuch);
	void rotate(int angle);
};
