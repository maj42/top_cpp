#include <iostream>
#include "Board.h"

int main()
{
    Board brd("auto");
    Board otherBrd("auto");
    //std::cout << brd << std::endl;
    while (!(brd.destroyed || otherBrd.destroyed)) {
        printBoards(brd, otherBrd, true);
        std::cout << "Bot 1: ";
        otherBrd.botMove(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system(CLS);

        printBoards(brd, otherBrd, false);
        std::cout << "Bot 2: ";
        brd.humanMove();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        system(CLS);
    }
    std::cout << (brd.destroyed ? ("Bot2 won") : ("Bot1 won")) << std::endl;
}


// TODO
// 
// human move
// stop, pause