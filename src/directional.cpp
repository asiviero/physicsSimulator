/*
 * directional.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

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
