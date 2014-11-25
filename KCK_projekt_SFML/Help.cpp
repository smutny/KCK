#include "stdafx.h"
#include "Help.h"

Help::Help()
{
}


Help::~Help()
{
}


std::wstring Help::s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string Help::ws2s(const std::wstring& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
	char* buf = new char[len];
	WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, buf, len, 0, 0);
	std::string r(buf);
	delete[] buf;
	return r;
}

int Help::ssearch(string a, string b) //(gdzie, szukany)
{
	unsigned int present;
	for (auto i = 0; i < a.length(); i++)
	{
		for (auto j = i; j < a.length(); j++)
		{
			present = 0;
			for (auto k = 0; k < b.length() && (j + k)<a.length(); k++)
			{
				if (a[j + k] == b[k])
				{
					present++;
				}
				if (present == b.length())
				{
					return j;
				}
			}
		}
	}
	return 1000;
}

std::wstring Help::textAnalysis(std::wstring text)
{
	//slownik

	vector<string> bezargumentowe = { "wita", "czesc", "siem", "hej", "doberek" };
	vector<string> przeklenstwa = { "kurw", "jeb", "pierd", "chuj" };
	vector<string> operatory = { "lec", "kup" };
	vector<string> latanie = { "prawo", "lewo", "gora", "dol" };
	vector<string> przekupowanie = { "celn", "gran", "pira" };
	vector<vector<string>*> wskazniki = { &latanie, &przekupowanie };

	//tokenizacja

	string sentence = ws2s(text);
	istringstream iss(sentence);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(tokens));

	//analiza

	//ugrzeczniacz
	int j = 0;
	int k = 0;
	while (j < tokens.size())
	{
		k = 0;
		while (k <przeklenstwa.size() && ssearch(tokens.at(j), przeklenstwa.at(k)) == 1000)
		{
			k++;
		}
		if (k == przeklenstwa.size()) //nie bylo operatora, nastepne slowo
		{
			j++;
		}
		else
		{
			return L"Nie! Grzeczniej prosze!";
		}
	}


	//wyszukiwanie bezargumentowych
	j = 0;
	k = 0;
	while (j < tokens.size())
	{
		k = 0;
		while (k < bezargumentowe.size() && ssearch(tokens.at(j), bezargumentowe.at(k)) == 1000)
		{
			k++;
		}
		if (k == bezargumentowe.size()) //nie bylo operatora, nastepne slowo
		{
			j++;
		}
		else
		{
			return s2ws(tokens.at(j)) + L" Kapitanie!";
		}
	}
	j = 0;
	k = 0;
	//wyszukiwanie operatorow
	while (j < tokens.size())
	{
		k = 0;
		while (k<operatory.size() && ssearch(tokens.at(j), operatory.at(k)) == 1000)
		{
			k++;
		}
		if (k == operatory.size()) //nie bylo operatora, nastepne slowo
		{
			j++;
		}
		else //byl operator, szukamy argumentu
		{
			for (auto i = j; i < tokens.size(); i++)//slowa po operatorze
			{
				for (auto l = 0; l < (*wskazniki.at(k)).size(); l++)
				{
					if (ssearch(tokens.at(i), (*wskazniki.at(k)).at(l)) != 1000)
					{
						//wywolanie funkcji operator z argumentem 
						return L"Wykonuje komende \"" + s2ws(tokens.at(j)) + L" " + s2ws(tokens.at(i)) + L"\"";
					}
				}

			}
			return L"Komenda \"" + s2ws(tokens.at(j)) + L"\" wymaga argumentu!";
			j++;
		}
	}
	return L"Komenda nieznana";

	/*
	if ((ssearch(text, L"czesc") != 1000) || (ssearch(text,L"witaj")!=1000))
	{
	return L"Witaj Kapitanie!";
	}
	if (ssearch(text, L"lec")!=1000)
	{
	int pozycja = ssearch(text, L"do");
	if (pozycja!=1000)
	{
	wstring output=L"Lece ";
	for (int i = pozycja; i < text.length(); i++)
	{
	output += text[i];
	}
	return output;
	}
	pozycja = ssearch(text, L"w");
	if (pozycja != 1000)
	{
	wstring output = L"Lece ";
	for (int i = pozycja; i < text.length(); i++)
	{
	output += text[i];
	}
	//wywolanie funkcji lec z argumentem prawo, lewo, prosto, tyl
	return output;
	}
	return L"Nie wiem dokad";
	}
	if (ssearch(text, L"kup") != 1000)
	{
	int pozycja = ssearch(text, L"kup");
	if (pozycja != 1000)
	{
	if (text.length()>(pozycja + 3))
	{
	wstring output = L"Przekupuje";
	for (int i = pozycja + 3; i < text.length(); i++)
	{
	output += text[i];
	}
	//wywolanie funkcji przekup
	return output;
	}
	}
	return L"Nie wiem kogo przekupic";
	}
	if (ssearch(text, L"sprzeda")!=1000)
	{
	int pozycja = ssearch(text, L"sprzedaj");
	if (pozycja != 1000 )
	{
	if (text.length()>(pozycja+8))
	{
	wstring output = L"Sprzedalem";
	for (int i = pozycja + 8; i < text.length(); i++)
	{
	output += text[i];
	}
	//wywolanie funkcji sprzedaj
	return output;
	}
	}
	return L"Nie wiem co sprzedac";

	}
	return L"Nie rozumiem komendy " + text;
	*/
}

