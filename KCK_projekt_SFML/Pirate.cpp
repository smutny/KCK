#include "stdafx.h"
#include "Human.h"
#include "Ship.h"
#include "Pirate.h"



unsigned int Pirate::chance;


void Pirate::attack(int x, int y, Ship &s)
{

	if (((x % 70 == 0 || y % 70 == 0) && chance <=100) && s.isStuck == false)
	{
		s.isStuck = true;
		cout << "YAARrrr! " << s.isStuck << endl;
		Pirate::action(s);
	}

}

Pirate::Pirate()
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	default_random_engine generator(seed);
	uniform_int_distribution<unsigned> distribution(1, 100);

	chance = distribution(generator);

	SetPrice(220);
}


Pirate::~Pirate()
{
}

void Pirate::action(Ship& statek){
	cout << "Zaplac " << Pirate::GetPrice() << " albo spadaj!\n";
	int  temp = 1;
	cin >> temp;
	if ((temp == 1) && (Pirate::GetPrice() < statek.getMoney())) {
		cout << "Dobra, lec\n";
		statek.setMoney(statek.getMoney() - Pirate::GetPrice());
		statek.isStuck = false;
	}
	else {
		cout << "Nie pokazuj sie tu wiecej,  frajerze!\n";
		statek.SetStuff(0);
		statek.isStuck = false;
	}
}
/**/
void Pirate::negativeAnswer(Ship& statek) {
	cout << "Nie pokazuj sie tu wiecej,  frajerze!\n";
	statek.SetStuff(0);
	statek.isStuck = false;
}

void Pirate::positiveAnswer(Ship& statek) {
	if (Pirate::GetPrice() < statek.getMoney()) {
		cout << "Dobra, lec\n";
		statek.setMoney(statek.getMoney() - Pirate::GetPrice());
		statek.isStuck = false;
	}
	else {
		negativeAnswer(statek);
	}
}
