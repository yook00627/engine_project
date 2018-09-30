#if 1
#include <iostream>
#include <math.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "src/window/window.h"
#include "src/shapes/shapes.h"


int main(int argc, char *argv)
{
	using namespace engine;
	using namespace graphics;
	using namespace input;

	//FULL SCREEN MODE OR WIDNOW MODE
	Window window(SCREEN_NAME, SCREEN_WIDTH, SCREEN_HEIGHT);
	glClearColor(0.3f, 0.3f, 0.3f, 0.0f);
	KeyboardMouse input_keys;
	GLuint var;


	double old_time = 0;
	double new_time = 0;

	glGenVertexArrays(1, &var);
	glBindVertexArray(var);

	const float DEG2RAD = 3.14159f / 180.0f;
	//IMPORTANT CREATE OBJECTS OUTSIDE OF LOOP, VECTOR CONSTRUCTOR REFRESHES VECTORS OTHERWISE
	//Square r(0.5f, 0.0f, 0.0f);
	Circle ball(0.05f, 0.0f, 0.5f);
	bool sw = false;
	ball.vectors.vel.x = 0.5f;

	FT_Library ft;

	if (FT_Init_FreeType(&ft)) {
		fprintf(stderr, "Could not init freetype library\n");
		return 1;
	}

	while (!window.closed())
	{
		window.clear();
		old_time = new_time;
		new_time = glfwGetTime();
		//std::cout << new_time << std::endl;
		//r.draw_rectangle();
		ball.drawCircle();


		if (ball.vectors.pos.x > .8 || ball.vectors.pos.x < -.8)
			ball.vectors.vel.x = -ball.vectors.vel.x;

		
		ball.vectors.update_position(new_time - old_time);

		if (sw)
		{
			//r.vectors.update_position(new_time - old_time);
			ball.vectors.vel.x = 0.0f;
			ball.vectors.accel.y = -9.8f;
			ball.vectors.update_position(new_time - old_time);
		}

		if (input_keys.key_pressed(GLFW_KEY_SPACE))
		{
			sw = true;
			std::cout << "pressed space" << std::endl;
		}

		if (input_keys.key_pressed(GLFW_KEY_F11))
		{
			window.windowSizeToggle();
		}

		if (input_keys.mouse_button_pressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			std::cout << "pressed mouse" << std::endl;
		}
		
		
		//double x, y;
		//input_keys.get_mouse_position(x, y);
		//std::cout << "x postion: " << x << " y position: " << y << std::endl;

		window.update();
	}

	return 0;
}
#endif


#if 0
#include <stdio.h>
#include <GL/glut.h>

GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;

void reshape(int width, int heigth) {
	/* window ro reshape when made it bigger or smaller*/

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//clip the windows so its shortest side is 2.0
	if (width < heigth) {
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)heigth / (GLfloat)width, 2.0 * (GLfloat)heigth / (GLfloat)width, 2.0, 2.0);
	}
	else {
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)width / (GLfloat)heigth, 2.0 * (GLfloat)width / (GLfloat)heigth, 2.0, 2.0);
	}
	// set viewport to use the entire new window
	glViewport(0, 0, width, heigth);
}

void rect() {
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-0.1, -0.2);
	glVertex2f(-0.1, 0.2);
	glVertex2f(0.1, 0.2);
	glVertex2f(0.1, -0.2);
	glEnd();

}

void display() {
	//Clear Window
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	rect();
	glPopMatrix();
	glFlush();
}


void init() {
	// set clear color to black
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// set fill color to white
	glColor3f(1.0, 1.0, 1.0);

	//set up standard orthogonal view with clipping
	//box as cube of side 2 centered at origin
	//This is the default view and these statements could be removed
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

}
float move_unit = 0.04f;
void keyboardown(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
		posX += move_unit;;
		break;

	case GLUT_KEY_LEFT:
		posX -= move_unit;;
		break;

	case GLUT_KEY_UP:
		posY += move_unit;;
		break;

	case GLUT_KEY_DOWN:
		posY -= move_unit;;
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv) {

	//initialize mode and open a windows in upper left corner of screen
	//Windows tittle is name of program

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Practice 1");
	glutDisplayFunc(display);
	init();
	glutSpecialFunc(keyboardown);
	glutMainLoop();
}
#endif