#include <iostream>

using namespace std;

void task1Phonebook();
void task2ModifiedBubble();
void task3PancakeSort();
void task4SortAlgComparison();

void bubbleSortByMobile(long long* arrayMobile, int* arrayLandline, string* arrayNames, int arraySize);
void bubbleSortByLandline(int* arrayLandline, long long* arrayMobile, string* arrayNames, int arraySize);
int sortBubbleModCount(int* array, int size);
int sortSelectionCount(int* array, int size);
void reverseStack(int* array, int start, int end);

int main()
{
    int choice;
    do {
        cout << "Enter your choice:\n1 - Phonebook with sorting\n2 - Modified Bubble sort\n\
3 - Sorting pancakes with a spatula\n4 - Comparing sorting algorithms: Modified Bubble sort and Selecion sort\n";
        cin >> choice;
    } while (choice < 1 || choice > 4);
    switch (choice) {
    case 1:
        cout << "\nPhonebook\n";
        task1Phonebook();
        break;
    case 2:
        cout << "\nModified Bubble sort\n";
        task2ModifiedBubble();
        break;
    case 3:
        cout << "\nSorting pancakes\n";
        task3PancakeSort();
        break;
    case 4:
        cout << "\nBubble vs. Selection\n";
        task4SortAlgComparison();
        break;
    }
}

void task1Phonebook() {
    const int arraySize = 5;
    long long arrayMobile[arraySize] = { 89991234567, 89999876543, 89001234567, 89009876543, 89123456789 };
    int arrayLandline[arraySize] = { 567891, 123456, 987654, 345678, 234567 };
    string arrayNames[arraySize] = { "Vasya", "Jack", "Mary", "Katya", "Mike" };

    int choice = 3;
    while (choice <= 3 && choice >= 1) {
        cout << "Enter your choice:\n1 - Sort by mobile\n2 - Sort by landline\n3 - Print phonebook\nAny other key - Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            bubbleSortByMobile(arrayMobile, arrayLandline, arrayNames, arraySize);
            break;
        case 2:
            bubbleSortByLandline(arrayLandline, arrayMobile, arrayNames, arraySize);
            break;
        case 3:
            for (int i = 0; i < arraySize; i++) cout << "\t" << arrayNames[i] << "\t" << arrayMobile[i] << "\t" << arrayLandline[i] << "\n\n";
            break;
        default:
            break;
        }
    }
}

void task2ModifiedBubble() {
    cout << "Before:\t";
    int sampleArray[8] = { 4, 3, 5, 2, 6, 7, 8, 9 };
    for (int i = 0; i < sizeof(sampleArray) / sizeof(int); i++) cout << sampleArray[i] << "\t";
    sortBubbleModCount(sampleArray, sizeof(sampleArray) / sizeof(int));
    cout << "\nAfter:\t";
    for (int i = 0; i < sizeof(sampleArray) / sizeof(int); i++) cout << sampleArray[i] << "\t";
}

void task3PancakeSort() {
    const int pancakes = 8;
    int pancakeStack[pancakes] = { 9, 6, 7, 3, 8, 2, 4, 5 };
    int swaps = 0, biggestPancakeInd;
    for (int i = 0; i < pancakes; i++) {
        biggestPancakeInd = i;
        for (int ii = i; ii < pancakes; ii++) {
            if (pancakeStack[ii] > pancakeStack[biggestPancakeInd]) biggestPancakeInd = ii;
        }
        if (biggestPancakeInd != i) {
            if (biggestPancakeInd != pancakes - 1) reverseStack(pancakeStack, biggestPancakeInd, pancakes - 1), swaps++;
            reverseStack(pancakeStack, i, pancakes - 1), swaps++;
        }
        cout << swaps << ":\t";
        for (int ii = 0; ii < pancakes; ii++) cout << pancakeStack[ii] << "\t";
        cout << endl;
    }
    cout << "Pancakes sorted in " << swaps << " swaps.";
}

void task4SortAlgComparison() {
    srand(time(0));
    const int arraySize = 1000;                             // размер массива
    const int arrays = 10;                                  // кол-во массивов
    int bubbleArray[arraySize], selectionArray[arraySize];  // массивы
    int bubbleResult[arrays], selectionResult[arrays];      // массив для кол-ва замен
    double bubbleAver = 0, selectionAver = 0;                  // для хранения суммы замен и вычисления среднего
    for (int array = 0; array < arrays; array++) {
        for (int i = 0; i < arraySize; i++) {
            int num = rand() % 1000;                        // диапазон значений массива 0 - 999
            bubbleArray[i] = selectionArray[i] = num;       // два идентичных массива
        }
        bubbleResult[array] = sortBubbleModCount(bubbleArray, arraySize);
        selectionResult[array] = sortSelectionCount(selectionArray, arraySize);
    }

    cout << "Bubble sort swaps\tSelection sort swaps\n";
    for (int i = 0; i < arrays; i++) {
        bubbleAver += bubbleResult[i];
        selectionAver += selectionResult[i];
        cout << bubbleResult[i] << "\t\t\t" << selectionResult[i] << endl;
    }
    bubbleAver = bubbleAver / arrays;
    selectionAver = selectionAver / arrays;
    cout << "Average swaps:\n" << bubbleAver << "\t\t\t" << selectionAver << endl;
}

void bubbleSortByMobile(long long* arrayMobile, int* arrayLandline, string* arrayNames, int count) {
    for (auto i = 0; i < count - 1; i++)
    {
        for (auto ii = i + 1; ii < count; ii++)
        {
            if (arrayMobile[i] > arrayMobile[ii]) {

                long long tempMobile = arrayMobile[i];
                arrayMobile[i] = arrayMobile[ii];
                arrayMobile[ii] = tempMobile;

                int tempLandline = arrayLandline[i];
                arrayLandline[i] = arrayLandline[ii];
                arrayLandline[ii] = tempLandline;

                string tempName = arrayNames[i];
                arrayNames[i] = arrayNames[ii];
                arrayNames[ii] = tempName;
            }
        }
    }
}

void bubbleSortByLandline(int* arrayLandline, long long* arrayMobile, string* arrayNames, int count) {
    for (auto i = 0; i < count - 1; i++)
    {
        for (auto ii = i + 1; ii < count; ii++)
        {
            if (arrayLandline[i] > arrayLandline[ii]) {

                int tempLandline = arrayLandline[i];
                arrayLandline[i] = arrayLandline[ii];
                arrayLandline[ii] = tempLandline;

                long long tempMobile = arrayMobile[i];
                arrayMobile[i] = arrayMobile[ii];
                arrayMobile[ii] = tempMobile;

                string tempName = arrayNames[i];
                arrayNames[i] = arrayNames[ii];
                arrayNames[ii] = tempName;
            }
        }
    }
}

int sortBubbleModCount(int *array, int size) {
    int swaps = 0;
    for (int i = 0; i < size; i++) {
        bool swapped = false;
        for (int j = 1; j < size - i; j++) {
            if (array[j - 1] > array[j]) {
                swapped = true;
                swaps++;
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
        if (!swapped) return swaps;
    }
    return swaps;
}

void reverseStack(int* array, int start, int end) {
    for (int i = 0; i <= (end - start) / 2; i++) {
        int temp = array[start + i];
        array[start + i] = array[end - i];
        array[end - i] = temp;
    }
}

int sortSelectionCount(int* array, int size) {
    int swaps = 0;
    for (int i = 0; i < size; i++) {
        int min = i, temp;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (i != min) {
            swaps++;
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    return swaps;
}