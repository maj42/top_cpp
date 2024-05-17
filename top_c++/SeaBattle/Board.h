#pragma once

#include <iostream>
#include <list>

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
	Board();
	Board(std::string init);
	Board& autoInit(Board&);
	Board& manualInit(Board&);

	char getCell(int row, int col) const;
	Board& setCell(int row, int col, char sym);
};

std::ostream& operator << (std::ostream& stream, const Board& board);