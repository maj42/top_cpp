#include <iostream>
#include "Board.h"
#include "conio.h"

const int turnLength = 2000;

void greetings(std::string greet) {
    for (int i = 0; i < greet.size(); ++i) {
        std::cout << greet[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    system(CLS);
}

void logo(std::string logoStr) {
    for (int i = 25; i != 12; --i) {
        std::cout << std::string(i, '\n');
        std::cout << "\t\t\t\t\t\t" << logoStr;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        if (i == 13) std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        system(CLS);
    }
}

bool ask(std::string query) {
    std::string choice;
    system(CLS);
    while (1) {
        std::cout << query;
        std::cin >> choice;
        if (choice.size() == 1) break;
        system(CLS);
        std::cout << "Invalid input" << std::endl;
    }
    switch (choice[0]) {
    case 'Y':
    case 'y':
    case '+':
        return true;
    default: return false;
    }
}

int main()
{
    bool play = true;
    while (play) {
        greetings("Greetings    \nAnd welcome    \nI want to play a game...");
        logo("SEA BATTLE!!!");

        bool humanPlayer = ask("Do you want to play yourself? Y/N: ");
        bool manualPlacement = false;
        if (humanPlayer) manualPlacement = ask("Do you want to build your board yourself? Y/N: ");
        bool bot1Smart = false;
        bool bot2Smart = false;
        if (!humanPlayer) bot1Smart = ask("Do you want first bot to be smart? Y/N: ");
        bot2Smart = ask("Do you want another bot to be smart? Y/N: ");

        Board brd1(manualPlacement ? "manual" : "auto");
        Board brd2("auto");

        system(CLS);
        std::cout << "Let the game begin!!!\n(Press space for pause menu while in-game)" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(turnLength));
        system(CLS);

        char input = '\n';
        while ((!(brd1.destroyed || brd2.destroyed)) && play) {
            printBoards(brd1, brd2, humanPlayer);
            std::cout << (humanPlayer ? ("You: ") : ("Bot 1: "));
            humanPlayer ? brd2.humanMove() : brd2.botMove(bot2Smart);
            std::this_thread::sleep_for(std::chrono::milliseconds(turnLength));
            system(CLS);

            printBoards(brd1, brd2, humanPlayer);
            std::cout << (humanPlayer ? ("Bot: ") : ("Bot 2: "));
            brd1.botMove(bot1Smart);
            std::this_thread::sleep_for(std::chrono::milliseconds(turnLength));
            system(CLS);
            
            if (_kbhit() && _getch() == ' ') {
                char ch;
                printBoards(brd1, brd2, humanPlayer);
                std::cout << "Game paused. Press any key to continue.\nPress e for exit.\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(turnLength));
                ch = _getch();
                switch (ch) {
                case 'e':
                    play = false;
                    break;
                default:
                    break;
                }
                system(CLS);
            }

        }
        if (play) std::cout << (brd1.destroyed ? (humanPlayer ? ("Bot won") : ("Bot 2 won")) : (humanPlayer ? ("You won!") : ("Bot1 won"))) << std::endl;
        play = ask("Do you want to play again? Y/N: ");
    }
}