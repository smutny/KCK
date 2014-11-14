#include "stdafx.h"
#include "Window.h"

sf::RenderWindow Window::mainScreen(sf::VideoMode(1024, 640), "KCK!");

Window::Window()
{
	setPosition();
	setFPS();
}

Window::~Window()
{
}


void Window::setPosition(unsigned x, unsigned y)
{
	mainScreen.setPosition(sf::Vector2i(30, 30));
}

void Window::setFPS(unsigned fps)
{
	mainScreen.setFramerateLimit(fps);
}



bool Window::isOpen()
{
	if (mainScreen.isOpen())
		return true;
}

bool Window::pollEvent(sf::Event &event)
{
	if (mainScreen.pollEvent(event))
		return true;
}


void Window::display()
{
	mainScreen.display();
}

void Window::close(sf::Event &event)
{
if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	mainScreen.close();
}

void Window::clear()
{
	mainScreen.clear();
}

void Window::draw(sf::Sprite &sprite)
{
	mainScreen.draw(sprite);
}

 void Window::draw(sf::Text &text)
{
	mainScreen.draw(text);
}


void Window::halp()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		cout << sf::Mouse::getPosition(mainScreen).x << " " << sf::Mouse::getPosition(mainScreen).y << "\n";
	}
}