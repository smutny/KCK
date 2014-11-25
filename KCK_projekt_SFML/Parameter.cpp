#include "stdafx.h"
#include "Window.h"
#include "Parameter.h"


Parameter::Parameter(int fs, int px, int py, char* fl, std::wstring l)
{
	fontSize = fs;
	positionX = px;
	positionY = py;
	fontLocalisation = fl;
	label = l;
}

Parameter::~Parameter()
{
}


void Parameter::setFont(const char* fontLocalisation)
{
	font.loadFromFile(fontLocalisation);
}

void Parameter::display(unsigned x)
{
	setFont(fontLocalisation);

	text.setFont(font);
	text.setString(label + std::to_wstring(x));
	text.setCharacterSize(fontSize);
	text.setColor(sf::Color::Yellow);
	text.setPosition(positionX, positionY);

	Window::draw(text);
}


