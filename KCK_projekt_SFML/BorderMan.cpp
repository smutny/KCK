#include "stdafx.h"

#include "BorderMan.h"
#include "Planet.h"
#include "Human.h"

void BorderMan::action(Ship& statek, Planet& p) {
	cout << "Zaplac " << Human::GetPrice() << " albo spadaj!\n";
	int  temp;
	cin >> temp;
	if ((temp == 1) && (Human::GetPrice() < statek.getMoney())) {
		cout << "Dobra, wlatuj\nWitamy na plnecie\n";
		statek.setMoney(statek.getMoney() - Human::GetPrice());
		statek.isStuck = false;
	}
	else {
		cout << "Spadaj, nie chcê Ciê tu wiêcej widzieæ\n"; //Smuteg
		p.SetBoolFalse();
		statek.isStuck = false;
	}
}

//Mo¿e dodamy coœ w main co po up³ywie np 30-60 sekund ustawi planety na dostêpne? 0o
//Planeta matka  ustawia wszystkie na true.