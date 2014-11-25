#pragma once

class Planet
{
public:
	Planet();
	Planet(float x, float y, float numer);
	~Planet();

	int getX();
	int getY();

	void display();

private:
	void setTexture(unsigned numer);
	void setPosition(float x, float y);
	bool interactive;
	
	 sf::Texture planetTexture;
	 sf::Sprite planetSprite;
};

