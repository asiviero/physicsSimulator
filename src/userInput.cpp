/*
 * userInput.cpp
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 *
 *  This file handles the user inputs, concerning keyboard, mouse and reshape input
 */

#include "../inc.h"

void keyboardHandler(unsigned char button, int x, int y) {
	switch(button) {
		case ESC_KEY:
			exit(0);
			break;
	}
}
