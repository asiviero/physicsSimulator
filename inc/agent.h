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

	class agent {// : public gravityClass {
		protected:
			float floatAgentPosition[3], floatAgentSpeed[3], floatAgentAcceleration[3], floatAgentForce[3];
			float floatAgentMass;
			float floatAgentColor[3];
			int gravitySet;
			int intMoveUp, intMoveDown, intMoveLeft, intMoveRight;

		public:
			agent();
			void drawAgent();
			void moveAgent();
			void setGravity();
			void directionalMoviment();
			void setMoveDirectional(int dir);
			void resetDirectionalMoviment();
			void resetForces(int axis);
	};


#endif /* AGENT_H_ */
