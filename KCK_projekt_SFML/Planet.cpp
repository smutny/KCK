#include "stdafx.h"
#include "Window.h"
#include "Planet.h"
#include "Console.h"
#include "BorderMan.h"
#include "Ship.h"



void Planet::display()
{
	Window::draw(planetSprite);
}

Planet::Planet()
{

}


Planet::~Planet()
{

}

void Planet::setTexture(unsigned number)
{
	planetTexture.loadFromFile("planet" + to_string(number) + ".png");
	planetSprite.setTexture(planetTexture);
}

void Planet::setPosition(float x, float y)
{
	planetSprite.setPosition(x, y);
}

Planet::Planet(float x, float y, float number)
{
	interactive = true;
	setTexture(number);
	setPosition(x,y);
}



int Planet::getX()
{
	return planetSprite.getPosition().x;
}
int Planet::getY()
{
	return planetSprite.getPosition().y;
}

void Planet::SetPrice(int price) {
	this->pprice = price;
}

int Planet::GetPrice() {
	return pprice;
}

void Planet::SetBoolFalse() {
	interactive = false;
}

void Planet::SetBoolTrue() {
	interactive = true;
}

bool Planet::CanWeShop() {
	return interactive;
}

bool Planet::onPlanet(Ship& statek) {
	if ((statek.getX() == getX()) && (statek.getY() == getY())) {
		return true;
	}
	else {
		return false;
	}
}

void Planet::welcome(Ship& statek, Planet& planeta, BorderMan& b) {
	if ((b.chance <= 50) && /*(statek.isStuck == true)*/(onPlanet(statek) == true)) {
		b.action(statek,planeta);
	}
	if ((interactive == true) && /*(statek.isStuck == true)*/(onPlanet(statek) == true)) {
		Console::putTextLine(L"Obs³uga Naziemna >> Witamy, masz do nas jak¹œ sprawê?");
	}
}

void Planet::shopingTime(Ship& statek) {
	wstring temp, temp2;
	temp2 = to_wstring(GetPrice());
	temp = L"Obs³uga Naziemna >> Mozemy odkupic od Ciebie towar za " + temp2 + L".\nChcia³byœ sprzedac?";
	Console::putTextLine(temp);
	/*int i;
	cin >> i;
	if (i <= statek.GetStuff()) {
		cout << "Bierzemy\n";
		statek.SetStuff(statek.GetStuff() - i);
		statek.setMoney(GetPrice()*i);
	}
	else {
		cout << "Nie masz tyle\n";
	}*/
}

void Planet::negativeAns() {
	Console::putTextLine(L"Obs³uga Naziemna >> Nie to nie, mo¿e nastêpnym razem\n");
}

void Planet::positiveAns(int i, Ship& statek) {
	if (i <= statek.GetStuff()) {
		Console::putTextLine(L"Obs³uga Naziemna >> Bierzemy\n");
		statek.SetStuff(statek.GetStuff() - i);
		statek.setMoney(GetPrice()*i);
	}
	else {
		Console::putTextLine(L"Obs³uga Naziemna >> Nie masz tyle\n");
	}
}