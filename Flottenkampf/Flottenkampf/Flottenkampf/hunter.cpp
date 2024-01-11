#include "hunter.h"

hunter::hunter(std::string name, int shell, int size, int damage, std::string specialAttackName) : ship(name, shell, size, damage, specialAttackName)
{
	this->name = name;
	this->shell = shell;
	this->size = size;
	this->damage = damage;
	this->specialAttackName = specialAttackName;
}

hunter::~hunter()
{

}

void hunter::attack(std::vector<ship*>& targetedFleet)
{
	if (targetedFleet.empty())
		return;

	int randomTargetShip = rand() % targetedFleet.size();
	auto targetShip = targetedFleet[randomTargetShip];
	int diceRoll = rand() % 10 + 1;

	std::cout << "The ship " << this->name << " (" << this->shell 
		<< ") was chosen to attack the ship "
		<< targetShip->getName()
		<< " (" << targetShip->getShell()
		<< ") from the opposing fleet.\n";

	std::cout << "Diceroll: " << diceRoll << std::endl;

	if (diceRoll < targetShip->getSize()) {
		std::cout << "The attack missed!\n";

		return;
	}
	else if (diceRoll >= 9) {
		targetShip->setShell(targetShip->getShell() - (this->damage * 2));
	}
	else {
		targetShip->setShell(targetShip->getShell() - this->damage);
	}

	if (targetShip->getShell() <= 0) {
		std::cout << "The ship " << targetShip->getName() << " sunk!\n";

		targetedFleet.erase(targetedFleet.begin() + randomTargetShip);

		delete targetShip;

		return;
	}
	else {
		std::cout << "The opposing ship's shell took damage (" << targetedFleet[randomTargetShip]->getShell() << ").\n";
	}
}
