#pragma once

#include "Planet.h"

class Window
{
public:
	Window();
	~Window();

	static void display();
	static void clear();
	static void draw(sf::Sprite &sprite);
	static void draw(sf::Text &text);
	static void close(sf::Event &event);

	static bool pollEvent(sf::Event &event);
	static bool isOpen();


	static void halp();
	static void ShowPlanetName(map<wstring, Planet*> p);

	
private:
	static void setFPS(unsigned fps = 60);
	static void setPosition(unsigned x = 30, unsigned y = 30);

	static sf::RenderWindow mainScreen;
	
};

