#include "game.h"
#include "map.h"
#include "robot.h"
#include "computer.h"
#include "config.h"

#include <iostream>
#include <conio.h>

game::game()
{
	this->roundCounter = 0;
}

game::~game()
{

}

void game::gameloop()
{
	srand((unsigned int)time(NULL));

	map* pMap = new map();

	pMap->fillWorld();

	startScreen();

	char cont = _getch();

	switch (cont)
	{
		case ESCAPE_KEY: return;

		default: break;
	}

	robot* pRobot = chooseBot();
	computer* pComp = createComputer();

	while (true) 
	{
		system("CLS");

		this->roundCounter++;

		printUI(pMap, pRobot, pComp);

		pRobot->movement();
		pRobot->action(pMap);

		pComp->computerMovement();
		pComp->action(pMap);
	}

	delete pMap;
	delete pRobot;
	delete pComp;
}

void game::printUI(map* pMap, robot* pRobot, computer* pComp)
{
	std::cout << "Round: " << roundCounter << std::endl;
	std::cout << "Score: " << pRobot->getScore() << "\n" << std::endl;
	std::cout << "Computerscore: " << pComp->getScore() << "\n" << std::endl;


	pMap->printWorld(pRobot, pComp);

	std::cout << "\n";

	pMap->printZAxis(pRobot);
}

void game::startScreen()
{
	std::cout << TITLE1
		<< TITLE2
		<< TITLE3
		<< TITLE4
		<< TITLE5
		<< TITLE6
		<< TITLE7
		<< TITLE8;

	std::cout << SUBTITLE;
}

robot* game::chooseBot()
{
	while (true)
	{
		system("CLS");

		std::cout << CHOICE
			<< CHOICE1
			<< CHOICE2
			<< CHOICE3;

		int choice = _getch();

		switch (choice)
		{
			case SORT_DESC: return new robot(0, 0, 0, true, false, false);

			case TAKE_THREE: return new robot(0, 0, 0, false, true, false);

			case EVEN_ODD: return new robot(0, 0, 0, false, false, true);

			default: 
				std::cout << ERROR_WRONGMOVE;
				choice = _getch();
				break;
		}
	}
}

computer* game::createComputer()
{
	int type = rand() % 3;

	if(type == 0)
		return new computer(0, 4, 4, true, false, false);
	else if (type == 1)
		return new computer(0, 4, 4, false, true, false);
	else 
		return new computer(0, 4, 4, false, false, true);
}