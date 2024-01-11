#pragma once

#include "ship.h"

class hunter : public ship
{
	public:
		hunter(std::string name, int shell, int size, int damage, std::string specialAttackName);
		~hunter() override;

		void attack(std::vector<ship*>& targetedFleet) override;
};

