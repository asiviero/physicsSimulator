/*
 * main.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "inc.h"

agent *mainAgent = new agent(STANDARD_LOSS_COEFFICIENT);
void display(void);

int main(int argc, char** argv) {
	// Init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(1200,800);
	glutInitWindowSize(MAIN_WINDOW_WIDTH,MAIN_WINDOW_HEIGHT);
	int intMainWindowID;
	intMainWindowID = glutCreateWindow("Physics Simulator");

	// Handler Functions
	glutKeyboardFunc(keyboardHandler);
	glutSpecialFunc(specialKeysHandler);

	// Rendering
	initScreen();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

void display(void)
{
/*  clear all pixels  */

		glClear (GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		// Simulator functions begin here
		drawGrid();
		mainAgent->drawAgent();
		mainAgent->moveAgent();
		// Simulator functions end here
		glPopMatrix();
		glutPostRedisplay();
		glutSwapBuffers();

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
		case GLUT_KEY_END:
			mainAgent->resetForces(X_AXIS);
			mainAgent->resetForces(Y_AXIS);
			break;
		default:
			mainAgent->setMoveDirectional(NULL);
	}
}
