#include <iostream>

using namespace std;

void task1();

int main()
{
    srand(time(NULL));
    task1();
}

void task1() {
    int* arr;
    int size;
    cout << "Enter array size:" << endl;
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; ++i) arr[i] = (rand() % 4) + 2;

    int choice;
    cout << "Delete evens(0) or odds(1) from array?" << endl;
    cin >> choice;

    cout << "Old array:" << endl;
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;

    int* newArr = new int[size];
    int newSize = 0;

    for (int i = 0, j = 0; i < size; ++i) {
        if ((!choice && arr[i] % 2) || (choice && !(arr[i] % 2))) {
            newArr[j++] = arr[i];
            newSize++;
        }
    }

    arr = newArr;
    size = newSize;

    cout << "New array:" << endl;
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
}