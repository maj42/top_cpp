#include "board.h"
#include <fstream>
#include <iomanip>
#include <bitset>

Board::Board() {
	char grid[81];
	boardState = 0; // 0-8 rows 9-17 cols 18-26 cells
	_randFill();
}

Board& Board::_randFill() {
	srand(time(0));
	int gridPos = DEBUG ? 0 : ((rand() % STARTING_GRIDS) + 1);
	std::fstream file{ "starting_grids.txt", std::ios::in };
	if (file) {
		file.seekp(83 * gridPos, std::ios_base::beg);
		file.read(grid, 81);
	}
	file.close();
	for (int i = 0; i < 81; ++i) {
		if (grid[i] != '0') startingFill.insert(i);
	}
	this->_checkState();
	return *this;
}

char Board::_parseNum(std::string& str) const {
	char num;
	if (str.length() != 1) return -1;
	if (str[0] < '1' || str[0] > '9') {
		return -1;
	}
	return str[0];
}

char Board::_parseCell(std::string& str) const {
	if (str.length() != 2) return -1;
	if ((str[0] >= '1' && str[0] <= '9') && ((str[1] >= 'a' && str[1] < 'j') || (str[1] >= 'A' && str[1] < 'J'))) {
		const char first = str[0];
		const char second = str[1];
		str.clear();
		str += toascii(second);
		str += toascii(first);
	}
	if (((str[0] >= 'a' && str[0] < 'j') || (str[0] >= 'A' && str[0] < 'J')) && (str[1] >= '1' && str[1] <= '9')) {
		if (str[0] < 'a') return static_cast<int> (str[0] - 'A') * 9 + static_cast<int> (str[1] - '1');
		else return static_cast<int> (str[0] - 'a') * 9 + static_cast<int> (str[1] - '1');
	}
	return -1;
}

Board& Board::move(std::string where, std::string num) {
	int moveCell = _parseCell(where);
	char moveNum = _parseNum(num);
	if (moveCell == -1) {
		std::cout << "Not a valid cell address!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	else if (startingFill.find(moveCell) != startingFill.end()) {
		std::cout << "This cell can't be changed!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	else if (moveNum == -1) {
		std::cout << "Not a valid number!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	else {
		std::cout << "Move cell: " << moveCell << " Move num: " << moveNum << std::endl;
		grid[moveCell] = moveNum;
		_checkState();
	}
	return *this;
}

void Board::_checkState() {
	static int cellsStartX[9]{0, 0, 0, 3, 3, 3, 6, 6, 6};
	static int cellsStartY[9]{0, 3, 6, 0, 3, 6, 0, 3, 6};
	boardState = 0;

	// row check
	for (int row = 0; row < 9; ++row) {
		std::set<char> rowSet;
		int rowSum = 0;
		for (int col = 0; col < 9; ++col) {
			if (grid[row * 9 + col] != '0') rowSet.insert(grid[row * 9 + col]);
			rowSum += grid[row * 9 + col] - '0';
		}
		if (DEBUG) std::cout << "Row: " << row << " RowSet size: " << rowSet.size() << " Row sum: " << rowSum << std::endl;
		if (rowSet.size() == 9 && rowSum == 45) boardState += pow(2, row);
	}
	std::cout << std::endl;

	// col check
	for (int col = 0; col < 9; ++col) {
		std::set<char> colSet;
		int colSum = 0;
		for (int row = 0; row < 9; ++row) {
			colSet.insert(grid[row * 9 + col]);
			colSum += grid[row * 9 + col] - '0';
		}
		if (DEBUG) std::cout << "Col: " << col + 9 << " ColSet size: " << colSet.size() << " Col sum: " << colSum << std::endl;
		if (colSet.size() == 9 && colSum == 45) boardState += pow(2, col + 9);
	}
	std::cout << std::endl;

	// cells check
	for (int cell = 0; cell < 9; ++cell) {
		std::set<char> cellSet;
		int cellSum = 0;
		for (int cellRow = cellsStartX[cell]; cellRow < cellsStartX[cell] + 3; ++cellRow) {
			for (int cellCol = cellsStartY[cell]; cellCol < cellsStartY[cell] + 3; ++cellCol) {
				cellSet.insert(grid[cellRow * 9 + cellCol]);
				cellSum += grid[cellRow * 9 + cellCol] - '0';
			}
		}
		if (DEBUG) std::cout << "Cell: " << cell + 18 << " CellSet size: " << cellSet.size() << " Cell sum: " << cellSum << std::endl;
		if (cellSet.size() == 9 && cellSum == 45) boardState += pow(2, cell + 18);
	}
	std::cout << std::endl;
	std::cout << std::bitset<27>(boardState) << "\n\n";
}

bool Board::_checkRowStatus(int row) const {
	if (row < 0 || row > 9) return false;
	if ((boardState >> row) & 0b1) return true;
	else return false;
}

bool Board::_checkColStatus(int col) const {
	if (col < 0 || col > 9) return false;
	if ((boardState >> (col + 9)) & 0b1) return true;
	else return false;
}

bool Board::_checkCellStatus(int cell) const {
	if (cell < 0 || cell > 9) return false;
	if ((boardState >> (cell + 18)) & 0b1) return true;
	else return false;
}

bool Board::checkWin() const {
	return boardState == 134217727; // 111111111 111111111 111111111
}

std::ostream& operator<< (std::ostream& str, Board& brd) {
	if (!DEBUG) system("cls");
	str << "      1    2    3     4    5    6     7    8    9" << "\n";
	for (int row = 0; row < 9; ++row) {
		if (!(row % 3)) {
			str << "   | " << std::string(45, '-') << " |\n";
			str << "   |\t\t   |\t\t   |\t\t   |\n";
		}
		str << std::setw(2) << char(row + 'A') << " ";
		for (int col = 0; col < 9; ++col) {
			str << ((col % 3) ? "" : "|");
			str << "  ";
			str << (brd.grid[row * 9 + col] == '0' ? ' ' : brd.grid[row * 9 + col]);
			str << "  ";
		}
		str << "|";
		if (row == 1) {
			str << "\tCompleted:\n";
		}
		else if (row == 2) {
			str << "\t\t1  2  3  4  5  6  7  8  9\n";
		}
		else if (row == 3) {
			str << "\tRows:\t";
			for (int i = 0; i < 9; ++i) {
				str << (brd._checkRowStatus(i) ? "OK" : "  ") << " ";
			}
			str << "\n";
		}
		else if (row == 4) {
			str << "\tCols:\t";
			for (int i = 0; i < 9; ++i) {
				str << (brd._checkColStatus(i) ? "OK" : "  ") << " ";
			}
			str << "\n";
		}
		else if (row == 5) {
			str << "\tCells:\t";
			for (int i = 0; i < 9; ++i) {
				str << (brd._checkCellStatus(i) ? "OK" : "  ") << " ";
			}
			str << "\n";
		}
		else str << "\n";
		str << "   |\t\t   |\t\t   |\t\t   |\n";
	}
	str << "   | " << std::string(45, '-') << " |\n";
	return str;
}