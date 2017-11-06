#include "../Primitives.hpp"

Trapezoid::Trapezoid(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int color) {
	this->vertices[0] = x1;
	this->vertices[1] = y1;
	this->vertices[2] = x2;
	this->vertices[3] = y2;
	this->vertices[4] = x3;
	this->vertices[5] = y3;
	this->vertices[6] = x4;
	this->vertices[7] = y4;
	tabToInts();
	this->color = color;
}

Trapezoid::Trapezoid(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int r, int g, int b) {
	this->vertices[0] = x1;
	this->vertices[1] = y1;
	this->vertices[2] = x2;
	this->vertices[3] = y2;
	this->vertices[4] = x3;
	this->vertices[5] = y3;
	this->vertices[6] = x4;
	this->vertices[7] = y4;
	tabToInts();
	this->color = makecol(r, g, b);
}

Trapezoid::Trapezoid(int *points, int color) {
	for (int i = 0; i < 8; i++)
		this->vertices[i] = points[i];

	tabToInts();
	this->color = color;
}

Trapezoid::Trapezoid(int *points, int r, int g, int b) {
	for (int i = 0; i < 8; i++)
		this->vertices[i] = points[i];

	tabToInts();
	this->color = makecol(r, g, b);
}

void Trapezoid::tabToInts() {
	this->x1 = vertices[0];
	this->y1 = vertices[1];
	this->x2 = vertices[2];
	this->y2 = vertices[3];
	this->x3 = vertices[4];
	this->y3 = vertices[5];
	this->x4 = vertices[6];
	this->y4 = vertices[7];
}

void Trapezoid::calcLenght() {
	this->a = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	this->b = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
	this->c = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	this->d = sqrt(pow((x4 - x1), 2) + pow((y4 - y1), 2));
}

void Trapezoid::draw(BITMAP* bmp) {
	calcLenght();
	if ((y1 == y2) && (y3 == y4) && (pow((a - b), 2) >= abs(pow(c, 2) - pow(d, 2))))
		polygon(bmp, 4, vertices, color);
}

void Trapezoid::calcArea() {
	if (key[KEY_A]) {
		calcLenght();
		float b_x = x1;
		float b_y = y4;
		this->height = sqrt(pow((b_x - x1), 2) + pow((b_y - y1), 2));
		this->area = ((a + b) / 2)*height;
		this->xC = (int)((((x2 + x3) / 2) + ((x1 + x4) / 2)) / 2);
		this->yC = (int)((((y2 + y3) / 2) + ((y1 + y4) / 2)) / 2);

		textprintf_centre_ex(screen, font, xC, yC + 15, white, -1, "Pole: %.2f", this->area);
	}
}

void Trapezoid::calcPerimeter() {
	if (key[KEY_P]) {
		calcLenght();
		this->perimeter = a + b + c + d;
		this->xC = (int)((((x2 + x3) / 2) + ((x1 + x4) / 2)) / 2);
		this->yC = (int)((((y2 + y3) / 2) + ((y1 + y4) / 2)) / 2);

		textprintf_centre_ex(screen, font, xC, yC, white, -1, "Obwod: %.2f", this->perimeter);
	}
}

void Trapezoid::calcCenter() {
	if (key[KEY_C]) {
		this->xC = (int)((((x2 + x3) / 2) + ((x1 + x4) / 2))/2);
		this->yC = (int)((((y2 + y3) / 2) + ((y1 + y4) / 2)) / 2);

		textprintf_centre_ex(screen, font, xC, yC - 30, white, -1, "Punkt srodka:");
		textprintf_centre_ex(screen, font, xC, yC - 15, white, -1, "(%d, %d)", this->xC, this->yC);
	}
}
