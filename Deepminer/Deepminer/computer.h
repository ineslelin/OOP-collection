#pragma once

#include "robot.h"

class computer : public robot 
{
	public:
		computer(int score, int xCoord, int yCoord, bool sortDesc, bool firstThree, bool evenOdd);
		virtual ~computer();

		void computerMovement();
};

