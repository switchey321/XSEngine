#include "../TestScene.hpp"

TestScene::TestScene()
{
	vectorLine = new Line();

	vector.push_back(Point(100, 10));
	vector.push_back(Point(80, 100));
	vector.push_back(Point(300, 600));
	vector.push_back(Point(200, 150));
	vector.push_back(Point(40, 600));
	vector.push_back(Point(900, 500));
	vector.push_back(Point(800, 50));
}

void TestScene::draw(BITMAP *bmp)
{
	Scene::clear(bmp);

	vectorLine->draw(bmp, vector);

	blit(bmp, screen, 0, 0, 0, 0, screen->w, screen->h);
}

void TestScene::update()
{
	
}

