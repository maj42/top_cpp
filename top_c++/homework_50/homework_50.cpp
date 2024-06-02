#include <iostream>

using namespace std;

int throwDice();
void showDice(int dice);

int main()
{
    //Написать игру в которой имитируется бросание кубиков компьютером и пользователем.
    //В игре 2 кубика и на каждом из них может выпасть от 1 до 6 очков.
    //Реализовать определение программой первого ходящего.Каждый делает по четыре броска.
    //После бросков показать, нарисованные символами кубики и количество очков, выпавших на них.
    //После  пары бросков(бросок компьютера + бросок пользователя) выводить на экран промежуточный результат 
    //– количество набранных очков игроком и компьютером.В конце сообщить о том, кто выиграл по итогам всех бросков.

    srand(time(0));
    const int turns = 4, throws = 2;
    int dicesPlayer[turns][throws], dicesComp[turns][throws];
    int  totalPlayer = 0, totalComp = 0;
    int turnOrder = rand() % 2;

    for (int turn = 0; turn < turns; ++turn) {
        system("cls");
        cout << "\nTurn " << turn + 1 << endl;
        cout << "Total for you: " << totalPlayer << "\nTotal for computer: " << totalComp << endl;
        if (turnOrder) {
            cout << "Computer's turn: " << endl;
            for (int throw_ = 0; throw_ < throws; ++throw_) {
                dicesComp[turn][throw_] = throwDice();
                showDice(dicesComp[turn][throw_]);
                totalComp += dicesComp[turn][throw_];
            }
        }

        cout << "Your turn, throw the dice: ";
        cin.get();
        for (int throw_ = 0; throw_ < throws; ++throw_) {
            dicesPlayer[turn][throw_] = throwDice();
            showDice(dicesPlayer[turn][throw_]);
            totalPlayer += dicesPlayer[turn][throw_];
        }

        if (!turnOrder) {
            cout << "Computer's turn: " << endl;
            for (int throw_ = 0; throw_ < throws; ++throw_) {
                dicesComp[turn][throw_] = throwDice();
                showDice(dicesComp[turn][throw_]);
                totalComp += dicesComp[turn][throw_];
            }
        }
        cout << "Press any key for next turn";
        cin.get();
    }

    system("cls");
    cout << "\nTotal for you: " << totalPlayer << "\nTotal for computer: " << totalComp << endl;
    totalPlayer >= totalComp ? cout << "You won!" << endl : cout << "Computer won!" << endl;
}

int throwDice() {
    return rand() % 6 + 1;
}

void showDice(int dice) {
    int diceRow = 5, diceCol = 7;
    cout << endl;
    switch (dice) {
    case 1:
        for (int i = 0; i < diceRow; ++i) {
            for (int j = 0; j < diceCol; ++j) {
                if ((i == 0 && j == 0) || (i == diceRow - 1 && j == diceCol - 1)) cout << '/';
                else if ((i == 0 && j == diceCol - 1) || (i == diceRow - 1 && j == 0)) cout << '\\';
                else if (j == 0 || j == diceCol - 1) cout << '|';
                else if (i == 0 || i == diceRow - 1) cout << '-';
                // numbers start
                else if (i == diceRow / 2 && j == diceCol / 2) cout << '*';
                // numbers end
                else cout << ' ';
            }
            cout << endl;
        }
        break;

    case 2:
        for (int i = 0; i < diceRow; ++i) {
            for (int j = 0; j < diceCol; ++j) {
                if ((i == 0 && j == 0) || (i == diceRow - 1 && j == diceCol - 1)) cout << '/';
                else if ((i == 0 && j == diceCol - 1) || (i == diceRow - 1 && j == 0)) cout << '\\';
                else if (j == 0 || j == diceCol - 1) cout << '|';
                else if (i == 0 || i == diceRow - 1) cout << '-';
                // numbers start
                else if (i == diceRow / 2 && ((j == diceCol / 2 - diceCol / 3) || (j == diceCol / 2 + diceCol / 3))) cout << '*';
                // numbers end
                else cout << ' ';
            }
            cout << endl;
        }
        break;

    case 3:
        for (int i = 0; i < diceRow; ++i) {
            for (int j = 0; j < diceCol; ++j) {
                if ((i == 0 && j == 0) || (i == diceRow - 1 && j == diceCol - 1)) cout << '/';
                else if ((i == 0 && j == diceCol - 1) || (i == diceRow - 1 && j == 0)) cout << '\\';
                else if (j == 0 || j == diceCol - 1) cout << '|';
                else if (i == 0 || i == diceRow - 1) cout << '-';
                // numbers start
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 && j == diceCol / 2) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                // numbers end
                else cout << ' ';
            }
            cout << endl;
        }
        break;

    case 4:
        for (int i = 0; i < diceRow; ++i) {
            for (int j = 0; j < diceCol; ++j) {
                if ((i == 0 && j == 0) || (i == diceRow - 1 && j == diceCol - 1)) cout << '/';
                else if ((i == 0 && j == diceCol - 1) || (i == diceRow - 1 && j == 0)) cout << '\\';
                else if (j == 0 || j == diceCol - 1) cout << '|';
                else if (i == 0 || i == diceRow - 1) cout << '-';
                // numbers start
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                // numbers end
                else cout << ' ';
            }
            cout << endl;
        }
        break;

    case 5:
        for (int i = 0; i < diceRow; ++i) {
            for (int j = 0; j < diceCol; ++j) {
                if ((i == 0 && j == 0) || (i == diceRow - 1 && j == diceCol - 1)) cout << '/';
                else if ((i == 0 && j == diceCol - 1) || (i == diceRow - 1 && j == 0)) cout << '\\';
                else if (j == 0 || j == diceCol - 1) cout << '|';
                else if (i == 0 || i == diceRow - 1) cout << '-';
                // numbers start
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                else if (i == diceRow / 2 && j == diceCol / 2) cout << '*';

                // numbers end
                else cout << ' ';
            }
            cout << endl;
        }
        break;

    case 6:
        for (int i = 0; i < diceRow; ++i) {
            for (int j = 0; j < diceCol; ++j) {
                if ((i == 0 && j == 0) || (i == diceRow - 1 && j == diceCol - 1)) cout << '/';
                else if ((i == 0 && j == diceCol - 1) || (i == diceRow - 1 && j == 0)) cout << '\\';
                else if (j == 0 || j == diceCol - 1) cout << '|';
                else if (i == 0 || i == diceRow - 1) cout << '-';
                // numbers start
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 - diceCol / 3) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2 + diceCol / 3) cout << '*';
                else if (i == diceRow / 2 - diceRow / 3 && j == diceCol / 2) cout << '*';
                else if (i == diceRow / 2 + diceRow / 3 && j == diceCol / 2) cout << '*';
                // numbers end
                else cout << ' ';
            }
            cout << endl;
        }
        break;
    }
    cout << endl;
}