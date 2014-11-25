#include "stdafx.h"
#include "Window.h"
#include "Planet.h"



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