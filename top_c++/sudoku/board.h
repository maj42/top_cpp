#pragma once
class Board
{
	char* grid;
public:
	Board();
	Board& randFill();
	Board& move(char where, char num);
	bool checkForWin();

	friend std::ostream& operator<< (std::ostream&, Board&);
};

std::ostream& operator<< (std::ostream& str, Board& brd);

