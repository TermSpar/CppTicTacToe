#include "Omark.h"

Omark::Omark() {
}

void Omark::setSprite(std::string dir) {
	oTexture.loadFromFile(dir);
	omark.setTexture(oTexture);
}

void Omark::setPosition(sf::Vector2f pos) {
	omark.setPosition(pos);
}

void Omark::drawTo(sf::RenderWindow &window) {
	window.draw(omark);
}

Omark::~Omark() {
}
