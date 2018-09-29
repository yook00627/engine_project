#pragma once
#include <glew/glew.h>
#include <GLFW/glfw3.h>
#include <Math.h>
#include "../physics/physics.h"

void drawcircle(float radius, int sides);

class base_shape {
public:
	//base_shape();
	physics vectors;
};

class Triangle : public base_shape {
private:
	float t_width, t_height;

public:
	Triangle(float width, float height);
	void create_triangle(double deltat);
};

class Rectangle : public base_shape {
private:
	float r_width, r_height;

public:
	Rectangle(float width, float height);
	void draw_rectangle();
};

class Square : public Rectangle {

public:
	Square(float edge);
};