#include <iostream>

using namespace std;

int main()
{
    srand(time(0));
    const int arrSize = 20;
    int arr[arrSize];
    for (int i = 0; i < arrSize; ++i) arr[i] = (rand() % 100) - 50; // -50 - 49

    int negSum = 0, oddProd = 1, max = arr[0], minEven = arr[0], minAbs = abs(arr[0]);
    for (int i = 0; i < arrSize; ++i) {
        int curNum = arr[i];
        if (curNum < 0) negSum += curNum;
        if (i % 2) oddProd *= curNum;
        if (curNum > max) max = curNum;
        if (!(curNum % 2) && curNum < minEven) minEven = curNum;
        if (abs(curNum) < minAbs) minAbs = abs(curNum);
    }

    cout << "Array:\n";
    for (int i = 0; i < arrSize; ++i) cout << arr[i] << " ";
    cout << "\n1. Sum of all negatives: " << negSum;
    cout << "\n2. Product of numbers with odd index: " << oddProd;
    cout << "\n3. Max number: " << max;
    cout << "\n4. Min even number or (if none) first number: " << minEven;
    cout << "\n5. Min absolute number: " << minAbs;
}
