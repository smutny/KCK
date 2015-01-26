#pragma once
class MotherPlanet : public Planet
{
public:
	MotherPlanet();
	~MotherPlanet();

	int ilosc;
	
	void powitanieDom();

	void kupowanie();

	void odblokowanie();
};

/*
int cena; <- Planet

*/