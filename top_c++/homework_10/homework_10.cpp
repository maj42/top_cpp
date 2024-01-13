#include <iostream>

using namespace std;

void task1();
void task2();
void task3();

void copyVariable(int*, int*);
void print(int*, int);
void copyArray(int*, int*, int);
void printMatrix(int(*mat)[3]);
void copyMatrix(int(*mat1)[3], int(*mat2)[3]);

int main()
{
    //task1();
    //task2();
    //task3();
}

void task1() {
    int a = 4;
    int b = 7;
    cout << "a = " << a << "\nb = " << b << endl;
    copyVariable(&a, &b);
    cout << "a = " << a << "\nb = " << b << endl;
}

void task2() {
    const int size = 5;
    int arr1[size] = { 1, 3, 5, 7, 9 };
    int arr2[size] = { 0 };
    print(arr1, size);
    print(arr2, size);
    copyArray(arr1, arr2, size);
    print(arr1, size);
    print(arr2, size);
}

void task3() {
    const int size = 3;
    int mat1[size][size] = { {3, 2, 1}, {6,5,4}, {9,8,7} };
    int mat2[size][size] = {};

    printMatrix(mat1);
    printMatrix(mat2);
    copyMatrix(mat1, mat2);
    printMatrix(mat2);
}

void copyVariable(int* var1, int* var2) {
    *var2 = *var1;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int* arr1, int* arr2, int size) {
    for (int i = 0; i < size; i++) *(arr2 + i) = *(arr1 + i);
}

void printMatrix(int(*mat)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void copyMatrix(int(*mat1)[3], int(*mat2)[3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mat2[i][j] = mat1[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
