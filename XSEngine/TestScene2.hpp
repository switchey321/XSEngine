#pragma once
#include "Scene.hpp"
#include "Primitives.hpp"

class TestScene2 : public Scene
{
private:
	Rectangle* prostokat1;
	Rectangle* prostokat2;
	Circle* kolo1;
	Circle* kolo2;
	Triangle* trojkat1;
	Triangle* trojkat2;
	Square* kwadrat1;
	Square* kwadrat2;
	Line* linia1;
	Line* linia2;
	Trapezoid* trapez1;
	int points2[8] = { 700,200,950,200,1100,350,700,350 };
	Trapezoid* trapez2;

public:
	TestScene2();
	void draw(BITMAP *bmp) override;
	void update() override;
};
