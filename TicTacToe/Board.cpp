#include "Board.h"

Board::Board() {
	// set default sizes:
	board.setSize({ 400, 400 });
}

Board::Board(sf::Vector2f size, sf::Color color) {
	// set user defined:
	board.setSize(size);
	board.setFillColor(color);
	turn = "o";
}

void Board::checkClicking(std::string e, sf::RenderWindow &window) {
	// get mouse coords:
	sf::Vector2i mouseCoords({ sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y });
	sf::Vector2f realCoords = window.mapPixelToCoords(mouseCoords);
	float mouseX = realCoords.x;
	float mouseY = realCoords.y;

	// line widths:
	float lineWidth = firstVerticalLine.getSize().x;

	/* click on certain boxes */
	if (e == "click") {
		// TOP LEFT BOX:
		if (mouseX > board.getPosition().x && mouseX < firstVerticalLine.getPosition().x &&
			mouseY > board.getPosition().y && mouseY < topHorizLine.getPosition().y) {
			// if spot is still open:
			if (topLeft) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 10, board.getPosition().y + 10 });
				// mark spot as taken:
				topLeft = false;
			}
		}
		// TOP MIDDLE BOX:
		else if (mouseX > firstVerticalLine.getPosition().x + lineWidth && mouseX < secondVerticalLine.getPosition().x &&
			mouseY > board.getPosition().y && mouseY < topHorizLine.getPosition().y) {
			// if spot is still open:
			if (topMiddle) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 300, board.getPosition().y + 10 });
				// mark spot as taken:
				topMiddle = false;
			}
		}
		// TOP RIGHT BOX:
		else if (mouseX > secondVerticalLine.getPosition().x + lineWidth && mouseX < board.getPosition().x + board.getSize().x &&
			mouseY > board.getPosition().y && mouseY < topHorizLine.getPosition().y) {
			// if spot is still open:
			if (topRight) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 570, board.getPosition().y + 10 });
				// mark spot as taken:
				topRight = false;
			}
		}

		// MIDDLE LEFT BOX:
		if (mouseX > board.getPosition().x && mouseX < firstVerticalLine.getPosition().x &&
			mouseY > topHorizLine.getPosition().y + lineWidth && mouseY < bottomHorizLine.getPosition().y) {
			// if spot is still open:
			if (middleLeft) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 10, board.getPosition().y + 300 });
				// mark spot as taken:
				middleLeft = false;
			}
		}
		// MIDDLE MIDDLE BOX:
		else if (mouseX > firstVerticalLine.getPosition().x + lineWidth && mouseX < secondVerticalLine.getPosition().x &&
			mouseY > topHorizLine.getPosition().y + lineWidth && mouseY < bottomHorizLine.getPosition().y) {
			// if spot is still open:
			if (middleMiddle) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 300, board.getPosition().y + 300 });
				// mark spot as taken:
				middleMiddle = false;
			}
		}
		// MIDDLE RIGHT BOX:
		else if (mouseX > secondVerticalLine.getPosition().x + lineWidth && mouseX < board.getPosition().x + board.getSize().x &&
			mouseY > topHorizLine.getPosition().y + lineWidth && mouseY < bottomHorizLine.getPosition().y) {
			// if spot is still open:
			if (middleRight) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 570, board.getPosition().y + 300 });
				// mark spot as taken:
				middleRight = false;
			}
		}

		// BOTTOM LEFT BOX:
		if (mouseX > board.getPosition().x && mouseX < firstVerticalLine.getPosition().x &&
			mouseY > bottomHorizLine.getPosition().y + lineWidth && mouseY < board.getPosition().y + board.getSize().y) {
			// if spot is still open:
			if (bottomLeft) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 10, board.getPosition().y + 580 });
				// mark spot as taken:
				bottomLeft = false;
			}
		}
		// BOTTOM MIDDLE BOX:
		else if (mouseX > firstVerticalLine.getPosition().x + lineWidth && mouseX < secondVerticalLine.getPosition().x &&
			mouseY > bottomHorizLine.getPosition().y + lineWidth && mouseY < board.getPosition().y + board.getSize().y) {
			// if spot is still open:
			if (bottomMiddle) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 300, board.getPosition().y + 580 });
				// mark spot as taken:
				bottomMiddle = false;
			}
		}
		// BOTTOM RIGHT BOX:
		else if (mouseX > secondVerticalLine.getPosition().x + lineWidth && mouseX < board.getPosition().x + board.getSize().x &&
			mouseY > bottomHorizLine.getPosition().y + lineWidth && mouseY < board.getPosition().y + board.getSize().y) {
			// if spot is still open:
			if (bottomRight) {
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 570, board.getPosition().y + 580 });
				// mark spot as taken:
				bottomRight = false;
			}
		}
	}
}

void Board::setPosition(sf::Vector2f pos) {
	board.setPosition(pos);
	createLines();
}

void Board::drawTo(sf::RenderWindow &window) {
	// draw board and lines:
	window.draw(board);
	window.draw(firstVerticalLine);
	window.draw(secondVerticalLine);
	window.draw(topHorizLine);
	window.draw(bottomHorizLine);

	// draw x's and o's:
	for (int i = 0; i < xVec.size(); i++) {
		xVec[i]->drawTo(window);
	}
	for (int i = 0; i < oVec.size(); i++) {
		oVec[i]->drawTo(window);
	}
}

void Board::createLines() {
	// line width:
	float lineWidth = 20;

	// set line colors to white:
	firstVerticalLine.setFillColor(sf::Color::White);
	secondVerticalLine.setFillColor(sf::Color::White);
	topHorizLine.setFillColor(sf::Color::White);
	bottomHorizLine.setFillColor(sf::Color::White);

	/* x and y values gotten through experiment (don't ask) */

	// set two vertical line positions/sizes:
	firstVerticalLine.setPosition({ board.getPosition().x + (board.getSize().x / 4) + 40, board.getPosition().y });
	firstVerticalLine.setSize({ lineWidth, board.getSize().y });

	secondVerticalLine.setPosition({ board.getPosition().x + ((board.getSize().x / 4) * 3) - 55, board.getPosition().y });
	secondVerticalLine.setSize({ lineWidth, board.getSize().y });

	// set two horizontal line positions/sizes:
	topHorizLine.setPosition({ board.getPosition().x, board.getPosition().y + (board.getSize().y / 4) + 40 });
	topHorizLine.setSize({ board.getSize().x, lineWidth });

	bottomHorizLine.setPosition({ board.getPosition().x, board.getPosition().y + ((board.getSize().y / 4) * 3) - 40 });
	bottomHorizLine.setSize({ board.getSize().x, lineWidth });
	
}

// draw x's and o's
void Board::drawXorO(sf::Vector2f pos) {
	// if it's x's turn:
	if (turn == "x") {
		xVec.push_back(new Xmark());
		xVec[xNum]->setSprite("resources/x.png");
		xVec[xNum++]->setPosition({ pos.x, pos.y });

		// make it next person's turn:
		turn = "o";
		return;
	}
	// if it's y's turn:
	else if (turn == "o") {
		oVec.push_back(new Omark());
		oVec[oNum]->setSprite("resources/o.png");
		oVec[oNum++]->setPosition({ pos.x, pos.y });

		// make it next person's turn:
		turn = "x";
		return;
	}
}

Board::~Board() {
}
