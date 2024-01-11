#pragma once

#include <iostream>
#include <vector>

#include "ship.h"
#include "cruiser.h"
#include "hunter.h"
#include "destroyer.h"
#include "defines.h"

class game
{
	public:
		game();
		~game();

		void gameloop();
		std::vector<ship*> createFleet();
		void fight();
		void printUI();

	private:
		bool isGameRunning;
		int roundCounter;
		std::vector<ship*> playerFleet;
		std::vector<ship*> opponentFleet;
};

