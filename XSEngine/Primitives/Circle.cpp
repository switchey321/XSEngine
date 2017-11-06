#include "../Primitives.hpp"

Circle::Circle(int x1, int y1, int radius, int color, bool fill) {
	this->x1 = x1;
	this->y1 = y1;
	this->radius = radius;
	this->color = color;
	this->fill = fill;
}

Circle::Circle(int x1, int y1, int radius, int r, int g, int b, bool fill) {
	this->x1 = x1;
	this->y1 = y1;
	this->radius = radius;
	this->color = makecol(r, g, b);
	this->fill = fill;
}

void Circle::draw(BITMAP* bmp) {
	if (fill)
		circlefill(bmp, x1, y1, radius, color);
	else
		circle(bmp, x1, y1, radius, color);
}

void Circle::calcArea() {
	if (key[KEY_A]) {
		this->area = M_PI * pow(this->radius, 2);
		textprintf_centre_ex(screen, font, x1, y1 + 15, white, -1, "Pole: %.2f", this->area);
	}
}

void Circle::calcPerimeter() {
	if (key[KEY_P]) {
		this->perimeter = 2 * M_PI * this->radius;
		textprintf_centre_ex(screen, font, x1, y1, white, -1, "Obwod: %.2f", this->perimeter);
	}
}

void Circle::calcCenter() {
	if (key[KEY_C]) {
		textprintf_centre_ex(screen, font, x1, y1 - 30, white, -1, "Punkt srodka:");
		textprintf_centre_ex(screen, font, x1, y1 - 15, white, -1, "(%d, %d)", this->x1, this->y1);
	}
}
