#include "cruiser.h"

cruiser::cruiser(std::string name, int shell, int size, int damage, std::string specialAttackName) : ship(name, shell, size, damage, specialAttackName)
{
	this->name = name;
	this->shell = shell;
	this->size = size;
	this->damage = damage;
	this->specialAttackName = specialAttackName;
}

cruiser::~cruiser()
{

}

void cruiser::attack(std::vector<ship*>& targetedFleet)
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

    targetShip->setShell(targetShip->getShell() - this->damage);

    std::cout << this->name << " hit its opponent! It can go again...\n";

    if (targetShip->getShell() <= 0) {
        std::cout << "The ship " << targetShip->getName() << " sunk!\n";

        targetedFleet.erase(targetedFleet.begin() + randomTargetShip);
        delete targetShip;

        if (targetedFleet.empty())
            return;
    }
    else {
        std::cout << "The opposing ship's shell took damage (" << targetShip->getShell() << ").\n";
    }

    this->attack(targetedFleet);
}

