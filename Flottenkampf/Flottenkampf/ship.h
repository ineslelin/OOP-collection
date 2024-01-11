#pragma once

#include <iostream>
#include <vector>

#include "defines.h"

class ship
{
	public:
		ship(std::string name, int shell, int size, int damage, std::string specialAttackName);
		virtual ~ship();

		virtual void attack(std::vector<ship*>& targetedFleet) = 0;

		std::string getName();

		int getShell();
		void setShell(int shell);

		int getSize();

	protected:
		std::string name;
		int shell;
		int size;
		int damage;
		std::string specialAttackName;
};

