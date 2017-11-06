#include "../Primitives.hpp"

Square::Square(int x1, int y1, int lenght, int color, bool fill) {
	this->x1 = x1;
	this->y1 = y1;
	this->width = lenght;
	this->x2 = x1 + lenght;
	this->y2 = y1 + lenght;
	this->color = color;
	this->fill = fill;
}

Square::Square(int x1, int y1, int lenght, int r, int g, int b, bool fill) {
	this->x1 = x1;
	this->y1 = y1;
	this->width = lenght;
	this->x2 = x1 + lenght;
	this->y2 = y1 + lenght;
	this->color = makecol(r, g, b);
	this->fill = fill;
}

void Square::draw(BITMAP* bmp) {
	if (fill)
		rectfill(bmp, x1, y1, x2, y2, color);
	else
		rect(bmp, x1, y1, x2, y2, color);
}

void Square::calcArea() {
	if (key[KEY_A]) {
		this->area = pow(this->width, 2);
		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) + 15, white, -1, "Pole: %.2f", this->area);
	}
}

void Square::calcPerimeter() {
	if (key[KEY_P]) {
		this->perimeter = 4 * this->width;
		textprintf_centre_ex(screen, font, (x1 + x2) / 2, (y1 + y2) / 2, white, -1, "Obwod: %.2f", this->perimeter);
	}
}

void Square::calcCenter() {
	if (key[KEY_C]) {
		this->xC = (int)((x1 + x2) / 2);
		this->yC = (int)((y1 + y2) / 2);

		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) - 30, white, -1, "Punkt srodka:");
		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) - 15, white, -1, "(%d, %d)", this->xC, this->yC);
	}
}