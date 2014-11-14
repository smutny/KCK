#include "stdafx.h"
#include "Human.h"
#include "Ship.h"

#include "Pirate.h"

void Pirate::attack(int x, int y, Ship& s) //REFERENCJA BITCHES
{
	auto seed1 = std::chrono::system_clock::now().time_since_epoch().count();

	default_random_engine generator(seed1);
	uniform_int_distribution<unsigned> distribution(1, 100);

	auto chance = distribution(generator);

	if ((x % 70 == 0  || y % 70 == 0) && chance <=50)
	{
		s.isStuck = true;
		cout << "NAPIERDALAC! " << s.isStuck << endl;
	}

}

Pirate::Pirate()
{
}


Pirate::~Pirate()
{
}
