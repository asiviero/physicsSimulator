/*
 * constants.h
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 *
 *  This file will contain several constants, mostly physical and mathematical
 *  constants, such as Pi, Euler Number, the Gravitational Constant and many
 *  others usually present in physical equations that govern movement
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_


// Agent Constants
#define AGENT_MASS 1
#define AGENT_FRICTION_COEFFICIENT_STATIC 1
#define AGENT_FRICTION_COEFFICIENT_DYNAMIC 0.1

// True / False
#define TRUE 1
#define FALSE 0

#define PI 3.14159265
#define EULER_NUMBER 2.71828182846
#define LIGHT_SPEED 299792458
#define GRAVITATIONAL_CONSTANT 6.6742E-11

// Constant modified for smoothness on falls
#define EARTH_GRAVITY 9.80665e-1
#define STD_FORCE_VERTICAL 1e-1
#define STD_FORCE_HORIZONTAL 0.2e-1

// These constants stand for the maximum coordinates allowed in a screen
#define X_AXIS_SIZE 1e6
#define Y_AXIS_SIZE 1e6
#define Z_AXIS_SIZE 1e6

// These constants stand for the width and height of the main window
#define MAIN_WINDOW_WIDTH 400
#define MAIN_WINDOW_HEIGHT 400

// These constants concern constants for keyboard keys
#define ESC_KEY 27

// Constants used in motion vectors, such as position, speed and acceleration
#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2

// Constants used in color vectors
#define RED_PCT 0
#define GREEN_PCT 1
#define BLUE_PCT 2

// Constant for the agent size
#define AGENT_SIZE 10

// Directional constants
#define UP_CONSTANT 0
#define DOWN_CONSTANT 1
#define LEFT_CONSTANT 2
#define RIGHT_CONSTANT 3

// Coefficient index constants
#define STATIC 0
#define DYNAMIC 1

// Material index constants
#define EARTH 0
#define RUBBER 1
#define LUBE 2
#define LEATHER 3


#endif /* CONSTANTS_H_ */
