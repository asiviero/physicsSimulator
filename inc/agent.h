/*
 * agent.h
 *
 *  Created on: Mar 8, 2012
 *      Author: andre
 *
 *  An agent is a controllable object in the simulator.
 *
 *  Its class contains information about its current position, speed, acceleration in space and material properties,
 *  such as its mass.
 *
 */

#ifndef AGENT_H_
#define AGENT_H_

	class agent {
		protected:
			float floatAgentPosition[3], floatAgentSpeed[3], floatAgentAcceleration[3], floatAgentForce[3];
			float floatAgentMass;
			float floatAgentColor[3];
			bool gravitySet;
			bool boolMoveUp, boolMoveDown, boolMoveLeft, boolMoveRight;

		public:
			// Initializing methods
			agent();
			void drawAgent();

			// General functions
			void moveAgent();
			void updateMovementVectors();

			// Directional movement methods, controlled by user input
			void directionalMovement();
			void setMoveDirectional(int dir);
			void resetDirectionalMovement();

			// Gravity Functions
			void setGravity();

			// This function might be used to establish boundaries in the grid
			// After it has been called, inertia will control the Agent movement
			void resetForces(int axis);
	};


#endif /* AGENT_H_ */
