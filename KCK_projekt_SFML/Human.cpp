#include "stdafx.h"
#include "Human.h"


Human::Human()
{
}


Human::~Human()
{
}

void Human::SetPrice(int price) {
	this->price = price;
}

int Human::GetPrice() {
	return price;
}

void Human::SetBoolFalse() {
	bought = false;
}

void Human::SetBoolTrue() {
	bought = true;
}

bool Human::GetBool() {
	return bought;
}

void Human::action() {}