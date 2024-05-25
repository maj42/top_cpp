#include "Board.h"
#include "color.hpp"

int Board::cntrTime = 0;

Board::Board() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) field[i][j] = EMPTY;
	}
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) available.push(i);
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
	// 1 4-deck
	buildManual(4);
	// 2 3-deck
	for (int i = 0; i < DECK3; ++i) {
		buildManual(3);
	}
	// 3 2-deck
	for (int i = 0; i < DECK2; ++i) {
		buildManual(2);
	}
	// 4 1-deck
	for (int i = 0; i < DECK1; ++i) {
		buildManual(1);
	}
	return *this;
}

int Board::stringCellToIntCell(std::string strCell) {
	if (strCell.length() != 2) return -1;
	if ((strCell[0] >= '0' && strCell[0] <= '9') && ((strCell[1] >= 'a' && strCell[1] < 'k') || (strCell[1] >= 'A' && strCell[1] < 'K'))) {
		const char first = strCell[0];
		const char second = strCell[1];
		strCell.clear();
		strCell += toascii(second);
		strCell += toascii(first);
	}
	if (((strCell[0] >= 'a' && strCell[0] < 'k') || (strCell[0] >= 'A' && strCell[0] < 'K')) && (strCell[1] >= '0' && strCell[1] <= '9')) {
		if (strCell[0] < 'a') return static_cast<int> (strCell[0] - 'A') * 10 + static_cast<int> (strCell[1] - '0');
		else return static_cast<int> (strCell[0] - 'a') * 10 + static_cast<int> (strCell[1] - '0');
	}
	return -1;
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
			std::cout << " ";
			char cell = first(row, col1);
			switch (cell) {
			case EMPTY:
				std::cout << dye::aqua(cell);
				break;
			case SHOT:
				std::cout << dye::aqua(cell);
				break;
			case SHIP:
				std::cout << dye::grey(cell);
				break;
			case SHIP_DESTR:
				std::cout << dye::red(cell);
				break;
			}
			std::cout << " ";
		}
		std::cout << "\t\t";
		std::cout << char('A' + row);
		for (int col2 = 0; col2 < BOARD_SIZE; ++col2) {
			std::cout << " ";
			if (!DEBUG && humanPlay && second(row, col2) == SHIP) std::cout << EMPTY;
			else {
				char cell = second(row, col2);
				switch (cell) {
				case EMPTY:
					std::cout << dye::aqua(EMPTY);
					break;
				case SHOT:
					std::cout << dye::aqua(SHOT);
					break;
				case SHIP:
					std::cout << dye::grey(SHIP);
					break;
				case SHIP_DESTR:
					std::cout << dye::red(SHIP_DESTR);
					break;
				}
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// debug ---------
	//std::cout << "First stack:" << std::endl;
	//for (int i = 0; i < first.shootStack.size(); ++i) {
	//	std::cout << first.shootStack[i] << " ";
	//}
	//std::cout << std::endl;
	//std::cout << "Second stack:" << std::endl;
	//for (int i = 0; i < second.shootStack.size(); ++i) {
	//	std::cout << second.shootStack[i] << " ";
	//}
	//std::cout << std::endl;
	// debug ---------
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
			if ((((*this)(row - 1, col) == SHIP) + ((*this)(row + 1, col) == SHIP) + ((*this)(row, col - 1) == SHIP) + ((*this)(row, col + 1) == SHIP)) > 1) return false;
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

Board& Board::buildManual(const int decks) {
	std::string anchor;
	int anchorX;
	int anchorY;
	while (1) {
		system(CLS);
		std::cout << *this << std::endl;
		std::cout << "Manual placement: place the main deck of a " << decks << "-deck ship : ";
		std::cin >> anchor;
		if (stringCellToIntCell(anchor) != -1) {
			anchorX = stringCellToIntCell(anchor) / 10;
			anchorY = stringCellToIntCell(anchor) % 10;
			if (checkNeighbours(anchorX, anchorY)) break;
			else {
				std::cout << "Too close to other ship" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				system(CLS);
			}
		}
		else {
			std::cout << "Invalid cell" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system(CLS);
		}
	}
	
	(*this)(anchorX, anchorY) = SHIP;
	int deckX = anchorX;
	int deckY = anchorY;

	for (int i = 1; i < decks; ++i) {
		system(CLS);
		std::cout << *this << std::endl;
		int incrX = 0;
		int incrY = 0;
		while (1) {
			std::cout << "Where do you want to place the next deck? (use WASD): " << std::endl;
			std::string next;
			while (1) {
				std::cin >> next;
				if (next.length() == 1) break;
				else std::cout << "More than 1 character. Use keys 'w', 'a', 's' or 'd'" << std::endl;
			}
			switch (next[0]) {
			case 'w':
				incrX--;
				break;
			case 'a':
				incrY--;
				break;
			case 's':
				incrX++;
				break;
			case 'd':
				incrY++;
				break;
			default:
				std::cout << "Invalid input. Use keys 'w', 'a', 's' or 'd'" << std::endl;
				continue;
			}

			if (!checkEmpty(deckX + incrX, deckY + incrY)) {
				std::cout << "Can't place deck here, there's deck already" << std::endl;
				incrX = 0;
				incrY = 0;
			}
			else if (!checkBorders(deckX + incrX, deckY + incrY)) {
				std::cout << "Can't place deck here, out of borders" << std::endl;
				incrX = 0;
				incrY = 0;
			}
			else if (!checkNeighbours(deckX + incrX, deckY + incrY, 2)) {
				std::cout << "Can't place deck here, ship nearby" << std::endl;
				incrX = 0;
				incrY = 0;
			}
			else if ((((*this)(deckX + incrX - 1, deckY + incrY) == SHIP) + ((*this)(deckX + incrX + 1, deckY + incrY) == SHIP)
				+ ((*this)(deckX + incrX, deckY + incrY - 1) == SHIP) + ((*this)(deckX + incrX, deckY + incrY + 1) == SHIP)) > 1) {
				std::cout << "Can't place deck here, ship nearby" << std::endl;
				incrX = 0;
				incrY = 0;
			}
			else break;
		}
		deckX += incrX;
		deckY += incrY;
		incrX = 0;
		incrY = 0;
		(*this)(deckX, deckY) = SHIP;
	}
	return *this;
}

Board& Board::humanMove() {
	std::string strShot;
	int shot;
	while (1) {
		std::cout << "Choose a cell to shot: ";
		std::cin >> strShot;
		shot = stringCellToIntCell(strShot);
		if (shot != -1) break;
		std::cout << "Invalid input" << std::endl;
	}
	shoot(shot / 10, shot % 10);
	available.remove(shot);
	checkAllDestroyed();
	return *this;
}

Board& Board::botMove(bool smart) {
	srand(time(0) + cntrTime++);
	int dice;
	if (smart && !shootStack.empty()) {
		dice = shootStack.pop();
	}
	else {
		dice = rand() % available.size();
		dice = available[dice];
	}
	shoot(dice / 10, dice % 10, smart);
	available.remove(dice);
	checkAllDestroyed();
	return *this;
}

Board& Board::shoot(const int row, const int col, bool smart) {
	switch ((*this)(row, col)) {
	case EMPTY:
		std::cout << char(row + 'A') << col << dye::aqua(" Missed") << std::endl;
		(*this)(row, col) = SHOT;
		available.remove(row * 10 + col);
		break;
	case SHOT:
	case SHIP_DESTR:
		std::cout << char(row + 'A') << col << " Already shot here!" << std::endl;
		break;
	case SHIP:
		std::cout << char(row + 'A') << col << dye::red(" Hit!") << std::endl;
		(*this)(row, col) = SHIP_DESTR;
		available.remove(row * 10 + col);
		shootStack.remove(row * 10 + col);
		if (smart) {
			if (available.contains((row + 1) * 10 + col)) shootStack.push((row + 1) * 10 + col);
			if (available.contains((row - 1) * 10 + col)) shootStack.push((row - 1) * 10 + col);
			if (available.contains(row * 10 + col + 1)) shootStack.push(row * 10 + col + 1);
			if (available.contains(row * 10 + col - 1)) shootStack.push(row * 10 + col - 1);
		}
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


// ShootStack
int Board::ShootStack::operator[](int ind) {
	auto it = stack.begin();
	for (int i = 0; i != ind; ++i) ++it;
	return *it;
}

int Board::ShootStack::operator[](int ind) const {
	auto it = stack.begin();
	for (int i = 0; i != ind; ++i) ++it;
	return *it;
}

int Board::ShootStack::size() const {
	return (int)stack.size();
}

int Board::ShootStack::pop() {
	if (stack.empty()) return -1;
	int out = *(--stack.end());
	stack.erase(--stack.end());
	return out;
}

void Board::ShootStack::push(int cell) {
	if (cell < 0 || cell >= 100) return;
	if (stack.find(cell) == stack.end()) stack.insert(cell);
}

void Board::ShootStack::remove(int cell) {
	if (stack.find(cell) != stack.end()) stack.erase(stack.find(cell));
}

bool Board::ShootStack::contains(int cell) const {
	return stack.find(cell) != stack.end();
}

bool Board::ShootStack::empty() const {
	return stack.empty();
}