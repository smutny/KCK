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

void Console::dupa(sf::Event event)
{
	

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
				if (currentLineNumber < maxLineNumber - 2)
				{
					str[currentLineNumber + 1] = banachPrefix + Help::textAnalysis(temp);
					currentLineNumber = currentLineNumber + 2;
					str[currentLineNumber] = captainPrefix;
				}
				else
				{
					if (currentLineNumber == maxLineNumber - 2)
					{
						str[currentLineNumber + 1] = banachPrefix + Help::textAnalysis(temp);
						for (int i = 0; i < maxLineNumber - 1; i++)
						{
							str[i] = str[i + 1];
						}
						currentLineNumber = maxLineNumber - 1;
						str[currentLineNumber] = captainPrefix;
					}
					else
					{
						if (currentLineNumber == maxLineNumber - 1)
						{
							for (int i = 0; i < maxLineNumber - 2; i++)
							{
								str[i] = str[i + 2];
							}
							str[currentLineNumber - 1] = banachPrefix + Help::textAnalysis(temp);
							str[currentLineNumber] = captainPrefix;
						}
					}
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
