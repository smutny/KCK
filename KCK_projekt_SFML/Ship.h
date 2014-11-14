#pragma once

class Planet;

class Ship
{
public:
	Ship();

	~Ship();
	

	void display();

	void focus(Planet p);

	void calaNaprzod(string rozkaz);
	
	bool isBeyondMap();



	unsigned money;
	bool isStuck;

//private:
	void setTexture();
	void setPosition(float x = 460, float y = 460);


	sf::Texture statekTekstura;
	sf::Sprite statek;
};

