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
	bool visited = false;
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
		Console::putTextLine(L"Obsługa Naziemna >> Witamy, chcesz nam coś sprzedać?");
	}
	if (planeta.visited)
	{
		Console::putTextLine(L"Obsługa Naziemna >> U nas już byłeś, leć dalej.");
	}
}

void Planet::shopingTime(Ship& statek) {
	if (interactive == true) {
		wstring temp, temp2;
		temp2 = L"700";// to_wstring(GetPrice());
		temp = L"Obsługa Naziemna >> Mozemy odkupic od Ciebie towar za " + temp2 + L".Chciałbyś sprzedać?";
		Console::putTextLine(temp);
	}
	else {
		Console::putTextLine(L"Obsługa Naziemna >> Przykro nam, nie jesteśmy zainteresowani.");
	}
}

void Planet::negativeAns() {
	Console::putTextLine(L"Obsługa Naziemna >> Nie to nie, może następnym razem\n");
	visited = true;
}

void Planet::positiveAns(int i, Ship& statek) {
	if (i <= statek.GetStuff() && interactive == true) {
		Console::putTextLine(L"Obsługa Naziemna >> Bierzemy\n");
		statek.SetStuff(statek.GetStuff() - i);
		statek.setMoney(GetPrice()*i);
		visited = true;
	}
	else {
		Console::putTextLine(L"Obsługa Naziemna >> Nie masz tyle\n");
	}
}

void Planet::byeBye(Ship& s) {
	Console::putTextLine(L"Obsluga Naziemna >> Żegnamy, mamy nadzieję że pobyt się udał i zapraszamy  ponownie.");
	Planet::visited = true;
	Planet::interactive = false;
	s.isStuck = true;

}