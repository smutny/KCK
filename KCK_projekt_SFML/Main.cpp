
#include "stdafx.h"

#include "Window.h"
#include "GameScreen.h"
#include "Ship.h"
#include "Planet.h"
#include "Console.h"

#include "Pirate.h"
#include "Parameter.h"


int main(int argv, char* argc[])
{
	Window::Window();
	GameScreen::GameScreen();
	Console::Console();

	sf::Clock zegar;
	

	Ship s;
	Parameter money(15, 550, 600, "arial.ttf", L"Pieni¹dze: ");

	Pirate p1;
	 vector<Planet*> p;

	 p.push_back(new Planet(140, 140, 1));
	 p.push_back(new Planet(70, 440, 2));
	 p.push_back(new Planet(290, 140, 3));
	 p.push_back(new Planet(420, 290, 4));

	

	

	while (Window::isOpen())
	{

		 auto dt = zegar.restart().asSeconds();
	

		sf::Event event;

		while (Window::pollEvent(event) && s.isStuck==false)
		{
			
		Window::close(event);

		
		Window::halp();
		Console::dupa(event);
		/*
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				if (!s.isBeyondMap())
					s.statek.move(0, -40 * dt);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				if (!s.isBeyondMap())
					s.statek.move(0, 40 * dt);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				if (!s.isBeyondMap())
					s.statek.move(-40 * dt,0);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				if (!s.isBeyondMap())
					s.statek.move(40 * dt,0 );
		*/	
		string c = "sss";
		int z = 0;
		if (s.statek.getPosition().x > 140 && c == "sss")
			
			while (z < 10)
			{
				s.statek.move(-90 *dt, 0);
				z++;
				
			}
		}

	

		

	
		p1.attack(s.statek.getPosition().x, s.statek.getPosition().y, s);
		Window::clear();
		

		Window::draw(GameScreen::getBackground());
			
		
		for (auto &planet : p)
		{
			planet->display();
		}

		Console::display();

		
		p1.attack(s.statek.getPosition().x, s.statek.getPosition().y, s);

		s.display();
		money.display(s.getMoney());
		
	
	
		Window::display();
		
		
	
	}
	return 0;
}