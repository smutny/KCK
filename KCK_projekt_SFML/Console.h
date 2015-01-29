#pragma once
 class Console
{
public:
	Console();
	~Console();

	static void doYourJob(sf::Event event);
	static void display();
	static void putTextLine(wstring line);
	static wstring getCaptainPrefix();
	static wstring getBanachPrefix();

private:
	static void setFont(const char* fontLocalisation);

	static int currentLineNumber;
	static int searchCurrentLineNumber;
	static int sLineNumber;
	static const int maxLineNumber = 10;					//mo¿na zmieniaæ (liczba wiêksza od 1)
	static  int fontSize;							//mo¿na zmieniaæ
	static  int firstLinePositionX;					//mo¿na zmieniaæ
	static  int firstLinePositionY;					//mo¿na zmieniaæ
	static  int lineSpacing;							//mo¿na zmieniaæ

	static wstring captainPrefix;	//mo¿na zmieniaæ
	static wstring banachPrefix;		//m¿na zmieniaæ
	

	static sf::Font font;
	static sf::Text text[maxLineNumber];

	static wstring str[maxLineNumber];
	static const char* fontLocalisation;
};

