#include "board.h"

int main()
{
    std::cout << "Welcome to Sudoku!" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Board brd{};
    bool play = true;
    std::string moveCell;
    std::string num;

    while (play) {
        std::cout << brd;
        std::cout << "Please make a move. Choose a cell: ";
        std::cin >> moveCell;
        std::cout << "\nChoose a number: ";
        std::cin >> num;
        brd.move(moveCell, num);

        if (brd.checkWin()) {
            system("cls");
            std::cout << "You're won!" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(4000));
            play = false;
        }
    }
    system("cls");
    std::cout << "Thanks for playing!" << std::endl;
}
