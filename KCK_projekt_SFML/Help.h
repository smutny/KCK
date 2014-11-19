#pragma once

#include <string>
#include <sstream>
#include <iterator>
#include<locale>
#include<Windows.h>
#include<stringapiset.h>
#include<vector>

using namespace std;

class Help
{
public:
	Help();
	~Help();
	static std::wstring Help::s2ws(const std::string& s);
	static std::string Help::ws2s(const std::wstring& s);
	static int ssearch(string a, string b);
	static std::wstring textAnalysis(std::wstring text);
};

