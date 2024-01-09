#include <iostream>

using namespace std;

void printArrays(int*, int*, int);

int main()
{
    const int arrSize = 5;
    int origArr[arrSize]{1, 2, 3, 4, 5};
    int copyArr[arrSize]{};

    printArrays(origArr, copyArr, arrSize);
    
    for (int i = 0; i < arrSize; i++) {
        *(copyArr + i) = *(origArr + i);
    }

    printArrays(origArr, copyArr, arrSize);
}

void printArrays(int* arr1, int* arr2, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << *(arr1 + i) << "\t";
    }
    cout << endl;
    for (int i = 0; i < arrSize; i++) {
        cout << *(arr2 + i) << "\t";
    }
    cout << endl << endl;
}