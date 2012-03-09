/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "inc.h"

agent *mainAgent = new agent();
void display(void);

int main(int argc, char** argv) {
	// Init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200,800);
	glutInitWindowSize(MAIN_WINDOW_WIDTH,MAIN_WINDOW_HEIGHT);
	int intMainWindowID;
	intMainWindowID = glutCreateWindow("Physichs Simulator");

	// Handler Functions
	glutKeyboardFunc(keyboardHandler);
	glutSpecialFunc(specialKeysHandler);

	// Creating the Agent
	//mainAgent = new agent();

	// Rendering
	initScreen();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void display(void)
{
/*  clear all pixels  */
    //while(1) {
		glClear (GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		drawGrid();
		mainAgent->drawAgent();
		mainAgent->moveAgent();
		glPopMatrix();
		glutPostRedisplay();
		glutSwapBuffers();
    //}
}

void specialKeysHandler(int button, int x, int y) {
	switch(button) {
		case GLUT_KEY_UP:
			mainAgent->setMoveDirectional(UP_CONSTANT);
			break;
		case GLUT_KEY_DOWN:
			mainAgent->setMoveDirectional(DOWN_CONSTANT);
			break;
		case GLUT_KEY_LEFT:
			mainAgent->setMoveDirectional(LEFT_CONSTANT);
			break;
		case GLUT_KEY_RIGHT:
			mainAgent->setMoveDirectional(RIGHT_CONSTANT);
			break;
		default:
			mainAgent->setMoveDirectional(NULL);
	}
}
