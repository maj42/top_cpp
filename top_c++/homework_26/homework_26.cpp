#include <iostream>

using namespace std;

void task1();
void task2();

int* isSubset(int*, int*, int, int);
int* delNeg(int*, int, int&);

int main()
{
    //task1();
    //task2();
}

void task1() {
    int A[] { 1, 2, 3, 4, 5 }, B[] { 4, 5 };
    int sizeA = sizeof(A) / sizeof(int);
    int sizeB = sizeof(B) / sizeof(int);

    cout << isSubset(A, B, sizeA, sizeB);
}

void task2() {
    int size = 5, newSize = size;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) arr[i] = pow(-1, i);

    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    int* newArr = delNeg(arr, size, newSize);
    cout << endl;
    for (int i = 0; i < newSize; ++i) cout << newArr[i] << " ";

    delete[] arr;
    arr = nullptr;
}

int* isSubset(int* A, int* B, int sizeA, int sizeB) {
    bool notFound;
    int start = 0;
    for (int i = 0; i < sizeB; ++i) {
        notFound = true;
        for (int j = 0; j < sizeA; ++j) {
            if (B[i] == A[j]) {
                if (!start) start = A[j];
                notFound = false;
                continue;
            }
        }
        if (notFound) return 0;
    }
    int* startP = A + start;
    return startP;
}

int* delNeg(int* arr, int sizeOrig, int& size) {
    int* newArr = new int[size];
    for (int i = 0, j = 0; i < sizeOrig; ++i) {
        if (arr[i] > 0) newArr[j++] = arr[i];
        else size--;
    }
    return newArr;
}