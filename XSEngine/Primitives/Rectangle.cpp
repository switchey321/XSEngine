#include "../Primitives.hpp"

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int color, bool fill) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->color = color;
	this->fill = fill;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int r, int g, int b, bool fill) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->color = makecol(r, g, b);
	this->fill = fill;
}

void Rectangle::draw(BITMAP* bmp) {
	if (fill) 
		rectfill(bmp, x1, y1, x2, y2, color);
	else
		rect(bmp, x1, y1, x2, y2, color);
}

void Rectangle::calcArea() {
	if (key[KEY_A]) {
		this->area = ((2 * sqrt(pow((x2 - x1), 2))) + (2 * sqrt(pow((y2 - y1), 2))));
		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) + 15, white, -1, "Pole: %.2f", this->area);
	}
}

void Rectangle::calcPerimeter() {
	if (key[KEY_P]) {
		this->perimeter = (sqrt(pow((x2 - x1), 2)) * sqrt(pow((y2 - y1), 2)));
		textprintf_centre_ex(screen, font, (x1 + x2) / 2, (y1 + y2) / 2, white, -1, "Obwod: %.2f", this->perimeter);
	}
}

void Rectangle::calcCenter() {
	if (key[KEY_C]) {
		this->xC = (int)((x1 + x2) / 2);
		this->yC = (int)((y1 + y2) / 2);

		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) - 30, white, -1, "Punkt srodka:");
		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) - 15, white, -1, "(%d, %d)", this->xC, this->yC);
	}
}