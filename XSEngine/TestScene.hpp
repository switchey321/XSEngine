#pragma once
#include "Scene.hpp"
#include "Primitives.hpp"

class TestScene : public Scene
{
private:
	Line* vectorLine;
	std::vector<Point> vector;
public:
	TestScene();
	void draw(BITMAP *bmp) override;
	void update() override;
};
