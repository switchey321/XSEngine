#include "..\TestScene3.hpp"


TestScene3::TestScene3()
{
	ship_ = Sprite("Sprites/ship1.bmp", Point(300,300));
}

void TestScene3::draw(BITMAP* bmp)
{
	Scene::clear(bmp);
	ship_.draw(bmp);
	blit(bmp, screen, 0, 0, 0, 0, screen->w, screen->h);
}

void TestScene3::update()
{
	ship_.update();
	if (mouse_b&1) ship_.followMouse();
	
	ship_.followMouseRotation();
}
