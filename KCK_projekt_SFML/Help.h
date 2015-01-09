#pragma once

#include "stdafx.h"
#include "Ship.h"
#include "Planet.h"


class Help
{
public:
	Help();
	~Help();
	
	static int ssearch(wstring a, wstring b);
	static std::wstring textAnalysis(std::wstring text);
	//static void wykonaj_komende();
	static void podaj_statek(Ship * st, float * time, map<wstring, Planet*> planets);
	static bool flaga;

	static Ship * statek;
	static float *  dt;
	static map<wstring, Planet*> planety;
	static wstring komenda;
	static wstring argument;

private:
	static std::vector<std::wstring> tokenize(const std::wstring& source);
	
};

