#pragma once
class Parameter
{
public:
	Parameter(int fs, int px, int py, char* fl, std::wstring l);
	~Parameter();

	void display(unsigned x);

private:
	void setFont(const char* fontLocalisation);


	int fontSize;
	int positionX;
	int positionY;
	std::wstring label;

	sf::Font font;
	sf::Text text;

	const char* fontLocalisation;
};


