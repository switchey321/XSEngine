#pragma once

#define _USE_MATH_DEFINES
#include <vector>
#include "Colors.hpp"
#include <allegro.h>

//---------------------

class Circle
{
protected:
	int x1, y1, radius;
	int color;
	bool fill;
	float area, perimeter;
public:
	Circle(int x1, int y1, int radius, int color, bool fill);
	Circle(int x1, int y1, int radius, int r, int g, int b, bool fill);
	void draw(BITMAP* bmp);
	void calcArea();
	void calcPerimeter();
	void calcCenter();
};

//--------------------

class Point
{
protected:
	int x, y;
public:
	Point();
	Point(int x, int y);
	int getX();
	int getY();
	void setY(int y);
	void setX(int x);
	void set(int x, int y);
};

//---------------------

class Line
{
protected:
	int x1, y1, x2, y2;
	int xC, yC;
	int color;
	float lenght;
public:
	Line();
	Line(int x1, int y1, int x2, int y2, int color);
	Line(int x1, int y1, int x2, int y2, int r, int g, int b);
	void draw(BITMAP* bmp);
	void draw(BITMAP* bmp, std::vector<Point> &vector);
	void calcLength();
	void calcCenter();
};

//---------------------

class Rectangle
{
protected:
	int x1, y1, x2, y2;
	int xC, yC;
	int color;
	bool fill;
	float width, height;
	float area, perimeter;
public:
	Rectangle(int x1, int y1, int x2, int y2, int color, bool fill);
	Rectangle(int x1, int y1, int x2, int y2, int r, int g, int b, bool fill);
	void draw(BITMAP* bmp);
	void calcArea();
	void calcPerimeter();
	void calcCenter();
};

//---------------------

class Square
{
protected:
	int x1, y1, x2, y2;
	int xC, yC;
	int color;
	bool fill;
	float width;
	float area, perimeter;
public:
	Square(int x1, int y1, int lenght, int color, bool fill);
	Square(int x1, int y1, int lenght, int r, int g, int b, bool fill);
	void draw(BITMAP* bmp);
	void calcArea();
	void calcPerimeter();
	void calcCenter();
};

//---------------------

class Triangle
{
protected:
	int x1, y1, x2, y2, x3, y3;
	int xC, yC;
	int color;
	float height;
	float area, perimeter;
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int r, int g, int b);
	void draw(BITMAP* bmp);
	void calcArea();
	void calcPerimeter();
	void calcCenter();
};

class Trapezoid
{
private:
	void tabToInts();
	void calcLenght();
protected:
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int xC, yC;
	float a, b, c, d;
	int color;
	float height;
	float area, perimeter;
	int vertices[8];
public:
	Trapezoid(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int color);
	Trapezoid(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int r, int g, int b);
	Trapezoid(int *points, int color);
	Trapezoid(int *points, int r, int g, int b);
	void draw(BITMAP* bmp);
	void calcArea();
	void calcPerimeter();
	void calcCenter();
};

