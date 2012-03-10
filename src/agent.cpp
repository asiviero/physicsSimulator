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
	floatAgentPosition[Y_AXIS] = Y_AXIS_SIZE;
	floatAgentMass = 1;
	gravitySet = TRUE;
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
	setGravity();

	cout << "Acc Y: " << floatAgentAcceleration[Y_AXIS] << " Acc X: " << floatAgentAcceleration[X_AXIS] << endl << "intMoveUp: " << intMoveUp << endl;

	// setting gravity effect
	if(gravitySet) {
		floatAgentForce[Y_AXIS] -= EARTH_GRAVITY/floatAgentMass;
	}

	// check for ground
	if(floatAgentPosition[Y_AXIS] <= 0) {
		//reset speed and acceleration vectors in Y axis
		floatAgentAcceleration[Y_AXIS] = floatAgentSpeed[Y_AXIS] = 0;
	}

	directionalMoviment();

	for(int i=0;i<3;i++) {
		floatAgentAcceleration[i] = floatAgentForce[i]/floatAgentMass;
		floatAgentSpeed[i] += floatAgentAcceleration[i];
		floatAgentPosition[i] += floatAgentSpeed[i];
		}

	//cout << "Speed Y: " << floatAgentSpeed[Y_AXIS] << " Speed X: " << floatAgentSpeed[X_AXIS] << endl;

	// removing gravity effect
	if(gravitySet) {
		floatAgentForce[Y_AXIS] += EARTH_GRAVITY/floatAgentMass;
	}

	// resetting input forces
	resetDirectionalMoviment();

	// this is for testing gravity
	if(floatAgentPosition[Y_AXIS] > 100) resetForces(Y_AXIS);
}

void agent::setGravity() {
	if(floatAgentPosition[Y_AXIS] <= 0) gravitySet = FALSE;
	else gravitySet = TRUE;
}

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
	floatAgentForce[Y_AXIS] += intMoveUp*STD_ACC;
	floatAgentForce[Y_AXIS] -= intMoveDown*STD_ACC;

	floatAgentForce[X_AXIS] += intMoveRight*STD_ACC;
	floatAgentForce[X_AXIS] -= intMoveLeft*STD_ACC;
}

void agent::resetDirectionalMoviment() {
	intMoveUp = intMoveDown = intMoveLeft = intMoveRight = FALSE;
}

void agent::resetForces(int axis) {
	floatAgentForce[axis] = 0;
}
