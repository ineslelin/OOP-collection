#include "map.h"
#include "config.h"
#include "robot.h"
#include "computer.h"

#include <vector>
#include <iostream>
#include <algorithm>

map::map()
{
	this->worldMap = std::vector <std::vector <std::vector <int>>>(Z_AXIS, std::vector <std::vector <int>>(Y_AXIS, std::vector <int> (X_AXIS)));
}

map::~map()
{

}

void map::fillWorld()
{
	for (int z = 0; z < Z_AXIS; z++) {
		for (int y = 0; y < Y_AXIS; y++) {
			for (int x = 0; x < X_AXIS; x++) {
				int randomNumber = rand() % 10;

				worldMap[z][y][x] = randomNumber;
			}
		}

		std::cout << "\n";
	}
}

void map::printWorld(robot* pRobot, computer* pComp)
{
	for (int y = 0; y < Y_AXIS; y++) {
		for (int x = 0; x < X_AXIS; x++) {

			if (x == pRobot->getXCoord() && y == pRobot->getYCoord())
				std::cout << "x ";
			else if (x == pComp->getXCoord() && y == pComp->getYCoord())
				std::cout << "C ";
			else
				std::cout << worldMap[0][y][x] << " ";
		}

		std::cout << "\n";
	}
}

void map::printZAxis(robot* pRobot)
{
	int x = pRobot->getXCoord();
	int y = pRobot->getYCoord();

	std::cout << "ROBOT:	";
	for (int z = 0; z < Z_AXIS; z++) {
		std::cout << worldMap[z][y][x] << " ";
	}
	std::cout << "\n\n";

	std::cout << "UP:	";
	if (y > 0)
	{
		for (int z = 0; z < Z_AXIS; z++) {
			std::cout << worldMap[z][y - 1][x] << " ";
		}
	}
	std::cout << "\n";

	std::cout << "LEFT:	";
	if (x > 0)
	{
		for (int z = 0; z < Z_AXIS; z++) {
			std::cout << worldMap[z][y][x - 1] << " ";
		}
	}
	std::cout << "\n";

	std::cout << "DOWN:	";
	if (y < Y_AXIS - 1)
	{
		for (int z = 0; z < Z_AXIS; z++) {
			std::cout << worldMap[z][y + 1][x] << " ";
		}
	}
	std::cout << "\n";

	std::cout << "RIGHT:	";
	if (x < X_AXIS - 1)
	{
		for (int z = 0; z < Z_AXIS; z++) {
			std::cout << worldMap[z][y][x + 1] << " ";
		}
	}
	std::cout << "\n";
}

void map::shuffleWorld()
{
	int shuffleMethod = rand() % 3;
	std::vector<int> zAxis(Z_AXIS);

	switch (shuffleMethod)
	{
		case 0: 
			for (int y = 0; y < Y_AXIS; y++) {
				for (int x = 0; x < X_AXIS; x++)
				{
					for (int z = 0; z < Z_AXIS; z++) {
						zAxis[z] = worldMap[z][y][x];
					}

					std::random_shuffle(zAxis.begin(), zAxis.end());

					for (int z = 0; z < Z_AXIS; z++) {
						worldMap[z][y][x] = zAxis[z];
					}
				}
			}
			break;

		case 1:
			for (int y = 0; y < Y_AXIS; y++) {
				for (int x = 0; x < X_AXIS; x++)
				{
					for (int z = 0; z < Z_AXIS; z++) {
						zAxis[z] = worldMap[z][y][x];
					}

					sort(zAxis.begin(), zAxis.end(), std::greater<int>());

					for (int z = 0; z < Z_AXIS; z++) {
						worldMap[z][y][x] = zAxis[z];
					}
				}
			}
			break;

		case 2:
			for (int y = 0; y < Y_AXIS; y++) {
				for (int x = 0; x < X_AXIS; x++)
				{
					for (int z = 0; z < Z_AXIS; z++) {
						zAxis[z] = worldMap[z][y][x];
					}

					sort(zAxis.begin(), zAxis.end());

					for (int z = 0; z < Z_AXIS; z++) {
						worldMap[z][y][x] = zAxis[z];
					}
				}
			}
			break;
	}
}