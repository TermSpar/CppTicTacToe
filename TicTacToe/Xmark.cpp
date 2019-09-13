#include "Xmark.h"

Xmark::Xmark() {
}

void Xmark::setSprite(std::string dir) {
	xTexture.loadFromFile(dir);
	xmark.setTexture(xTexture);
}

void Xmark::setPosition(sf::Vector2f pos) {
	xmark.setPosition(pos);
}

void Xmark::drawTo(sf::RenderWindow &window) {
	window.draw(xmark);
}

Xmark::~Xmark() {
}
