#pragma once

#include "Human.h"
#include "Ship.h"

using namespace std;

class BorderMan : public Human {
public:
	void action(Ship& statek, Planet& p);
};