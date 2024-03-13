#include <iostream>

using namespace std;

void task1();
void task2();
void task3();

int main()
{
    //task1();
    //task2();
    //task3();
}

void task1() {
    const int row = 5, col = 5;
    int arr[row][col];
    int curNum;
    cout << "Enter seed(first number) for 2D array: ";
    cin >> curNum;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = curNum;
            curNum *= 2;
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void task2() {
    const int row = 5, col = 5;
    int arr[row][col];
    int curNum;
    cout << "Enter seed(first number) for 2D array: ";
    cin >> curNum;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = curNum++;
        }
    }

    //print array
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) cout << arr[i][j] << "\t";
        cout << endl;
    }
}

void task3() {
    srand(time(0));
    const int row = 5, col = 5;
    int arr[row][col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = rand() % 10;
        }
    }

    //print array
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) cout << arr[i][j] << "\t";
        cout << endl;
    }

    int shiftDir, shiftAmount, rowShift = 0, colShift = 0;
    cout << "\nChoose the direction of the shift:\n1 - Up\n2 - Right\n3 - Down\n4 - Left\n";
    cin >> shiftDir;
    cout << "\nEnter the amount of steps to shift:\n";
    cin >> shiftAmount;

    switch (shiftDir) {
    case 1: rowShift += shiftAmount;
        break;
    case 2: colShift -= shiftAmount;
        break;
    case 3: rowShift -= shiftAmount;
        break;
    case 4: colShift += shiftAmount;
        break;
    }

    cout << "\nMoved matrix:\n";

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) cout << arr[(row + i + rowShift) % row][(col + j + colShift) % col] << "\t";
        cout << endl;
    }
}
