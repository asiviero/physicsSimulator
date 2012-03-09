/*
 * agent.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 */

#include "../inc.h"

agent::agent() {
	// Reset all vars, except the mass
	for(int i=0;i<3;i++) {
		floatAgentAcceleration[i] = 0;
		floatAgentSpeed[i] = 0;
		floatAgentColor[i] = 0;
		floatAgentPosition[i] = 0;
	}
	//floatAgentPosition[Y_AXIS] = Y_AXIS_SIZE;
	floatAgentMass = 1;
	gravitySet = false;
}

void agent::drawAgent() {
	glPointSize(10);
	glBegin(GL_POINTS);
		glColor3f(floatAgentColor[RED_PCT],floatAgentColor[GREEN_PCT],floatAgentColor[BLUE_PCT]);
		glVertex3f(floatAgentPosition[X_AXIS],floatAgentPosition[Y_AXIS],floatAgentPosition[Z_AXIS]);
	glEnd();
}

void agent::moveAgent() {
	//sleep(1);
	//gravity();
	directionalMoviment();
	cout << "Acc Y: " << floatAgentAcceleration[Y_AXIS] << " Acc X: " << floatAgentAcceleration[X_AXIS] << endl;

	for(int i=0;i<3;i++) {
		floatAgentSpeed[i] += floatAgentAcceleration[i];
		floatAgentPosition[i] += floatAgentSpeed[i];
		}

	cout << "Speed Y: " << floatAgentSpeed[Y_AXIS] << " Speed X: " << floatAgentSpeed[X_AXIS] << endl;

}

/*void agent::gravity() {
	if(floatAgentPosition[Y_AXIS] <= 0 && gravitySet != FALSE) {
		floatAgentAcceleration[Y_AXIS] = 0;
		floatAgentSpeed[Y_AXIS] = 0;
		gravitySet = FALSE;
	}
	else {
		if(floatAgentPosition[Y_AXIS] > 0) {
			if(gravitySet==TRUE) {
				floatAgentAcceleration[Y_AXIS] -= EARTH_GRAVITY;
				gravitySet++;
		}
	}
	}

}*/

void agent::setMoveDirectional(int dir) {
	switch(dir) {
		case UP_CONSTANT:
			if(intMoveDown) {
				intMoveUp = intMoveDown = intMoveLeft = intMoveRight = FALSE;
				break;
			}
			intMoveUp = TRUE;
			intMoveDown = FALSE;
			intMoveLeft = FALSE;
			intMoveRight = FALSE;
			break;
		case DOWN_CONSTANT:
			if(intMoveUp) {
				intMoveUp = intMoveDown = intMoveLeft = intMoveRight = FALSE;
				break;
			}
			intMoveUp = FALSE;
			intMoveDown = TRUE;
			intMoveLeft = FALSE;
			intMoveRight = FALSE;
			break;
		case LEFT_CONSTANT:
			if(intMoveRight) {
				intMoveUp = intMoveDown = intMoveLeft = intMoveRight = FALSE;
				break;
			}
			intMoveUp = FALSE;
			intMoveDown = FALSE;
			intMoveLeft = TRUE;
			intMoveRight = FALSE;
			break;
		case RIGHT_CONSTANT:
			if(intMoveLeft) {
				intMoveUp = intMoveDown = intMoveLeft = intMoveRight = FALSE;
				break;
			}
			intMoveUp = FALSE;
			intMoveDown = FALSE;
			intMoveLeft = FALSE;
			intMoveRight = TRUE;
			break;
		default:
			intMoveUp = intMoveDown = intMoveLeft = intMoveRight = FALSE;
			break;
	}
}

void agent::directionalMoviment() {
	floatAgentAcceleration[Y_AXIS] += intMoveUp*STD_ACC;
	floatAgentAcceleration[Y_AXIS] -= intMoveDown*STD_ACC;

	floatAgentAcceleration[X_AXIS] += intMoveRight*STD_ACC;
	floatAgentAcceleration[X_AXIS] -= intMoveLeft*STD_ACC;
}
