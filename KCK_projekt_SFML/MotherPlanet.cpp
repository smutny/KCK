#pragma once
#include "stdafx.h"
#include "Planet.h"
#include "MotherPlanet.h"
#include "Console.h"

MotherPlanet::MotherPlanet(float x, float y, float numer)
{
	SetPrice(50);
	ilosc = 700;

	interactive = false;
	visited = true;	//ważne
	setTexture(numer);
	setPosition(x, y);
	isMotherPlanet = true;

}


MotherPlanet::~MotherPlanet()
{
}

void MotherPlanet::powitanieDom() {
	Console::putTextLine(L"Domowa Obsluga Naziemna >> Witaj w domu, dobrze Cię widzieć. Chcesz odkupić trochę świeżego towaru?");
	MotherPlanet::odblokowanie();
	//Odblokowanie wszystkich planet przy wizycie
}

void MotherPlanet::kupowanie(Ship& s) {
	s.isOnPlanet = true;
	if (s.GetStuff() == 0) {
		wstring temp2;
		wstring temp = to_wstring(GetPrice());
		wstring temp3 = to_wstring(ilosc);
		temp2 = L"Domowa Obsluga Naziemna >> Możemy Ci sprzedać " + temp3 + L" towaru po " + temp + L".";

		Console::putTextLine(temp2);
		Console::putTextLine(L"Czy chcesz kupić towar?");
	}
	else {
		Console::putTextLine(L"Domowa Obsluga Naziemna >> Jeszcze nie sprzedałeś poprzedniego towaru, wróć jak się go pozbędziesz.");
	}
}

void MotherPlanet::negativeAns(Ship& s) {
	Console::putTextLine(L"Domowa Obsluga Naziemna >> Nie to nie, żegnam.");
	s.isStuck = false;
}

void MotherPlanet::positiveAns(Ship& s,int i) {
	if (s.getMoney() >= i * GetPrice() && s.GetStuff() == 0) {
		s.setMoney(s.getMoney() - i * GetPrice());
		s.SetStuff(s.GetStuff() + i);
		ilosc = ilosc - i;
		Console::putTextLine(L"Domowa Obsluga Naziemna >> Zakupiłeś towar.");
		s.isStuck = false;
	}
	else
	{
		Console::putTextLine(L"Domowa Obsługa Naziemna >> Nie stać Cię!");
		Console::putTextLine(L"Domowa Obsługa Naziemna >> Spróbuj kupić mniejszą ilość!");
	}
}

void MotherPlanet::generatorIlosci() {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();

	default_random_engine generator(seed);
	uniform_int_distribution<unsigned> distribution(1, 100);

	ilosc = distribution(generator);
	//Nic nie zmieniam w iloœciach bo chyba ok jest :d
}