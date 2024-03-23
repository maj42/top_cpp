#include <iostream>

using namespace std;

void task1();
void task2();
void task3();
void task4();

int throwDice();
void showDice(int);
int factorial(int);
bool isPrime(int);

int main()
{
    srand(time(0));
    //task1();
    //task2();
    //task3();
    //task4();
}

void task1() {
    const int turns = 5, throws = 2;
    int dicesPlayer[turns][throws], dicesComp[turns][throws];
    float averPlayer = 0, averComp = 0;
    int turnOrder = rand() % 2;
    
    for (int turn = 0; turn < turns; ++turn) {
        cout << "\nTurn " << turn + 1 << endl;
        if (turnOrder) {
            cout << "Computer's turn: " << endl;
            for (int throw_ = 0; throw_ < throws; ++throw_) {
                dicesComp[turn][throw_] = throwDice();
                showDice(dicesComp[turn][throw_]);
                averComp += dicesComp[turn][throw_];
            }
        }

        cout << "Your turn, throw the dice: ";
        cin.get();
        for (int throw_ = 0; throw_ < throws; ++throw_) {
            dicesPlayer[turn][throw_] = throwDice();
            showDice(dicesPlayer[turn][throw_]);
            averPlayer += dicesPlayer[turn][throw_];
        }

        if (!turnOrder) {
            cout << "Computer's turn: " << endl;
            for (int throw_ = 0; throw_ < throws; ++throw_) {
                dicesComp[turn][throw_] = throwDice();
                showDice(dicesComp[turn][throw_]);
                averComp += dicesComp[turn][throw_];
            }
        }
    }

    averPlayer /= float(turns * throws);
    averComp /= float(turns * throws);
    cout << "\nAverage for you: " << averPlayer << "\nAverage for computer: " << averComp << endl;
    averPlayer >= averComp ? cout << "You won!" << endl : cout << "Computer won!" << endl;
}

void task2() {
    int N = 10, K = 20;
    for (int n = 0; n < N; ++n) {
        for (int k = 0; k < K; ++k) {
            if (n == 0 || n == N - 1) cout << " - ";
            else if (k == 0) cout << '|';
            else if (k == K - 1) cout << "   |";
            else cout << "   ";
        }
        cout << endl;
    }
}

void task3() {
    cout << factorial(5) << endl;
}

void task4() {
    cout << boolalpha << isPrime(10) << endl;
    cout << boolalpha << isPrime(15485863) << endl;
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

int factorial(int num) {
    if (num == 1) return 1;
    return factorial(num - 1) * num;
}

bool isPrime(int num) {
    if (num <= 1) return false;

    for (int n = 2; n <= sqrt(num); ++n) {
        if (num % n == 0) return false;
    }

    return true;
}