#pragma once
#include "stdafx.h"
#include "Planet.h"
#include "MotherPlanet.h"
#include "Console.h"

MotherPlanet::MotherPlanet()
{
	SetPrice(50);
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
	if (s.GetStuff > 0) {
		wstring temp2;
		wstring temp = to_wstring(GetPrice());
		wstring temp3 = to_wstring(ilosc);
		temp2 = L"Domowa Obsluga Naziemna >> Mo¿emy Ci sprzedaæ " + temp3 + L"towaru po " + temp + L".";

		Console::putTextLine(temp2);
		Console::putTextLine(L"Jestes chêtny?");
	}
	else {
		Console::putTextLine(L"Domowa Obsluga Naziemna >> Jeszcze nie sprzeda³eœ poprzedniego towaru, wróæ jak siê go pozbêdziesz.");
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