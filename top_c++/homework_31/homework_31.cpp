#include <iostream>

using namespace std;

void delZeroLines(int**, int&, int);

int main()
{
    srand(time(NULL));
    int size1 = 5, size2 = 5;
    int** arr = new int*[size1];

    for (int i = 0; i < size1; ++i) {
        arr[i] = new int[size2];
    }

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) arr[i][j] = rand() % 5;
    }

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    delZeroLines(arr, size1, size2);

    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) cout << arr[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < size1; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}


void delZeroLines(int** arr, int& size1, int size2) {
    bool zeroFound = false;
    for (int i = 0; i < size1; ++i) {
        zeroFound = false;
        for (int j = 0; j < size2; ++j) {
            if (zeroFound) break;
            if (arr[i][j] == 0) {
                delete[] arr[i];
                arr[i] = arr[size1 - 1];
                size1--;
                i--;
                zeroFound = true;
                break;
            }
        }
    }
}