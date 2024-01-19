#include <iostream>

using namespace std;

void printMatrix(int**, int, int);
void fillMatrix(int**, int, int);
int** removeRowsWithZero(int** matrix, int&, int);

void main()
{
    int rows = 3;
    int columns = 4;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[columns] {};
    }

    srand((unsigned)time(0));

    fillMatrix(matrix, rows, columns);
    printMatrix(matrix, rows, columns);
    matrix = removeRowsWithZero(matrix, rows, columns);
    printMatrix(matrix, rows, columns);
}

void printMatrix(int** matrix, int rows, int columns) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << matrix[r][c] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void fillMatrix(int** matrix, int rows, int columns) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            matrix[r][c] = rand() % 5;
        }
        cout << endl;
    }
}

int** removeRowsWithZero(int** matrix, int& row, int column) {
    bool* nullRows = new bool[row] {};
    int deletedRows = 0;
    for (int r = 0; r < row; r++) {
        bool isNull = false;
        for (int c = 0; c < column; c++) {
            if (matrix[r][c] == 0) {
                isNull = true;
                break;
            }
        }
        if (isNull) {
            nullRows[r] = true;
            deletedRows++;
        }
    }
    int** resultMatrix = new int* [row - deletedRows];
    int index = 0;
    for (int r = 0; r < row; r++) {
        if (nullRows[r]) delete[] matrix[r];
        else resultMatrix[index++] = matrix[r];
        
    }
    row -= deletedRows;
    delete[] matrix;
    return resultMatrix;
}