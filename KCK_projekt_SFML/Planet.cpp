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

void Planet::setTexture(unsigned numer)
{
	planetTexture.loadFromFile("planet" + to_string(numer) + ".png");
	planetSprite.setTexture(planetTexture);
}

void Planet::setCoordinates(float x, float y)
{
	planetSprite.setPosition(x, y);
}



Planet::Planet(float x, float y, float number )
{
	interactive = true;

	setTexture(number);
	setCoordinates(x,y);
}



float Planet::getX()
{
	return planetSprite.getPosition().x;
}
float Planet::getY()
{
	return planetSprite.getPosition().y;
}