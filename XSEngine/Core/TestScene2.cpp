#include "../TestScene2.hpp"


TestScene2::TestScene2()
{
	prostokat1 = new Rectangle(100, 100, 200, 300, blue, true);
	prostokat2 = new Rectangle(100, 500, 600, 400, gold, false);
	kolo1 = new Circle(500, 200, 50, silver, true);
	kolo2 = new Circle(750, 99, 80, red, false);
	trojkat1 = new Triangle(1100, 300, 1000, 10, 1180, 200, magenta);
	trojkat2 = new Triangle(350, 150, 250, 150, 350, 350, gray);
	kwadrat1 = new Square(720, 500, 100, lime, true);
	kwadrat2 = new Square(1100, 400, 90, teal, false);
	linia1 = new Line(800, 450, 1200, 650, maroon);
	linia2 = new Line(1180, 330, 700, 500, olive);
	trapez1 = new Trapezoid(40, 520, 500, 520, 300, 620, 120, 620, green);
	trapez2 = new Trapezoid(points2, navy);

}

void TestScene2::draw(BITMAP *bmp)
{
	Scene::clear(bmp);

	prostokat1->draw(bmp);
	prostokat2->draw(bmp);
	kolo1->draw(bmp);
	kolo2->draw(bmp);
	trojkat1->draw(bmp);
	trojkat2->draw(bmp);
	kwadrat1->draw(bmp);
	kwadrat2->draw(bmp);
	linia1->draw(bmp);
	linia2->draw(bmp);
	trapez1->draw(bmp);
	trapez2->draw(bmp);

	blit(bmp, screen, 0, 0, 0, 0, screen->w, screen->h);

	trojkat1->calcPerimeter();
	trojkat2->calcPerimeter();
	trojkat1->calcArea();
	trojkat2->calcArea();
	trojkat1->calcCenter();
	trojkat2->calcCenter();
	kolo1->calcPerimeter();
	kolo2->calcPerimeter();
	kolo1->calcArea();
	kolo2->calcArea();
	kolo1->calcCenter();
	kolo2->calcCenter();
	prostokat1->calcPerimeter();
	prostokat2->calcPerimeter();
	prostokat1->calcArea();
	prostokat2->calcArea();
	prostokat1->calcCenter();
	prostokat2->calcCenter();
	kwadrat1->calcPerimeter();
	kwadrat1->calcArea();
	kwadrat2->calcPerimeter();
	kwadrat2->calcArea();
	kwadrat1->calcCenter();
	kwadrat2->calcCenter();
	linia1->calcLength();
	linia2->calcLength();
	linia1->calcCenter();
	linia2->calcCenter();
	trapez1->calcArea();
	trapez1->calcPerimeter();
	trapez1->calcCenter();
	trapez2->calcArea();
	trapez2->calcPerimeter();
	trapez2->calcCenter();
}

void TestScene2::update()
{
}

