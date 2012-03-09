/*
 * generalDrawing.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "../inc.h"
#define HORIZONTAL_GRID_LINES 10
#define VERTICAL_GRID_LINES 10

void drawGrid() {
	float floatGridMarker;
	for(int i=0;i<HORIZONTAL_GRID_LINES;i++) {
		floatGridMarker = -X_AXIS_SIZE + i*(2*X_AXIS_SIZE/HORIZONTAL_GRID_LINES);
		glColor3f(0,0,0);
		glBegin(GL_LINE);
			glVertex2f(floatGridMarker,Y_AXIS_SIZE);
			glVertex2f(floatGridMarker,-Y_AXIS_SIZE);
		glEnd();
	}
	for(int i=0;i<VERTICAL_GRID_LINES;i++) {
		floatGridMarker = -Y_AXIS_SIZE + i*(2*Y_AXIS_SIZE/VERTICAL_GRID_LINES);
		glColor3f(0,0,0);
		glBegin(GL_LINE);
			glVertex2f(X_AXIS_SIZE,floatGridMarker);
			glVertex2f(-X_AXIS_SIZE,floatGridMarker);
		glEnd();
	}
}

void initScreen (void)
{
/*  select clearing (background) color       */
    glClearColor (1.0, 1.0, 1.0, 0.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-X_AXIS_SIZE, X_AXIS_SIZE, -Y_AXIS_SIZE, Y_AXIS_SIZE, -Z_AXIS_SIZE, Z_AXIS_SIZE);
}
