#pragma once
#include "Scene.hpp"
#include "Sprite.hpp"

class TestScene3 : public Scene
{
private:
	Sprite ship_;
public:
	TestScene3();

	void draw(BITMAP* bmp) override;
	void update() override;
};
