/*
 * bounce.cpp
 *
 *  Created on: Mar 10, 2012
 *      Author: andre
 */

#include "../inc.h"

void agent::increaseBounceTimer() {
	floatBounceTimer += floatEnergyLossBounce*0.0001;
}

float agent::energyLossCoefficient() {
	//cout << "Timer: " << floatBounceTimer << "  e^(-timer): " << exp(-floatBounceTimer) << " Y speed: " << floatAgentSpeed[Y_AXIS] << endl;
	return (exp(-floatBounceTimer));
}

void agent::resetBounceTimer() {
	floatBounceTimer = 0;
}
