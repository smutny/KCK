#include "stdafx.h"
#include "GameScreen.h"

sf::Texture GameScreen::texture;
sf::Sprite  GameScreen::sprite;
const char* GameScreen::textureLocalisation = "KOSMOS.jpg";

GameScreen::GameScreen()
{
	setBackGround(textureLocalisation);
	setPosition();
}

GameScreen::~GameScreen()
{
}

sf::Sprite GameScreen::getBackground()
{
	return sprite;
}

void GameScreen::setBackGround(const char* localisation)
{
	texture.loadFromFile(localisation);
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(100, 100, 490, 490));
}

void GameScreen::setPosition(float x, float y)
{
	sprite.setPosition(x, y);

}