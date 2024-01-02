#include <iostream>

using namespace std;

void task1NumCheck();
void task2Checkboard();
void task3MultipleOrder();
void task4SeaBattleField();

int main()
{
    int choice;
    do {
        cout << "Enter your choice:\n1 - Number of digits in a number,sum and average of them\n2 - Print checkboard as * and -\n\
3 - Place an order for several people\n4 - Print a Sea Battle battlefield\n";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    switch (choice) {
    case 1:
        cout << "Number of digits in a number,sum and average of them:\n";
        task1NumCheck();
        break;
    case 2:
        cout << "\nPrint checkboard as * and -:\n";
        task2Checkboard();
        break;
    case 3:
        cout << "\nPlace an order for several people:\n";
        task3MultipleOrder();
        break;
    case 4:
        cout << "\nPrint a Sea Battle battlefield:\n";
        task4SeaBattleField();
        break;
    }
}

void task1NumCheck() {
    int num, digit = 0, digits = 0, sum = 0, zeroes = 0;
    cout << "Enter number: ";
    cin >> num;
    while (num) {
        digits++;
        digit = num % 10;
        if (not digit) zeroes++;
        sum += digit;
        num /= 10;
    }
    cout << "Number has " << digits << " digits, " << zeroes << " of them - 0.\nSum of its digits is " << sum << ", average is " << (double)sum / digits << endl;
}

void task2Checkboard() {
    int cellSize;
    const char fillers[2] = {'*', '-'};
    const char cellVert[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    cout << "Enter the size of the single cell: ";
    cin >> cellSize;
    for (int row = 9; row > 0; row--) {
        if (row == 9) {
            cout << "\t";
            for (int cellName = 0; cellName < 8; cellName++) cout << cellVert[cellName] << "\t";
            cout << "\n\n";
            continue;
        }
        cout << row << "\t";
        for (int subRow = 0; subRow < cellSize; subRow++) {
            if (subRow != 0) cout << "\t";
            for (int column = 0; column < 8; column++) {
                string cell(cellSize, fillers[row % 2]);
                cout << cell << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void task3MultipleOrder() {
    int persons;
    cout << "How many persons in order? ";
    cin >> persons;
    double orderTotal, ordersTotal = 0;
    for (int person = 0; person < persons; person++) {
        orderTotal = 0;
        while (true) {
            int choice;
            cout << "Person " << person + 1 << ", what do you want to order?" << endl;
            cout << "1 - Burger $3.99\n2 - Fryes $1.99\n3 - Cola $1.55\n4 - Coffee $2.99" << endl;
            cout << "Your order: $" << orderTotal << "\nTotal order: $" << ordersTotal << endl;
            cout << "Press any other button for next person order or exit\n";
            cin >> choice;
            if (choice < 1 || choice > 4) break;
            switch (choice) {
            case 1:
                orderTotal += 3.99;
                ordersTotal += 3.99;
                break;
            case 2:
                orderTotal += 1.99;
                ordersTotal += 1.99;
                break;
            case 3:
                orderTotal += 1.55;
                ordersTotal += 1.55;
                break;
            case 4:
                orderTotal += 2.99;
                ordersTotal += 2.99;
                break;
            }
        }
    }
    cout << "TOTAL: $" << ordersTotal << endl;
}

void task4SeaBattleField() {
    const char cellColumn[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    for (int row = 0; row < 10; row++) {
        if (row == 0) {
            cout << "\t";
            for (int i = 0; i < 10; i++) cout << cellColumn[i] << "\t";
            cout << "\n\n";
        }
        for (int col = 0; col < 10; col++) {
            if (col == 0) cout << row << "\t";
            cout << cellColumn[col] << row << "\t";
        }
        cout << "\n\n";
    }
}