#include "shapes.h"
#include <iostream>
// Creates a rectangle based on height and width parameters

Rectangle::Rectangle(float width, float height) {
	//sets private width and height
	r_width = width;
	r_height = height;
};

void Rectangle::draw_rectangle() {
	//aspect ratio compensation
	float new_height = (r_height / 9) / 2;
	float new_width = (r_width / 16) / 2;

	//start drawing based on triangles
	glBegin( GL_TRIANGLES );

	glVertex2f(new_width + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(-new_width + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(new_width + vectors.pos.x, -new_height + vectors.pos.y);

	glVertex2f(-new_width + vectors.pos.x, new_height + vectors.pos.y);
	glVertex2f(new_width + vectors.pos.x, -new_height + vectors.pos.y);
	glVertex2f(-new_width + vectors.pos.x, -new_height + vectors.pos.y);
	//run program to get new position
	//vectors.update_position(deltat);
	std::cout << "draw accel.y: " << &vectors.accel.y << std::endl;
	std::cout << "draw pos.y: " << &vectors.pos.y << std::endl;
	glEnd();
}