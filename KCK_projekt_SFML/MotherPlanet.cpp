#pragma once
#include "stdafx.h"
#include "Planet.h"
#include "MotherPlanet.h"
#include "Console.h"

MotherPlanet::MotherPlanet(float x, float y, float numer)
{
	SetPrice(50);

	interactive = false;
	visited = true;	//ważne
	setTexture(numer);
	setPosition(x, y);

}


MotherPlanet::~MotherPlanet()
{
}

void MotherPlanet::powitanieDom() {
	Console::putTextLine(L"Domowa Obsluga Naziemna >> Witaj w domu. Chcesz odkupiæ trochê œwie¿ego towaru? A mo¿e tylko nas odwiedzasz?");
	MotherPlanet::odblokowanie();
	//Odblokowanie wszystkich planet przy wizycie
}

void MotherPlanet::kupowanie(Ship& s) {
	if (s.GetStuff() > 0) {
		wstring temp2;
		wstring temp = to_wstring(GetPrice());
		wstring temp3 = to_wstring(ilosc);
		temp2 = L"Domowa Obsluga Naziemna >> Możemy Ci sprzedaæ " + temp3 + L"towaru po " + temp + L".";

		Console::putTextLine(temp2);
		Console::putTextLine(L"Jestes chętny?");
	}
	else {
		Console::putTextLine(L"Domowa Obsluga Naziemna >> Jeszcze nie sprzedałeś poprzedniego towaru, wróć jak się go pozbędziesz.");
	}
}

void MotherPlanet::negativeAns(Ship& s) {
	Console::putTextLine(L"Domowa Obsluga Naziemna >> Nie to nie, ¿egnam.");
	s.isStuck = false;
}

void MotherPlanet::positiveAns(Ship& s,int i) {
	if (s.getMoney() >= i * GetPrice() && s.GetStuff() == 0) {
		s.setMoney(s.getMoney() - i * GetPrice());
		Console::putTextLine(L"Domowa Obsluga Naziemna >> Zakupi³eœ towar.");
		s.isStuck = false;
	}
}

void MotherPlanet::generatorIlosci() {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	default_random_engine generator(seed);
	uniform_int_distribution<unsigned> distribution(1, 100);

	ilosc = distribution(generator);
	//Nic nie zmieniam w iloœciach bo chyba ok jest :d
}