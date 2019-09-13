#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board.h"

int main() {
	sf::RenderWindow window;

	float xSize = 1200;
	float ySize = 900;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - (xSize / 2), (sf::VideoMode::getDesktopMode().height / 2) - (ySize / 2));

	window.create(sf::VideoMode(xSize, ySize), "C++ TicTacToe", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	// board variables:
	Board board({800, 800}, sf::Color(128 , 128 , 128));
	board.setPosition({ static_cast<float>(window.getSize().x / 6), static_cast<float>(window.getSize().y / 6) - 100 });

	// event string:
	std::string e = "";

	//Main Loop:
	while (window.isOpen()) {

		sf::Event Event;

		//Event Loop:
		while (window.pollEvent(Event)) {
			switch (Event.type) {

			case sf::Event::Closed:
				window.close();
			case sf::Event::MouseButtonPressed:
				e = "click";
				break;
			case sf::Event::MouseButtonReleased:
				e = "";
				break;
			}
			board.checkClicking(e, window);
		}
		window.clear();

		board.drawTo(window);

		window.display();
	}
}