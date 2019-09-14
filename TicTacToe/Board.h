#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Xmark.h"
#include "Omark.h"

class Board {
public:
	// constructors:
	Board();

	Board(sf::Vector2f, sf::Color);

	// click on certain peices of board:
	void checkClicking(std::string, sf::RenderWindow &w);

	// return who won the game or tie:
	std::string getWinnerOrTie();

	// get scores:
	int getXscore();

	int getOscore();

	// reset the game:
	void resetGame();

	// set board position on window:
	void setPosition(sf::Vector2f);

	// draw everything to window:
	void drawTo(sf::RenderWindow &w);

	~Board();

private:
	// board outline:
	sf::RectangleShape board;
	sf::RectangleShape firstVerticalLine;
	sf::RectangleShape secondVerticalLine;
	sf::RectangleShape topHorizLine;
	sf::RectangleShape bottomHorizLine;

	// keep track of which spots are open:
	bool topLeft = true; bool topMiddle = true; bool topRight = true;
	bool middleLeft = true; bool middleMiddle = true; bool middleRight = true;
	bool bottomLeft = true; bool bottomMiddle = true; bool bottomRight = true;

	// x and o arrays:
	std::vector<Xmark*> xVec;
	int xNum = 0;
	std::vector<Omark*> oVec;
	int oNum = 0;

	// check who's turn it is:
	std::string turn;

	// create the lines on the board:
	void createLines();

	// draw x's and o's
	void drawXorO(sf::Vector2f pos);

	// check for wins:
	char XOarray[3][3];
	void checkForWins();
	std::string winnerOrTie = "none";

	// score vars:
	int scoreX = 0;
	int scoreO = 0;

	// reset game vars:
	int moves = 0;
	bool isWinner = false;
};

