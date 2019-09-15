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

std::string Board::getWinnerOrTie() {
	return winnerOrTie;
}

int Board::getXscore() {
	return scoreX;
}

int Board::getOscore() {
	return scoreO;
}

void Board::resetGame() {
	// clear vectors:
	xNum = 0;
	xVec.clear();

	oNum = 0;
	oVec.clear();

	// clear array:
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			XOarray[i][j] = NULL;
		}
	}

	// reset spaces to open:
	topLeft = true; topMiddle = true; topRight = true;
	middleLeft = true; middleMiddle = true; middleRight = true;
	bottomLeft = true; bottomMiddle = true; bottomRight = true;

	isWinner = false;
	winnerOrTie = "none";
	moves = 0;
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
				// account for x or o:
				if (turn == "x")
					XOarray[0][0] = 'x';
				else
					XOarray[0][0] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 10, board.getPosition().y + 10 });
				// mark spot as taken:
				moves++;
				topLeft = false;
			}
		}
		// TOP MIDDLE BOX:
		else if (mouseX > firstVerticalLine.getPosition().x + lineWidth && mouseX < secondVerticalLine.getPosition().x &&
			mouseY > board.getPosition().y && mouseY < topHorizLine.getPosition().y) {
			// if spot is still open:
			if (topMiddle) {
				// account for x or o:
				if (turn == "x")
					XOarray[0][1] = 'x';
				else
					XOarray[0][1] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 300, board.getPosition().y + 10 });
				// mark spot as taken:
				moves++;
				topMiddle = false;
			}
		}
		// TOP RIGHT BOX:
		else if (mouseX > secondVerticalLine.getPosition().x + lineWidth && mouseX < board.getPosition().x + board.getSize().x &&
			mouseY > board.getPosition().y && mouseY < topHorizLine.getPosition().y) {
			// if spot is still open:
			if (topRight) {
				// account for x or o:
				if (turn == "x")
					XOarray[0][2] = 'x';
				else
					XOarray[0][2] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 570, board.getPosition().y + 10 });
				// mark spot as taken:
				moves++;
				topRight = false;
			}
		}

		// MIDDLE LEFT BOX:
		if (mouseX > board.getPosition().x && mouseX < firstVerticalLine.getPosition().x &&
			mouseY > topHorizLine.getPosition().y + lineWidth && mouseY < bottomHorizLine.getPosition().y) {
			// if spot is still open:
			if (middleLeft) {
				// account for x or o:
				if (turn == "x")
					XOarray[1][0] = 'x';
				else
					XOarray[1][0] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 10, board.getPosition().y + 300 });
				// mark spot as taken:
				moves++;
				middleLeft = false;
			}
		}
		// MIDDLE MIDDLE BOX:
		else if (mouseX > firstVerticalLine.getPosition().x + lineWidth && mouseX < secondVerticalLine.getPosition().x &&
			mouseY > topHorizLine.getPosition().y + lineWidth && mouseY < bottomHorizLine.getPosition().y) {
			// if spot is still open:
			if (middleMiddle) {
				// account for x or o:
				if (turn == "x")
					XOarray[1][1] = 'x';
				else
					XOarray[1][1] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 300, board.getPosition().y + 300 });
				// mark spot as taken:
				moves++;
				middleMiddle = false;
			}
		}
		// MIDDLE RIGHT BOX:
		else if (mouseX > secondVerticalLine.getPosition().x + lineWidth && mouseX < board.getPosition().x + board.getSize().x &&
			mouseY > topHorizLine.getPosition().y + lineWidth && mouseY < bottomHorizLine.getPosition().y) {
			// if spot is still open:
			if (middleRight) {
				// account for x or o:
				if (turn == "x")
					XOarray[1][2] = 'x';
				else
					XOarray[1][2] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 570, board.getPosition().y + 300 });
				// mark spot as taken:
				moves++;
				middleRight = false;
			}
		}

		// BOTTOM LEFT BOX:
		if (mouseX > board.getPosition().x && mouseX < firstVerticalLine.getPosition().x &&
			mouseY > bottomHorizLine.getPosition().y + lineWidth && mouseY < board.getPosition().y + board.getSize().y) {
			// if spot is still open:
			if (bottomLeft) {
				// account for x or o:
				if (turn == "x")
					XOarray[2][0] = 'x';
				else
					XOarray[2][0] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 10, board.getPosition().y + 580 });
				// mark spot as taken:
				moves++;
				bottomLeft = false;
			}
		}
		// BOTTOM MIDDLE BOX:
		else if (mouseX > firstVerticalLine.getPosition().x + lineWidth && mouseX < secondVerticalLine.getPosition().x &&
			mouseY > bottomHorizLine.getPosition().y + lineWidth && mouseY < board.getPosition().y + board.getSize().y) {
			// if spot is still open:
			if (bottomMiddle) {
				// account for x or o:
				if (turn == "x")
					XOarray[2][1] = 'x';
				else
					XOarray[2][1] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 300, board.getPosition().y + 580 });
				// mark spot as taken:
				moves++;
				bottomMiddle = false;
			}
		}
		// BOTTOM RIGHT BOX:
		else if (mouseX > secondVerticalLine.getPosition().x + lineWidth && mouseX < board.getPosition().x + board.getSize().x &&
			mouseY > bottomHorizLine.getPosition().y + lineWidth && mouseY < board.getPosition().y + board.getSize().y) {
			// if spot is still open:
			if (bottomRight) {
				// account for x or o:
				if (turn == "x")
					XOarray[2][2] = 'x';
				else
					XOarray[2][2] = 'o';
				// draw x or o in that box:
				drawXorO({ board.getPosition().x + 570, board.getPosition().y + 580 });
				// mark spot as taken:
				moves++;
				bottomRight = false;
			}
		}
	}
	// check for wins:
	checkForWins();
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

void Board::checkForWins() {
	// loop through XOarray:
	for (int vert = 0; vert < 3; vert++) {
		for (int horiz = 0; horiz < 3; horiz++) {
			// check for horizontal wins:
			if (XOarray[vert][horiz + 1] != NULL && XOarray[vert][horiz - 1] != NULL && (horiz - 1) != -1 && (horiz + 1) < 3) {
				if (XOarray[vert][horiz] == XOarray[vert][horiz + 1] && XOarray[vert][horiz] == XOarray[vert][horiz - 1]) {
					if (!isWinner) {
						if (XOarray[vert][horiz] == 'x') {
							winnerOrTie = "X";
							scoreX++;
						}
						else {
							winnerOrTie = "O";
							scoreO++;
						}
					}
					isWinner = true;
				}
			}
			// check for vertical wins:
			else if (XOarray[vert + 1][horiz] != NULL && XOarray[vert - 1][horiz] != NULL) {
				if (XOarray[vert][horiz] == XOarray[vert + 1][horiz] && XOarray[vert][horiz] == XOarray[vert - 1][horiz]) {
					if (!isWinner) {
						if (XOarray[vert][horiz] == 'x') {
							winnerOrTie = "X";
							scoreX++;
						}
						else {
							winnerOrTie = "O";
							scoreO++;
						}
					}
					isWinner = true;
				}
			}

			// weird bug fix:
			if (XOarray[0][1] != NULL) {
				if (XOarray[0][1] == XOarray[1][1] && XOarray[0][1] == XOarray[2][1]) {
					if (XOarray[0][1] == 'x') {
						if (!isWinner) {
							winnerOrTie = "X";
							scoreX++;
						}
						isWinner = true;
					}
				}
			}
		}
	}
	// check diagonal wins:
	if ((XOarray[0][0] != NULL && XOarray[1][1] != NULL && XOarray[2][2] != NULL) ||
		XOarray[0][2] != NULL && XOarray[1][1] != NULL) {
		if ((XOarray[0][0] == XOarray[1][1] && XOarray[0][0] == XOarray[2][2]) ||
			(XOarray[0][2] == XOarray[1][1] && XOarray[0][2] == XOarray[2][0])) {
			if (!isWinner) {
				if (XOarray[1][1] == 'x') {
					winnerOrTie = "X";
					scoreX++;
				}
				else {
					winnerOrTie = "O";
					scoreO++;
				}
				isWinner = true;
			}
		}
	}

	// if it's a tie:
	if (moves == 9 && !isWinner) {
		winnerOrTie = "TIE";
		return;
	}
}

Board::~Board() {
}