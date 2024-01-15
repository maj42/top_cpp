#include <iostream>

using namespace std;

void sumAndProdFromArr(int*, int, int&, int&);

int main()
{
    const int size = 6;
    int sum = 0, prod = 1;
    int arr[size]{ 1, 2, 3, 4, 5, 6 };
    sumAndProdFromArr(arr, size, sum, prod);
    cout << "Array sum = " << sum << "\nArray product = " << prod << endl;
}

void sumAndProdFromArr(int* arr, int size, int& sum, int& prod) {
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        prod *= arr[i];
    }
}