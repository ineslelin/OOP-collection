#pragma once

#include "map.h"
#include "robot.h"
#include "computer.h"

class game
{
	public:
		game();
		virtual ~game();

		void gameloop();
		void printUI(map* pMap, robot* pRobot, computer* pComp);
		void startScreen();
		robot* chooseBot();
		computer* createComputer();

	private:
		int roundCounter;
};

