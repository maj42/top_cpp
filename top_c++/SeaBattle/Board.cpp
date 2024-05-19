#include "Board.h"

int Board::cntrTime = 0;

Board::Board() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) field[i][j] = EMPTY;
	}
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) available.push_back(i);
	destroyed = false;
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
	srand(time(0) + cntrTime++);
	// 1 4-deck
	buildShip(4);
	// 2 3-deck
	for (int i = 0; i < DECK3; ++i) {
		buildShip(3);
	}
	// 3 2-deck
	for (int i = 0; i < DECK2; ++i) {
		buildShip(2);
	}
	// 4 1-deck
	for (int i = 0; i < DECK1; ++i) {
		buildShip(1);
	}
	return *this;
}

Board& Board::manualInit(Board&) {
	srand(time(0));
	//TODO
	return *this;
}

inline char& Board::operator()(const int row, const int col) {
	return Board::field[row][col];
}

inline char Board::operator()(const int row, const int col) const {
	return Board::field[row][col];
}

std::ostream& operator << (std::ostream& stream, const Board& board) {
	stream << " ";
	for (int i = 0; i < BOARD_SIZE; ++i) {
		stream << " " << i << " ";
	}
	stream << ' ' << std::endl;

	for (int i = 0; i < BOARD_SIZE; ++i) {
		stream << char('A' + i);
		for (int j = 0; j < BOARD_SIZE; ++j) {
			stream << " " << board(i, j) << " ";
		}
		stream << ' ' << std::endl;
	}
	return stream;
}

void printBoards(const Board& first, const Board& second, bool humanPlay) {
	std::cout << "\t     " << (humanPlay ? "You" : "Bot1") << "\t\t\t\t     " << (humanPlay ? "Bot" : "Bot2") << "\n\n";
	std::cout << " ";
	for (int i = 0; i < BOARD_SIZE; ++i) {
		std::cout << " " << i << " ";
	}
	std::cout << "\t\t ";
	for (int i = 0; i < BOARD_SIZE; ++i) {
		std::cout << " " << i << " ";
	}
	std::cout << std::endl;

	for (int row = 0; row < BOARD_SIZE; ++row) {
		std::cout << char('A' + row);
		for (int col1 = 0; col1 < BOARD_SIZE; ++col1) {
			std::cout << " " << first(row, col1) << " ";
		}
		std::cout << "\t\t";
		std::cout << char('A' + row);
		for (int col2 = 0; col2 < BOARD_SIZE; ++col2) {
			std::cout << " ";
			if (!DEBUG && humanPlay && second(row, col2) == SHIP) std::cout << EMPTY;
			else std::cout << second(row, col2);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

inline bool Board::checkBorders(const int row, const int col) const {
	return (row >= 0 && row < BOARD_SIZE) && (col >= 0 && col < BOARD_SIZE);
}

inline bool Board::checkEmpty(const int row, const int col) const {
	return (*this)(row, col) == EMPTY;
}

inline bool Board::checkPlacement(const int row, const int col) const {
	if (checkBorders(row, col) && checkEmpty(row, col)) return true;
	return false;
}

bool Board::checkNeighbours(const int row, const int col, const int occup = 0) const {
	int cntr = 0;
	for (int x = -1; x < 2; ++x) {
		for (int y = -1; y < 2; ++y) {
			if (row + x < 0 || row + x >= BOARD_SIZE || col + y < 0 || col + y >= BOARD_SIZE) continue;
			// Doesn't work in DEBUG ------
			if (((*this)(row - 1, col) == SHIP + (*this)(row + 1, col) == SHIP + (*this)(row, col - 1) == SHIP + (*this)(row, col + 1) == SHIP) > 1) return false;
			// ----------------------------
			if (!checkEmpty(row + x, col + y)) cntr++;
			if (cntr > occup) return false;
		}
	}
	return true;
}

Board& Board::buildShip(const int decks) {
	int anchorX, anchorY, deckX, deckY, tempX, tempY;
	int cntr;
	int dice;

	while (1) {
		anchorX = rand() % 10;
		anchorY = rand() % 10;
		if (checkNeighbours(anchorX, anchorY)) {
			deckX = anchorX;
			deckY = anchorY;
			break;
		}
	}
	char temp = '1'; // debug
	for (int j = 0; j < decks; ++j) {
		(*this)(deckX, deckY) = (DEBUG ? temp++ : SHIP);
		cntr = 0;
		while (1) {
			dice = rand() % 4;
			switch (dice) {
			case 0:
				tempX = 1;
				tempY = 0;
				break;
			case 1:
				tempX = -1;
				tempY = 0;
				break;
			case 2:
				tempX = 0;
				tempY = 1;
				break;
			case 3:
				tempX = 0;
				tempY = -1;
				break;
			default:
				break;
			}
			if (checkNeighbours(deckX + tempX, deckY + tempY, 2) && checkPlacement(deckX + tempX, deckY + tempY)) {
				deckX += tempX;
				deckY += tempY;
				break;
			}
			if (cntr++ == 10) {
				deckX = anchorX;
				deckY = anchorY;
				cntr = 0;
			}
		}
	}
	return *this;
}

Board& Board::humanMove() {
	// TODO
	return *this;
}

Board& Board::botMove(bool smart) {
	srand(time(0) + cntrTime++);
	// TODO smart move
	int dice = rand() % available.size();
	auto it = std::next(available.begin(), dice);
	dice = *it;
	shoot(dice / 10, dice % 10);
	available.remove(dice);
	checkAllDestroyed();
	return *this;
}

Board& Board::shoot(const int row, const int col) {
	switch ((*this)(row, col)) {
	case EMPTY:
		std::cout << char(row + 'A') << col << " Missed" << std::endl;
		(*this)(row, col) = SHOT;
		available.remove(row * 10 + col);
		break;
	case SHOT:
	case SHIP_DESTR:
		std::cout << char(row + 'A') << col << " Already shot here!" << std::endl;
		break;
	case SHIP:
		std::cout << char(row + 'A') << col << " Hit!" << std::endl;
		(*this)(row, col) = SHIP_DESTR;
		available.remove(row * 10 + col);
		break;
	}
	return *this;
}

Board& Board::checkAllDestroyed() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			if ((*this)(i, j) == SHIP) return *this;
		}
	}
	destroyed = true;
	return *this;
}
