#pragma once

#include <iostream>
#include <list>

const bool DEBUG = false;

const size_t BOARD_SIZE = 10;

const char EMPTY = ' ';
const char SHOT = 'o';
const char SHIP = '#';
const char SHIP_DESTR = 'x';

const int DECK4 = 1;
const int DECK3 = 2;
const int DECK2 = 3;
const int DECK1 = 4;

class Board {
	char field[BOARD_SIZE][BOARD_SIZE];
	std::list<int> available;

public:
	bool destroyed;
	static int cntrTime;

	// constr
	Board();
	Board(std::string init);

	// init
	Board& autoInit(Board&);
	Board& manualInit(Board&);  // TODO
	
	// op overloads
	char& operator()(int row, int col);
	char operator()(int row, int col) const;

	// checks
	bool checkBorders(int row, int col) const;
	bool checkEmpty(int row, int col) const;
	bool checkPlacement(int row, int col) const;
	bool checkNeighbours(int row, int col, int occup) const;
	
	Board& buildShip(int decks);
	Board& humanMove();
	Board& botMove(bool smart = false);
	Board& shoot(int row, int col);
	Board& checkAllDestroyed();
};

std::ostream& operator << (std::ostream& stream, const Board& board);
void printBoards(const Board& first, const Board& second, bool humanPlay);
