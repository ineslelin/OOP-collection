#include "ship.h"

ship::ship(std::string name, int shell, int size, int damage, std::string specialAttackName)
{
	this->name = name;
	this->shell = shell;
	this->size = size;
	this->damage = damage;
	this->specialAttackName = specialAttackName;

#ifdef DEBUG
	std::cout << "Ship created\n";
#endif 
}

ship::~ship()
{
#ifdef DEBUG
	std::cout << "Ship deleted\n";
#endif 
}

std::string ship::getName() { return this->name; }

int ship::getShell() { return this->shell; }
void ship::setShell(int shell) { this->shell = shell; }

int ship::getSize() { return this->size; }