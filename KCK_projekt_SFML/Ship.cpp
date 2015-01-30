#include "stdafx.h"
#include "Window.h"
#include "Planet.h"
#include "Ship.h"
#include "Pirate.h"

Ship::Ship()
{
	setTexture();
	setPosition();

	SetStuff(1000);
	money = 1000;
	isStuck = false;
	isOnPlanet = false;
}


Ship::~Ship()
{
}



void Ship::setTexture2()
{
	if (GetStuff() >= 500)
	{
		statekTekstura.loadFromFile("spaceShipFull.png");
		statek.setTexture(statekTekstura);
	}
	else if (GetStuff() <= 500 && GetStuff() >= 100)
	{
		statekTekstura.loadFromFile("spaceShipHalf.png");
		statek.setTexture(statekTekstura);
	}

}


void Ship::stop()
{
	movementCounter = 0;
}

void Ship::fly(float& dt, wstring rozkaz, int counterLimit)
{
	if (movementCounter == counterLimit)
	{
		movementCounter = 0;
		isStuckv2 = true;
	}
	else{
		movementCounter++;

		vx = vy = 0;
		if (rozkaz == L"lewo" && isStuck == false && isStuckv2 == false)
			vx += -10;

		if (rozkaz == L"prawo" && isStuck == false && isStuckv2 == false)
			vx += 165;

		if (rozkaz == L"góra" && isStuck == false && isStuckv2 == false)
			vy += -10;

		if (rozkaz == L"dół" && isStuck == false && isStuckv2 == false)
			vy += 165;

		if (movementCounter <= counterLimit)
		{
			comeBack();

			x += vx * dt;
			y += vy * dt;
		}

	}

}

void Ship::flyTo(float& dt, Planet& p)
{

		if (getX() < p.getX())
		{
			fly(dt, L"prawo", 7000);
		}
		else if (getX() > p.getX())
		{
			fly(dt, L"lewo", 7000);
		}
		else if (getY() > p.getY())
		{
			fly(dt, L"góra", 7000);
		}
		else if (getY() < p.getY())
		{
			fly(dt, L"dół", 7000);
		}
	
}


void Ship::comeBack()
{
	if (getX() > 460)
		x = 460;
	if (getX() < 30)
		x = 30;
	if (getY() < 30)
		y = 30;
	if (getY() > 460)
		y = 460;
}

void Ship::display()
{
	statek.setPosition(x, y);
	Window::draw(statek);
}


void Ship::focus(Planet& p)
{
	if (getX() >= p.getX() &&
		getX() <= p.getX() + 70 &&
		getY() >= p.getY() &&
		getY() <= p.getY() + 70
		)

		isStuck = true;
}


void Ship::setTexture()
{
	statekTekstura.loadFromFile("spaceShip.png");
	statek.setTexture(statekTekstura);
}

void Ship::setPosition(float x, float y)
{
	statek.setPosition(x,y);
	this->x = x; this->y = y;
}

void Ship::SetStuff(int stuff) {
	this->stuff = stuff;
}

int Ship::GetStuff() {
	return stuff;
}