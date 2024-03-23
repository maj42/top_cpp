#include <iostream>

using namespace std;

void task1();
void task2();
void task3();

float power(float, int);
int* reverse(int*, int);
bool happy(int num);

int main()
{
    //task1();
    //task2();
    //task3();
}

void task1() {
    cout << power(3.3, 3) << endl;
}

void task2() {
    const int size = 5;
    int arr[size]{ 1, 2, 3, 4, 5 };
    
    for (int i = 0; i < size; ++i) cout << arr[i] << ' ';
    cout << endl;
    reverse(arr, size);
    for (int i = 0; i < size; ++i) cout << arr[i] << ' ';
    cout << endl;
}

void task3() {
    cout << boolalpha << happy(254317) << endl;
    cout << boolalpha << happy(111234) << endl;
}

float power(float num, int power) {
    float result = 1;
    for (int i = 0; i < power; ++i) result *= (float)num;
    return result;
}

int* reverse(int* arr, int size) {
    int temp;
    for (int i = 0; i < size / 2; ++i) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    return arr;
}

bool happy(int num) {
    int firstHalf = 0, lastHalf = 0, curNum;
    for (int i = 0; i < 6; ++i) {
        curNum = num % 10;
        num /= 10;
        i > 2 ? firstHalf += curNum : lastHalf += curNum;
    }
    return firstHalf == lastHalf;
}