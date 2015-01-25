#pragma once

#include "stdafx.h"

#include "Window.h"
#include "GameScreen.h"
#include "Ship.h"
#include "Planet.h"
#include "Console.h"
#include "Parameter.h"
#include "Pirate.h"
#include "Help.h"
#include "BorderMan.h"

void wykonaj_komende();
Ship s; Pirate p1; BorderMan b;
map<wstring, Planet*> planets;
float dt;


int main(int argv, char* argc[])
{
	
	Window::Window();
	GameScreen::GameScreen();
	Console::Console();

	sf::Clock clock;
	
	Parameter money(15, 550, 600, "arial.ttf", L"Pieniądze: ");


	 planets[L"Merkury"] = new Planet(140, 140, 1);
	 planets[L"Uran"] = new Planet(70, 440, 2); //70,440,2 //550,550,2
	 planets[L"Jowisz"] = new Planet(290, 140, 3);
	 planets[L"Neptun"] = new Planet(420, 290, 4);
	 bool shipOnPlanet = false;
	 pair<wstring, Planet*> currentPlanet = make_pair(L"Merkury", planets[L"Merkury"]);


	 dt = clock.restart().asSeconds();
	while (Window::isOpen())
	{
		
		//auto dt = clock.restart().asSeconds();
		Help::podaj_statek(&s, &dt, planets);

		//if (Help::flaga)
		//{
			wykonaj_komende();
	//	}
		if (!shipOnPlanet)
		{
			for (auto planet : planets)
			{
				if (planet.second->onPlanet(s))
				{
					planet.second->welcome(s, *planet.second, b);
					currentPlanet = planet;
					shipOnPlanet = true;
				}
			}
		}
		if (currentPlanet.second->onPlanet(s) == false)
		{
			shipOnPlanet = false;
		}
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

		for (const auto& planet : planets)
		{
			planet.second->display();
		}


		string name = "Merkury";
		//s.fly(dt, L"lewo");
		//s.flyTo(dt, *planets[name]);
		
		s.display();

		Window::display();	

	}
	return 0;
}


void wykonaj_komende()
{
	if (Help::komenda == L"lec")
	{
		
		if (Help::argument == L"lewo" || Help::argument == L"prawo" || Help::argument == L"góra" || Help::argument == L"dół")
		{	
			
			s.fly(dt, Help::argument);

		}
		else
		{
			s.flyTo(dt, *planets[Help::argument]);
		}
	}
	if (Help::komenda == L"plac")
	{
		if (Pirate::busy)
		{
			cout << "pirat";
			p1.positiveAnswer(s);
		}
		if (BorderMan::busy)
		{
			for (const auto& a : planets)
			{
				if (a.second->onPlanet(s))
				{
					cout << "granicznik";
					b.positiveAns(*a.second,s);
				}
			}
		}
	}


	Help::flaga = false;
}