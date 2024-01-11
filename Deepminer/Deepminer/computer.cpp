#include "computer.h"
#include "config.h"

#include <iostream>

computer::computer(int score, int xCoord, int yCoord, bool sortDesc, bool firstThree, bool evenOdd)
{
	this->score = score;
	this->xCoord = xCoord;
	this->yCoord = yCoord;

	this->sortDesc = sortDesc;
	this->firstThree = firstThree;
	this->evenOdd = evenOdd;
}

computer::~computer()
{

}

void computer::computerMovement()
{
	int computerMovements = rand() % 4;

	switch (computerMovements)
	{
		case 0:
			if (this->yCoord > 0)
				this->yCoord--; 
			else
				this->yCoord++;
			break;

		case 1:
			if (this->xCoord > 0)
				this->xCoord--;
			else
				this->xCoord++;
			break;

		case 2:
			if (this->yCoord < Y_AXIS - 1)
				this->yCoord++;
			else
				this->yCoord--;
			break;

		case 3:
			if (this->xCoord < X_AXIS - 1)
				this->xCoord++;
			else
				this->xCoord--;
			break;
	}
}