#include "stdafx.h"
#include "Window.h"
#include "Help.h"
#include "Console.h"
  int Console::fontSize = 15;								//mo¿na zmieniaæ
  int Console::firstLinePositionX = 550;					//mo¿na zmieniaæ
  int Console::firstLinePositionY = 40;					//mo¿na zmieniaæ
  int Console::lineSpacing = 5;

 const char* Console::fontLocalisation = "arial.ttf";

 int Console::currentLineNumber = 0;
 int Console::searchCurrentLineNumber = 0;
 int Console::sLineNumber = 0;
 wstring Console::str[maxLineNumber] = { L"" };
 wstring Console::captainPrefix = L"Kapitan >> ";	//mo¿na zmieniaæ
 wstring Console::banachPrefix = L"Banach >> ";		//mo¿na zmieniaæ



  sf::Font Console::font;
  sf::Text Console::text[maxLineNumber];


Console::~Console()
{
}

Console::Console()
{
	str[0] = captainPrefix;
}

void Console::doYourJob(sf::Event event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		while (searchCurrentLineNumber > 0 && str[searchCurrentLineNumber - 1].find(captainPrefix) == std::string::npos)
		{
			searchCurrentLineNumber--;
		}
		if (searchCurrentLineNumber > 0)
		{
			searchCurrentLineNumber--;
			str[currentLineNumber] = str[searchCurrentLineNumber];
			sLineNumber = searchCurrentLineNumber;
		}
		else
		{
			searchCurrentLineNumber = sLineNumber;
			str[currentLineNumber] = str[searchCurrentLineNumber];
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		while (searchCurrentLineNumber < currentLineNumber - 1 && str[searchCurrentLineNumber + 1].find(captainPrefix) == std::string::npos)
		{
			searchCurrentLineNumber++;
		}
		if (searchCurrentLineNumber < currentLineNumber - 1)
		{
			searchCurrentLineNumber++;
			str[currentLineNumber] = str[searchCurrentLineNumber];
			sLineNumber = searchCurrentLineNumber;
		}
		else
		{
			searchCurrentLineNumber = sLineNumber;
			str[currentLineNumber] = str[searchCurrentLineNumber];
		}
	}
	

	if (event.type == sf::Event::TextEntered)
	{
		if (static_cast<wchar_t>(event.text.unicode) != L'\r' && static_cast<wchar_t>(event.text.unicode) != L'\b')
		{
			str[currentLineNumber] += static_cast<wchar_t>(event.text.unicode);
		}
		else
		{
			if (static_cast<wchar_t>(event.text.unicode) == L'\r')
			{
				std::wstring temp;
				for (auto i = captainPrefix.length(); i < str[currentLineNumber].length(); i++)
				{
					temp += str[currentLineNumber][i];
				}

				if (currentLineNumber < maxLineNumber - 1)
				{
					currentLineNumber++;
					sLineNumber = searchCurrentLineNumber = currentLineNumber;
					Console::putTextLine(banachPrefix + Help::textAnalysis(temp));
				}
				else
				{
					for (int i = 0; i < maxLineNumber - 1; i++)
					{
						str[i] = str[i + 1];
					}
					sLineNumber = searchCurrentLineNumber = currentLineNumber;
					Console::putTextLine(banachPrefix + Help::textAnalysis(temp));
				}
			}
			else
			{
				if (str[currentLineNumber].length() != captainPrefix.length()) str[currentLineNumber].pop_back();
			}
		}
	}
}

void Console::setFont(const char* fontLocalisation)
{
	font.loadFromFile(fontLocalisation);
}

void Console::display()
{
	setFont(fontLocalisation);

	for (int i = 0; i < maxLineNumber; i++)
		{
			text[i].setFont(font);
			text[i].setString(str[i]);
			text[i].setCharacterSize(fontSize);
			text[i].setColor(sf::Color::Green);
			text[i].setPosition(firstLinePositionX, firstLinePositionY + i * (fontSize + lineSpacing));
		}

	for (int i = 0; i < maxLineNumber; i++)
	{
		Window::draw(text[i]);
	}

}

void Console::putTextLine(wstring line)
{
	str[currentLineNumber] = line;

	if (currentLineNumber < maxLineNumber - 1)
	{
		currentLineNumber++;
		sLineNumber = searchCurrentLineNumber = currentLineNumber;
	}
	else
	{
		for (int i = 0; i < maxLineNumber - 1; i++)
		{
			str[i] = str[i + 1];
		}
	}

	str[currentLineNumber] = captainPrefix;
}