#include "..\TestScene3.hpp"



TestScene3::TestScene3()
{
	ship = Sprite("Sprites/ship1.bmp", Point(300,300));
}


TestScene3::~TestScene3()
{
}


void TestScene3::draw(BITMAP* bmp)
{
	Scene::clear(bmp);
	ship.draw(bmp);
	blit(bmp, screen, 0, 0, 0, 0, screen->w, screen->h);
}

void TestScene3::update()
{
	ship.update();
	if (key[KEY_UP]) ship.move(Point(0, -2));
	if (key[KEY_DOWN]) ship.move(Point(0, 2));
	if (key[KEY_LEFT]) ship.move(Point(-2, 0));
	if (key[KEY_RIGHT]) ship.move(Point(2, 0));
	int angle = atan2(ship.getPositionX() - mouse_x, (ship.getPositionY()- mouse_y)); // TODO: fix ship rotation to mouse cursor
	ship.rotate(angle);
}
