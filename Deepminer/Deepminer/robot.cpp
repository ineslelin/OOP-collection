#include "robot.h"
#include "map.h"
#include "config.h"

#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>

robot::robot()
{
	
}

robot::robot(int score, int xCoord, int yCoord, bool sortDesc, bool firstThree, bool evenOdd)
{
	this->score = score;
	this->xCoord = xCoord;
	this->yCoord = yCoord;

	this->sortDesc = sortDesc;
	this->firstThree = firstThree;
	this->evenOdd = evenOdd;
}

robot::~robot()
{

}

void robot::movement()
{
	char input = _getch();

	switch (input)
	{
		case 'w':
		case 'W':
			if (this->yCoord > 0)
				yCoord--;
			else {
				std::cout << ERROR_WRONGMOVE;
				input = _getch();
			}
			break;

		case 'a':
		case 'A':
			if (this->xCoord > 0)
				xCoord--;
			else {
				std::cout << ERROR_WRONGMOVE;
				input = _getch();
			}
			break;

		case 's':
		case 'S':
			if (this->yCoord < Y_AXIS - 1)
				yCoord++;
			else {
				std::cout << ERROR_WRONGMOVE;
				input = _getch();
			}
			break;

		case 'd':
		case 'D':
			if (this->xCoord < X_AXIS - 1)
				xCoord++;
			else {
				std::cout << ERROR_WRONGMOVE;
				input = _getch();
			}
			break;
			
		case SPACE_KEY:
			this->xCoord = xCoord;
			this->yCoord = yCoord;
			break;

		default: 
			std::cout << ERROR_WRONGMOVE;
			break;
	}
}

void robot::action(map* pMap)
{
	std::vector<int> zAxis (Z_AXIS);

	for (int z = 0; z < Z_AXIS; z++) {
		zAxis[z] = pMap->worldMap[z][this->yCoord][this->xCoord];
	}
	
	if (this->sortDesc == true)
	{
		sort(zAxis.begin(), zAxis.end(), std::greater<int>()); //sorts vector 

		score += zAxis[0];

		zAxis.erase(zAxis.begin());
		zAxis.push_back(0); // setting the last item in the vector to 0
	}

	if (this->firstThree == true)
	{
		for (int i = 0; i < 3; i++)
		{
			score += zAxis[0];

			zAxis.erase(zAxis.begin());
			zAxis.push_back(0);
		}
	}

	if (this->evenOdd == true)
	{
		if (zAxis[0] % 2 == 0)
		{
			score += zAxis[0];
			zAxis.erase(zAxis.begin());
			zAxis.push_back(0);

			for (int i = 0; i < Z_AXIS; i++)
			{
				if (zAxis[i] % 2 == 0) {
					score += zAxis[i];
					zAxis.erase(zAxis.begin() + i);
					zAxis.push_back(0);
				}
			}
		}
		else {
			score += zAxis[0];
			zAxis.erase(zAxis.begin());
			zAxis.push_back(0);

			for (int i = 0; i < Z_AXIS; i++)
			{
				if (zAxis[i] % 2 != 0) {
					score += zAxis[i];
					zAxis.erase(zAxis.begin() + i);
					zAxis.push_back(0);
				}
			}
		}
	}

	for (int z = 0; z < Z_AXIS; z++) {
		pMap->worldMap[z][this->yCoord][this->xCoord] = zAxis[z];
	}

	if (this->score % 50 == 0)
		pMap->shuffleWorld();
}

int robot::getScore()				{ return this->score; }
void robot::setScore(int score)		{ this->score = score; }
int robot::getXCoord()				{ return this->xCoord; }
void robot::setXCoord(int xCoord)	{ this->xCoord = xCoord; }
int robot::getYCoord()				{ return this->yCoord; }
void robot::setYCoord(int yCoord)	{ this->yCoord = yCoord; }