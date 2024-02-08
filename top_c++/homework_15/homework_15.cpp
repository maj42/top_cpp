#include <iostream>

using namespace std;

int*** create3DArray(size_t);
void fill3DArr(int***, size_t);
void print3DArr(int***, size_t);
void clear3DArr(int***, size_t);

int main()
{
    int*** arr3D = create3DArray(3);
    fill3DArr(arr3D, 3);
    print3DArr(arr3D, 3);
    clear3DArr(arr3D, 3);
    print3DArr(arr3D, 3);
}

int*** create3DArray(size_t size) {
    int*** arr = new int** [size] {};
    for (int i = 0; i < size; i++) {
        arr[i] = new int* [size] {};
        for (int j = 0; j < size; j++) {
            arr[i][j] = new int [size] {};
        }
    }
    return arr;
}

void fill3DArr(int*** arr, size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) arr[i][j][k] = (i * 3 * 3) + (j * 3) + k + 1;
        }
    }
}

void print3DArr(int*** arr, size_t size) {
    if (!arr) return;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) cout << arr[i][j][k] << "\t";
            cout << endl;
        }
        cout << "\n\n";
    }
}

void clear3DArr(int*** arr, size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            delete[] arr[i][j];
            arr[i][j] = 0;
        }
        delete[] arr[i];
        arr[i] = 0;
    }
    delete[] arr;
    arr = 0;
}