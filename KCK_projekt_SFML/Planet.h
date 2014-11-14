#pragma once
class Planet
{
public:


	void display();

	Planet();
	Planet(float x, float y, float numer);
	~Planet();
	float getX();
	float getY();
	
private:
	void setTexture(unsigned numer);
	void setCoordinates(float x, float y);
	bool interactive;
	

	 sf::Texture planetTexture;
	 sf::Sprite planetSprite;
};

