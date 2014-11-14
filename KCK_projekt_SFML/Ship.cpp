#include "stdafx.h"
#include "Window.h"
#include "Planet.h"
#include "Ship.h"


Ship::Ship()
{
	setTexture();
	setPosition();

	money = 10000;
	isStuck = false;
}


Ship::~Ship()
{
}

void Ship::setTexture()
{
	statekTekstura.loadFromFile("spaceShip.png");
	statek.setTexture(statekTekstura);
}

void Ship::setPosition(float x, float y)
{
	statek.setPosition(x,y);
}


void Ship::calaNaprzod(string rozkaz)
{
	if (rozkaz == "naprzod")
		statek.move(0, -50);
}

//do zmiany
bool Ship::isBeyondMap()
{
	if (statek.getPosition().x < 600 && statek.getPosition().x > 10 &&
		statek.getPosition().y < 600 && statek.getPosition().y > 10)
	return false;
}

void Ship::focus(Planet p)
	{
		if (statek.getPosition().x > p.getX() &&
			statek.getPosition().x < p.getX() + 70 &&
			statek.getPosition().y > p.getY() &&
			statek.getPosition().y < p.getY() + 70
			)

			isStuck = true;
	}


void Ship::display()
{
	Window::draw(statek);
}