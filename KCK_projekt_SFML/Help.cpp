#include "stdafx.h"
#include "Help.h"


Help::Help()
{
}


Help::~Help()
{
}



std::wstring Help::textAnalysis(std::wstring text)
{
	return L"Nie rozumiem polecenia \"" + text + L"\"";
}