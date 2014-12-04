#include "stdafx.h"
#include "Human.h"
#include "Ship.h"
#include "Pirate.h"



unsigned int Pirate::chance;



void Pirate::attack(int x, int y, Ship &s)
{

	if (((x % 70 == 0 || y % 70 == 0) && chance <= 30) && s.isStuck == false)
	{
		s.isStuck = true;
		cout << "YAARrrr! " << s.isStuck << endl;
	}

}

Pirate::Pirate()
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	default_random_engine generator(seed);
	uniform_int_distribution<unsigned> distribution(1, 100);

	chance = distribution(generator);
}


Pirate::~Pirate()
{
}
