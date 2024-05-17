#include "Board.h"

Board::Board() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) field[i][j] = EMPTY;
	}
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) available.push_back(i);
}

Board::Board(std::string init) : Board() {
	if (init == "auto") {
		autoInit(*this);
	}
	else if (init == "manual") {
		manualInit(*this);
	}
}

Board& Board::autoInit(Board&) {
	srand(time(0));
	//TODO
	return *this;
}

Board& Board::manualInit(Board&) {
	srand(time(0));
	//TODO
	return *this;
}

char Board::getCell(int row, int col) const {
	return field[row][col];
}

Board& Board::setCell(int row, int col, char sym) {
	Board::field[row][col] = sym;
	return *this;
};

std::ostream& operator << (std::ostream& stream, const Board& board) {
	stream << " ";
	for (int i = 0; i < BOARD_SIZE; ++i) {
		stream << " " << i << " ";
	}
	stream << ' ' << std::endl;

	for (int i = 0; i < BOARD_SIZE; ++i) {
		stream << char('A' + i);
		for (int j = 0; j < BOARD_SIZE; ++j) {
			stream << " " << board.getCell(i, j) << " ";
		}
		stream << ' ' << std::endl;
	}
	return stream;
}