#include <iostream>
#include <thread>
#include "Board.h"
#define CLS "cls"

#if defined(__linux__)
#define CLS "clear"
#endif

int main()
{
    Board brd("auto");
    Board otherBrd("auto");
    //std::cout << brd << std::endl;
    while (!(brd.destroyed || otherBrd.destroyed)) {
        printBoards(brd, otherBrd, false);
        std::cout << "Bot 1: ";
        otherBrd.botMove();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system(CLS);

        printBoards(brd, otherBrd, false);
        std::cout << "Bot 2: ";
        brd.botMove();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system(CLS);
    }
    std::cout << (brd.destroyed ? ("Bot2 won") : ("Bot1 won")) << std::endl;
}


// TODO
// 
// bot strategy
// manual placement
// human move
// stop, pause
// 
// debug: concecutive ships