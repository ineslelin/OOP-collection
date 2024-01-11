#include "game.h"

game::game()
{
	this->isGameRunning = true;
	this->roundCounter = 1;
}

game::~game()
{

}

void game::gameloop()
{
	while (isGameRunning)
	{
		printUI();

		playerFleet = createFleet();

		#ifdef DEBUG
			for (auto ship : playerFleet) {
				std::cout << "Name: " << ship->getName() << "\n";
			}
		#endif

		opponentFleet = createFleet();

		#ifdef DEBUG
			for (auto ship : opponentFleet) {
				std::cout << "Name: " << ship->getName() << "\n";
			}
		#endif

		fight();

		if (playerFleet.empty())
			std::cout << "You lost!\n";
		else
			std::cout << "You won!\n";

		isGameRunning = false;
	}
}

void game::printUI()
{
	std::cout << BOX_1 << BOX_2
		<< SHIP_CHOICE_1 << SHIP_CHOICE_2
		<< SHIP_CHOICE_3 << SHIP_CHOICE_4 << BOX_2
		<< SHIP_CHOICE_5 << SHIP_CHOICE_6
		<< SHIP_CHOICE_7 << SHIP_CHOICE_8
		<< SHIP_CHOICE_9
		<< BOX_2 << BOX_1 << "\n";
}

std::vector<ship*> game::createFleet()
{
	int size;
	std::vector<ship*> currFleet;

	std::cout << CHOOSE_FLEET;
	std::cin >> size;

	for (int i = 0; i < size; i++) {
		int choice;

		std::cout << SHIP_TYPES;
		std::cin >> choice;

		switch (choice) {
			case 1: currFleet.push_back(new hunter("Hunter", HUNTER_SHELL, HUNTER_SIZE, HUNTER_DAMAGE, "Critical Hits"));
				break;
			case 2: currFleet.push_back(new destroyer("Destroyer", DESTROYER_SHELL, DESTROYER_SIZE, DESTROYER_DAMAGE, "Target-seeking"));
				break;
			case 3: currFleet.push_back(new cruiser("Cruiser", CRUISER_SHELL, CRUISER_SIZE, CRUISER_DAMAGE, "Bombardement"));
				break;
			default: std::cout << ERR_MSG;
				std::cin >> choice;
		}
	}
	
	return currFleet;
}

void game::fight()
{
	system("CLS");

	while (true)
	{
		std::cout << "\n\n---------------ROUND " << roundCounter << "---------------\n";

		int randomPlayerShip = rand() % playerFleet.size();
		playerFleet[randomPlayerShip]->attack(opponentFleet);

		if (playerFleet.empty() || opponentFleet.empty())
			break;

		int randomOpponentShip = rand() % opponentFleet.size();
		opponentFleet[randomOpponentShip]->attack(playerFleet);

		if (playerFleet.empty() || opponentFleet.empty())
			break;

		roundCounter++;
	}
}