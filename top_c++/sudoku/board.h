#pragma once
#include <iostream>
#include <set>
#include <chrono>
#include <thread>
#include "board.h"

#define STARTING_GRIDS 10

const bool DEBUG = false;

class Board
{
	char grid[81];
	std::set<int> startingFill;
	int32_t boardState;
	Board& _randFill();
	char _parseNum(std::string&) const;
	char _parseCell(std::string&) const;
	void _checkState();
	bool _checkRowStatus(int) const;
	bool _checkColStatus(int) const;
	bool _checkCellStatus(int) const;

public:
	Board();
	Board& move(std::string, std::string);
	bool checkWin() const;
	friend std::ostream& operator<< (std::ostream&, Board&);
};