#include "../Primitives.hpp"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->color = color;
}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->xC = (this->x1 + this->x2 + this->x3) / 3;
	this->yC = (this->y1 + this->y2 + this->y3) / 3;
	this->color = makecol(r, g, b);
}

void Triangle::draw(BITMAP* bmp) {
	triangle(bmp, x1, y1, x2, y2, x3, y3, color);
}

void Triangle::calcArea() {
	if (key[KEY_A]) {
		float d_x = (x2 + x3) / 2;
		float d_y = (y2 + y3) / 2;
		this->height = sqrt(pow((d_x - x1), 2) + pow((d_y - y1), 2));
		float bc = sqrt(pow((x3 - x2), 2) + pow(y3 - y2, 2));
		this->area = (bc*height) / 2;

		textprintf_centre_ex(screen, font, ((x1 + x2 + x3) / 3), ((y1 + y2 + y3) / 3) + 15, white, -1, "Pole: %.2f", this->area);
	}
}

void Triangle::calcPerimeter() {
	if (key[KEY_P]) {
		float ab = sqrt(pow((x2 - x1), 2) + pow(y2 - y1, 2));
		float bc = sqrt(pow((x3 - x2), 2) + pow(y3 - y2, 2));
		float ca = sqrt(pow((x1 - x3), 2) + pow(y1 - y3, 2));
		this->perimeter = ab + bc + ca;

		textprintf_centre_ex(screen, font, (x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, white, -1, "Obwod: %.2f", this->perimeter);
	}
}

void Triangle::calcCenter() {
	if (key[KEY_C]) {
		this->xC = (int)((x1 + x2 + x3) / 3);
		this->yC = (int)((y1 + y2 + y3) / 3);

		textprintf_centre_ex(screen, font, ((x1 + x2 + x3) / 3), ((y1 + y2 + y3) / 3) - 30, white, -1, "Punkt srodka:");
		textprintf_centre_ex(screen, font, ((x1 + x2 + x3) / 3), ((y1 + y2 + y3) / 3) - 15, white, -1, "(%d, %d)", this->xC, this->yC);
	}
}