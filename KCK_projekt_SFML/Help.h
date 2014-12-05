#pragma once

#include "stdafx.h"
#include "Ship.h"
#include "Planet.h"
#include"Command.h"


class Help
{
public:
	Help();
	~Help();
	static std::wstring Help::s2ws(const std::string& s);
	static std::string Help::ws2s(const std::wstring& s);
	static int ssearch(string a, string b);
	static std::wstring textAnalysis(std::wstring text);
	static void wykonaj_komende(string komenda, string argument, Ship * s, float dt);
	static void podaj_statek(Ship * st, float * time, map<string, Planet*> & planets, Command & c);
private:
	static Ship * statek;
	static float *  dt;
	static map<string, Planet*> planety;
	static Command komenda;
};

