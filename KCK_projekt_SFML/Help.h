#pragma once

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

