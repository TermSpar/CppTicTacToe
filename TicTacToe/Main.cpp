#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

#include "Board.h"
#include "Button.h"

int main() {
	sf::RenderWindow window;

	float xSize = 1200;
	float ySize = 970;

	sf::Vector2i centerWindow((sf::VideoMode::getDesktopMode().width / 2) - (xSize / 2), (sf::VideoMode::getDesktopMode().height / 2) - 510);

	window.create(sf::VideoMode(xSize, ySize), "C++ TicTacToe", sf::Style::Titlebar | sf::Style::Close);
	window.setPosition(centerWindow);

	window.setKeyRepeatEnabled(true);

	// board variables:
	Board board({800, 800}, sf::Color(128 , 128 , 128));
	board.setPosition({ static_cast<float>(window.getSize().x / 6), static_cast<float>(window.getSize().y / 6) - 20 });

	// winner/tie label:
	sf::Font font; font.loadFromFile("resources/terminal.otf");
	sf::Text winnerOrTie; winnerOrTie.setFont(font); winnerOrTie.setCharacterSize(80);
	winnerOrTie.setColor(sf::Color::Green); winnerOrTie.setPosition({ 60, 17 });
	winnerOrTie.setString("");

	// score label/vars:
	sf::Text score; score.setFont(font); score.setCharacterSize(80);
	score.setColor(sf::Color::White); score.setPosition({ 200, 17 });
	score.setString("X's: 0                      O's: 0");
	int scoreX = 0;
	int scoreO = 0;
	std::ostringstream scoreText;

	// replay button:
	Button btnReplay("Play Again", { 200, 80 }, 25, sf::Color::Green, sf::Color::Black);
	btnReplay.setFont(font);
	btnReplay.setPosition({ 910, 30 });

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

				// if game is over:
				if (board.getWinnerOrTie() != "none") {
					if (btnReplay.isMouseOver(window)) {
						board.resetGame();
					}
				}
				break;
			case sf::Event::MouseButtonReleased:
				e = "";
				break;
			}
			// send clicking events:
			board.checkClicking(e, window);

		}
		window.clear();

		// draw board:
		board.drawTo(window);

		// if there's no winner:
		if (board.getWinnerOrTie() == "none") {
			// keep track of score
			scoreText.str("");
			scoreText << "X's: " << board.getXscore() << "                      O's: " << board.getOscore();
			score.setString(scoreText.str());
			window.draw(score);
		}
		else {
			// if x wins:
			if (board.getWinnerOrTie() == "X") {
				winnerOrTie.setString("X has won the game!");
			}
			else if (board.getWinnerOrTie() == "O") {
				winnerOrTie.setString("O has won the game!");
			}
			else {
				winnerOrTie.setString("The game was tied!");
			}
			// draw display label and replay button:
			window.draw(winnerOrTie);
			btnReplay.drawTo(window);
		}
		window.display();
	}
}