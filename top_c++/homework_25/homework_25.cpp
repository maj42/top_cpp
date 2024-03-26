#include <iostream>

using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int calc(int&, int&, char);

int main()
{
    //task1();
    //task2();
    //task3();
    //task4();
    task5();
}

void task1() {
    const int size = 5;
    int arr1[size]{ 1, 2, 3, 4, 5 };
    int arr2[size]{};

    int* ptr1 = arr1;
    int* ptr2 = arr2;

    for (int i = 0; i < size; ++i) {
        *ptr2++ = *ptr1++;
        cout << arr2[i] << " ";
    }
    cout << endl;
}

void task2() {
    const int size = 5;
    int arr[size]{ 1, 2, 3, 4, 5 };
    int* ptr = arr;
    int* rPtr = ptr + (size - 1);
    int temp;

    for (int i = 0; i < size / 2; ++i) {
        temp = *rPtr;
        *rPtr-- = *ptr;
        *ptr++ = temp;
    }

    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

void task3() {
    const int size = 5;
    int arr1[size]{ 1, 2, 3, 4, 5 };
    int arr2[size]{};

    int* ptr1 = arr1;
    int* ptr2 = arr2 + (size - 1);

    for (int i = 0; i < size; ++i) {
        *ptr2-- = *ptr1++;
    }

    for (int i = 0; i < size; ++i) cout << arr2[i] << " ";
    cout << endl;
}

void task4() {
    int x = 5, y = 6;
    cout << calc(x, y, '+') << endl;
    cout << calc(x, y, '-') << endl;
    cout << calc(x, y, '*') << endl;
    cout << calc(x, y, '$') << endl;
}


void task5() {
    const int size = 5;
    int arr[size]{ 1, 2, 3, 4, 5 };
    int* ptr = arr;
    int sum = 0;

    for (int i = 0; i < size; ++i) sum += *ptr++;

    cout << sum << endl;
}

int calc(int& x, int& y, char ch) {
    switch (ch) {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    default: return -1000000;
    }
}