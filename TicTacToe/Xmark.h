#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Xmark {
public:
	Xmark();

	// set sprite (to avoid copying errors):
	void setSprite(std::string dir);

	void setPosition(sf::Vector2f pos);

	void drawTo(sf::RenderWindow &w);

	~Xmark();

private:
	sf::Texture xTexture;
	sf::Sprite xmark;
};