#pragma once

#include "Human.h"

class Pirate : public Human
{
public:
	Pirate();
	~Pirate();
	void attack(int x, int y, Ship &s);

	void action(Ship& statek);
private:

	static unsigned int chance;
};

