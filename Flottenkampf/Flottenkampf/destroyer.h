#pragma once

#include "ship.h"

class destroyer : public ship
{
public:
	destroyer(std::string name, int shell, int size, int damage, std::string specialAttackName);
	~destroyer() override;

	void attack(std::vector<ship*>& targetedFleet) override;
};

