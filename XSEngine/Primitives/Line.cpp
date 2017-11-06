#include "../Primitives.hpp"

Line::Line()
{	
}

Line::Line(int x1, int y1, int x2, int y2, int color) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->color = color;
}

Line::Line(int x1, int y1, int x2, int y2, int r, int g, int b) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->color = makecol(r, g, b);
}

void Line::draw(BITMAP* bmp) {
	line(bmp, x1, y1, x2, y2, color);
}

void Line::draw(BITMAP* bmp, std::vector<Point> &vector)
{
	if (vector.size() > 1) {
		Point point1 = vector[0];
		for (int i = 1; i < vector.size(); i++) 
		{
			line(bmp, point1.getX(), point1.getY(), vector[i].getX(), vector[i].getY(), makeacol(255,0,0,0));
			point1 = Point(vector[i].getX(), vector[i].getY());
		}
	}
}

void Line::calcLength() {
	if (key[KEY_L]) {
		this->lenght = sqrt(pow((x2 - x1), 2) + pow(y2 - y1, 2));
		textprintf_centre_ex(screen, font, (x1 + x2) / 2, ((y1 + y2) / 2) + 15, white, -1, "Dlugosc: %.2f", this->lenght);
	}
}

void Line::calcCenter() {
	if (key[KEY_C]) {
		this->xC = (int)((x1 + x2) / 2);
		this->yC = (int)((y1 + y2) / 2);

		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2) - 15, white, -1, "Punkt srodka:");
		textprintf_centre_ex(screen, font, ((x1 + x2) / 2), ((y1 + y2) / 2), white, -1, "(%d, %d)", this->xC, this->yC);
	}
}

