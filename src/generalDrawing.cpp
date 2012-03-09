/*
 * generalDrawing.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#define HORIZONTAL_GRID_LINES 10
#define VERTICAL_GRID_LINES 10

#include "../inc.h"

void initScreen (void)
{
/*  select clearing (background) color       */
    glClearColor (1.0, 1.0, 1.0, 1.0);

/*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-X_AXIS_SIZE, X_AXIS_SIZE, -Y_AXIS_SIZE, Y_AXIS_SIZE, -Z_AXIS_SIZE, Z_AXIS_SIZE);
}


/*
 * This function draws a homogeneous bidimensional grid for better visualization. Its usage is optional.
 */
void drawGrid() {
	float floatGridMarker = 0;
	for(int i=0;i<HORIZONTAL_GRID_LINES;i++) {
		floatGridMarker = -X_AXIS_SIZE + i*(2*X_AXIS_SIZE/HORIZONTAL_GRID_LINES);
		glBegin(GL_LINE);
			glColor3f(0,0,0);
			glVertex2f(floatGridMarker,Y_AXIS_SIZE);
			glVertex2f(floatGridMarker,-Y_AXIS_SIZE);
		glEnd();
	}
	for(int i=0;i<VERTICAL_GRID_LINES;i++) {
		floatGridMarker = -Y_AXIS_SIZE + i*(2*Y_AXIS_SIZE/VERTICAL_GRID_LINES);
		glBegin(GL_LINE);
			glColor3f(0,0,0);
			glVertex2f(X_AXIS_SIZE,floatGridMarker);
			glVertex2f(-X_AXIS_SIZE,floatGridMarker);
		glEnd();
	}
}
