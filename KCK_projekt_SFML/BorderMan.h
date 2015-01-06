#pragma once

#include "Human.h"
#include "Ship.h"

using namespace std;

class BorderMan : public Human {
public:
	BorderMan();
	~BorderMan();

	void action(Ship& statek);

	void negativeAns(Planet& p);
	void positiveAns(Planet& p, Ship& s);
//private:
	static unsigned int chance;
};