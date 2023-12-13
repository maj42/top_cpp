#include <iostream>

using namespace std;

int* getArray(int arrayLength, int min, int max);
void task1MinMaxInArray();
void task2SumNumsLessThan();
void task3BusinessIncome();
void task4FloatArray();

int main()
{
    int choice;
    do {
        cout << "Enter your choice:\n1 - Get min and max number from array\n2 - Get sum of numbers less than given from array\n\
3 - Calculate business income for a range of months\n4 - Float point numbers array and operations with it\n";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    switch (choice) {
    case 1:
        cout << "Array with its min and max:\n";
        task1MinMaxInArray();
        break;
    case 2:
        cout << "\nArray with sum of its nums less than given:\n";
        task2SumNumsLessThan();
        break;
    case 3:
        cout << "\nBusiness income array with min and max in given range:\n";
        task3BusinessIncome();
        break;
    case 4:
        cout << "\nFloat point numbers array and operations with it:\n";
        task4FloatArray();
        break;
    }
}

int* getArray(int arrayLength, int min, int max) {
    srand(time(0));
    int* array = new int[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        array[i] = (rand() % (max - min)) + min + 1;
    }
    return array;
}

void task1MinMaxInArray() {
    const int arrayLength = 10;
    int min = 0, max = 100;
    int* array = getArray(arrayLength, min, max);
    int maxInt = array[0], minInt = array[0];

    for (int i = 0; i < arrayLength; i++) {
        cout << array[i] << "\t";
        if (array[i] < minInt) minInt = array[i];
        if (array[i] > maxInt) maxInt = array[i];
    }
    cout << "\nMax number: " << maxInt << "\nMin number: " << minInt << endl;
}

void task2SumNumsLessThan() {
    const int arrayLength = 10;
    int min, max, maxNumForSum, sum = 0;
    cout << "Enter range for array numbers:";
    do {
        cout << "\nMin: ";
        cin >> min;
        cout << "Max: ";
        cin >> max;
    } while (min > max);

    int* array = getArray(arrayLength, min, max);

    cout << "Enter maximum number to count sum to: ";
    cin >> maxNumForSum;

    for (int i = 0; i < arrayLength; i++) {
        cout << array[i] << "\t";
        if (array[i] < maxNumForSum) sum += array[i];
    }

    cout << "\nSum of numbers less than " << maxNumForSum << " in array is " << sum << endl;
}

void task3BusinessIncome() {
    int incomeArray[12];
    cout << "Enter income for a year by month: ";
    for (int i = 0; i < 12; i++) {
        cout << "\n" << i + 1 << " month: ";
        cin >> incomeArray[i];
    }
    
    int from, to, worst, best;
    cout << "Enter range for finding worst and best month:\nFrom month (1-11): ";
    cin >> from, from--;
    cout << "To (" << from + 2 << "-12): ";
    cin >> to, to--;
    worst = from, best = from;

    for (from; from < to; from++) {
        if (incomeArray[from] < incomeArray[worst]) worst = from;
        if (incomeArray[from] > incomeArray[best]) best = from;
    }

    cout << "\nWorst month in range with " << incomeArray[worst] << " money: " << worst + 1 << endl;
    cout << "\nBest month in range with " << incomeArray[best] << " money: " << best + 1 << endl;
}

void task4FloatArray() {
    const int arrayLength = 10;
    int upperBound = 100.0, lowerBound = -100.0;
    srand(time(0));
    double array[arrayLength];
    for (int i = 0; i < arrayLength; i++) {
        array[i] = lowerBound + (upperBound - lowerBound) * ((rand() % 10000) / (double)10000);
        cout << array[i] << "\t";
    }

    // 1. Negative sum
    double sumNegatives = 0;
    // 2. Product of numbers between indexes of min and max numbers
    double productBetwMinMax = 1, min = array[0], max = array[0];
    int minInd, maxInd;
    // 3. Product of numbers with even indexes
    double productEvenInd = 1;
    // 4. Sum of numbers between indexes of first and last negative numbers
    double sumBetwNeg = 0;
    int firstNegInd = -1, lastNegInd;

    for (int i = 0; i < arrayLength; i++) {
        // 1.
        if (array[i] < 0) sumNegatives += array[i];
        // 2.
        if (array[i] >= max) {
            max = array[i];
            maxInd = i;
        }
        if (array[i] <= min) {
            min = array[i];
            minInd = i;
        }
        // 3.
        if (not(i % 2)) productEvenInd *= array[i];
        // 4.
        if (array[i] < 0) {
            if (firstNegInd < 0) {
                firstNegInd = i;
                lastNegInd = i;
            }
            else {
                lastNegInd = i;
            }
        }
    }

    // 2.
    if (minInd > maxInd) {
        int temp = minInd;
        minInd = maxInd;
        maxInd = temp;
    }
    for (int i = minInd; i < maxInd; i++) {
        productBetwMinMax *= array[i];
    }

    // 4.
    if (not(firstNegInd == -1 || firstNegInd == lastNegInd)) {
        for (int i = firstNegInd; i < lastNegInd; i++) {
            sumBetwNeg += array[i];
        }
    }
    else cout << "There's not enough negative numbers in array for 4.4 task.\n";
    cout << "\nTask 4.1: Sum of all negative numbers: " << sumNegatives << endl;
    cout << "Task 4.2: Product of numbers between indexes of min and max numbers :" << productBetwMinMax << endl;
    cout << "Task 4.3: Product of numbers with even indexes: " << productEvenInd << endl;
    cout << "Task 4.4: Sum of numbers between indexes of first and last negative numbers: ";
    (sumBetwNeg == 0) ? cout << "There's not enough negative numbers in the array\n" : cout << sumBetwNeg << endl;
    }
    