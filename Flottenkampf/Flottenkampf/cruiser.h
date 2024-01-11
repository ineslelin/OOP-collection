#pragma once

#include "ship.h"

class cruiser : public ship
{
	public:
		cruiser(std::string name, int shell, int size, int damage, std::string specialAttackName);
		~cruiser() override;

		void attack(std::vector<ship*>& targetedFleet) override;
};

