#include <iostream>

using namespace std;

void showArray(int*, int);

int main()
{
    srand(unsigned(time(0)));
    const int size = 10;
    int arr[size], zeroes = 0;
    for (int i = 0; i < size; i++) arr[i] = (rand() % 3);
    showArray(arr, size);

    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            arr[i - zeroes] = arr[i];
        }
        else zeroes++;
    }
    for (int i = size - zeroes; i < size; i++) arr[i] = -1;

    showArray(arr, size);
}

void showArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}