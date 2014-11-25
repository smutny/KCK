
#include "stdafx.h"

#include "Window.h"
#include "GameScreen.h"
#include "Ship.h"
#include "Planet.h"
#include "Console.h"
#include "Parameter.h"
#include "Pirate.h"



int main(int argv, char* argc[])
{
	int hajsLeci = 232;

	Window::Window();
	GameScreen::GameScreen();
	Console::Console();

	sf::Clock clock;
	
	Parameter money(15, 550, 600, "arial.ttf", L"Pieni¹dze: ");

	Ship s; Pirate p1;
	
	 map<string, Planet*> planets;
	 planets["Merkury"] = new Planet(140, 140, 1);
	 planets["Uran"] = new Planet(550, 550, 2); //70,440,2
	 planets["Joiwsz"] = new Planet(290, 140, 3);
	 planets["Neptun"] = new Planet(420, 290, 4);

	while (Window::isOpen())
	{
		
		auto dt = clock.restart().asSeconds();
		
		sf::Event event;
		while (Window::pollEvent(event))
		{
			Window::close(event);
			Window::halp();
			Console::doYourJob(event);
		}

	Window::clear();
	GameScreen::display();
	Console::display();

		p1.attack(s.getX(), s.getY(), s);
		money.display(s.getMoney());

		for (auto planet : planets)
		{
			planet.second->display();
		}


		string name = "Merkury";
		//s.fly(dt, L"lewo");
		s.flyTo(dt, *planets[name]);
		s.setMoney(++hajsLeci);
		s.display();

		
	
	Window::display();	

	}
	return 0;
}