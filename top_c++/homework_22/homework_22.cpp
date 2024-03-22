#include <iostream>

using namespace std;

void task1();
void task2();

int main()
{
    srand(time(0));
    //task1();
    task2();
}

void task1() {
    int arr[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) arr[i][j] = rand() % 2;
    }

    int zeroes = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!arr[i][j]) zeroes++;
        }
    }
    cout << "Zeroes in array: " << zeroes << endl;
}

void task2() {
    const int size = 10;
    int mat[size][size];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) mat[i][j] = rand() % 100;
    }

    //a
    int max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j >= i && mat[i][j] > max) max = mat[i][j];
            if (j >= i) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\na: " << max << "\n\n";

    //b
    max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (j <= i && mat[i][j] > max) max = mat[i][j];
            if (j <= i) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\nb: " << max << "\n\n";

    //c
    max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((j >= i && j <= size - 1 - i) && mat[i][j] > max) max = mat[i][j];
            if (j >= i && j <= size - 1 - i) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\nc: " << max << "\n\n";

    //d
    max = mat[size - 1][size - 1];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((j <= i && j >= size - 1 - i) && mat[i][j] > max) max = mat[i][j];
            if (j <= i && j >= size - 1 - i) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\nd: " << max << "\n\n";
    //e
    max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (((j >= i && j <= size - 1 - i) || (j <= i && j >= size - 1 - i)) && mat[i][j] > max) max = mat[i][j];
            if ((j >= i && j <= size - 1 - i) || (j <= i && j >= size - 1 - i)) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\ne: " << max << "\n\n";

    //f
    max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (((i >= j && i <= size - 1 - j) || (i <= j && i >= size - 1 - j)) && mat[i][j] > max) max = mat[i][j];
            if ((i >= j && i <= size - 1 - j) || (i <= j && i >= size - 1 - j)) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\nf: " << max << "\n\n";

    //g
    max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i >= j && i <= size - 1 - j) && mat[i][j] > max) max = mat[i][j];
            if (i >= j && i <= size - 1 - j) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\ng: " << max << "\n\n";

    //h
    max = mat[size - 1][size - 1];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if ((i <= j && i >= size - 1 - j) && mat[i][j] > max) max = mat[i][j];
            if (i <= j && i >= size - 1 - j) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\nh: " << max << "\n\n";
    //i
    max = mat[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i + j < size && mat[i][j] > max) max = mat[i][j];
            if (i + j < size) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\ni: " << max << "\n\n";

    //j
    max = mat[size - 1][size - 1];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i + j > size - 2 && mat[i][j] > max) max = mat[i][j];
            if (i + j > size - 2) cout << mat[i][j] << "\t";
            else cout << "x\t";
        }
        cout << endl;
    }
    cout << "\nj: " << max << "\n\n";
}