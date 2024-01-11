#pragma once

class robot;
class computer;

#include <vector>
#include <iostream>

class map
{
	public:
		map();
		~map();

		void fillWorld();
		void printWorld(robot* pRobot, computer* pComp);
		void printZAxis(robot* pRobot);
		void shuffleWorld();

		std::vector <std::vector <std::vector <int>>> worldMap;
};

