#pragma once

#include <iostream>
#include <set>
#include <thread>

#define BOARD_SIZE 10
#define CLS "cls"

#if defined(__linux__)
#define CLS "clear"
#endif

const bool DEBUG = false;

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

public:
	struct ShootStack {
		std::set<int> stack;
		int operator[](int ind);
		int operator[](int ind) const;
		int size() const;
		int pop();
		void push(int cell);
		void remove(int cell);
		bool contains(int cell) const;
		bool empty() const;
	};

	bool destroyed;
	static int cntrTime;
	ShootStack shootStack;
	ShootStack available;

	// constr
	Board();
	Board(std::string init);

	// init
	Board& autoInit(Board&);
	Board& manualInit(Board&);
	
	// op overloads
	char& operator()(int row, int col);
	char operator()(int row, int col) const;

	// checks
	bool checkBorders(int row, int col) const;
	bool checkEmpty(int row, int col) const;
	bool checkPlacement(int row, int col) const;
	bool checkNeighbours(int row, int col, int occup) const;
	
	Board& buildShip(int decks);
	Board& buildManual(const int decks);
	Board& humanMove();
	Board& botMove(bool smart = false);
	Board& shoot(int row, int col, bool smart = false);
	Board& checkAllDestroyed();
	int stringCellToIntCell(std::string strCell);
};

std::ostream& operator << (std::ostream& stream, const Board& board);
void printBoards(const Board& first, const Board& second, bool humanPlay);
