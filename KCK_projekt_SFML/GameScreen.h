#pragma once

class GameScreen
{
public:
	GameScreen();
	~GameScreen();
	
	static sf::Sprite getBackground();
	static void display();

private:
	static void setBackGround(const char* localisation);
	static void setPosition(float x = 30, float y = 30);

	static sf::Texture texture;
	static sf::Sprite sprite;

	static const char* textureLocalisation;
};