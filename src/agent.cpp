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
	gravitySet = true;
}

// Since the agent can be represented as a single spot in the screen, this is very simple to draw
// Its color and size can be altered in inc/constants.h
void agent::drawAgent() {
	glPointSize(AGENT_SIZE);
	glBegin(GL_POINTS);
		glColor3f(floatAgentColor[RED_PCT],floatAgentColor[GREEN_PCT],floatAgentColor[BLUE_PCT]);
		glVertex3f(floatAgentPosition[X_AXIS],floatAgentPosition[Y_AXIS],floatAgentPosition[Z_AXIS]);
	glEnd();
}

// This is the main movement function, and it'll get bigger and more complex as
// features are added. Currently it can be summed as:

/*
 * Working: Gravity, Directional Control
 *
 * To be implemented: Friction, Bouncing and Collision
 *
 */
void agent::moveAgent() {
	// Determines if the body should or should not suffer gravity effect. Boolean var gravitySet is updated
	setGravity();

	// setting gravity effect
	if(gravitySet) {
		floatAgentForce[Y_AXIS] -= EARTH_GRAVITY/floatAgentMass;
	}

	// check for ground
	if(floatAgentPosition[Y_AXIS] <= 0) {
		//reset speed and acceleration vectors in Y axis
		floatAgentAcceleration[Y_AXIS] = floatAgentSpeed[Y_AXIS] = 0;
	}

	// After ground checking, directional control is applied, in a manner that ground
	// effect of nulling speed and acceleration in the Y axis won't affect further movement
	directionalMovement();

	// Updates the movement vectors (acceleration, speed and position)
	updateMovementVectors();

	// removing gravity effect
	if(gravitySet) {
		floatAgentForce[Y_AXIS] += EARTH_GRAVITY/floatAgentMass;
	}

	// resetting input forces
	resetDirectionalMovement();

	// this is for testing gravity
	//if(floatAgentPosition[Y_AXIS] > Y_AXIS_SIZE/3) resetForces(Y_AXIS);
}

// Basic function to update the vectors, from lowest to highest level
void agent::updateMovementVectors() {
	for(int i=0;i<3;i++) {
		floatAgentAcceleration[i] = floatAgentForce[i]/floatAgentMass;
		floatAgentSpeed[i] += floatAgentAcceleration[i];
		floatAgentPosition[i] += floatAgentSpeed[i];
	}
}

void agent::setGravity() {
	if(floatAgentPosition[Y_AXIS] <= 0) gravitySet = false;
	else gravitySet = true;
}

// This function controls if and where to the agent should move
void agent::setMoveDirectional(int dir) {
	switch(dir) {
		case UP_CONSTANT:
			if(boolMoveDown) {
				boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
				break;
			}
			boolMoveUp = true;
			boolMoveDown = false;
			boolMoveLeft = false;
			boolMoveRight = false;
			break;
		case DOWN_CONSTANT:
			if(boolMoveUp) {
				boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
				break;
			}
			boolMoveUp = false;
			boolMoveDown = true;
			boolMoveLeft = false;
			boolMoveRight = false;
			break;
		case LEFT_CONSTANT:
			if(boolMoveRight) {
				boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
				break;
			}
			boolMoveUp = false;
			boolMoveDown = false;
			boolMoveLeft = true;
			boolMoveRight = false;
			break;
		case RIGHT_CONSTANT:
			if(boolMoveLeft) {
				boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
				break;
			}
			boolMoveUp = false;
			boolMoveDown = false;
			boolMoveLeft = false;
			boolMoveRight = true;
			break;
		default:
			boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
			break;
	}
}

// Apply what was defined in setMoveDirectional
void agent::directionalMovement() {
	floatAgentForce[Y_AXIS] += boolMoveUp*STD_FORCE;
	floatAgentForce[Y_AXIS] -= boolMoveDown*STD_FORCE;

	floatAgentForce[X_AXIS] += boolMoveRight*STD_FORCE;
	floatAgentForce[X_AXIS] -= boolMoveLeft*STD_FORCE;
}

void agent::resetDirectionalMovement() {
	boolMoveUp = boolMoveDown = boolMoveLeft = boolMoveRight = false;
}

void agent::resetForces(int axis) {
	floatAgentForce[axis] = 0;
}
