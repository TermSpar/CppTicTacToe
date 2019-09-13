#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Omark {
public:
	Omark();

	// set sprite (to avoid copying errors):
	void setSprite(std::string dir);

	void setPosition(sf::Vector2f pos);

	void drawTo(sf::RenderWindow &w);

	~Omark();

private:
	sf::Texture oTexture;
	sf::Sprite omark;
};