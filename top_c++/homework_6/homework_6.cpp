//TODO
#include <iostream>

using namespace std;

void task1Phonebook();

void bubbleSortByMobile(long long* arrayMobile, int* arrayLandline, string* arrayNames, int arraySize);
void bubbleSortByLandline(int* arrayLandline, long long* arrayMobile, string* arrayNames, int arraySize);

int main()
{
    task1Phonebook();
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

/*
void quickSort(int* array, int size);
void swap(int& first, int& second);

int main()
{
    int array[] = {34, 54, 2, 55, 45, 34, 44, 22, 12, 3};
    int size = sizeof(array) / sizeof(int);
    quickSort(array, size - 1);
    for (int i = 0; i < size; i++) {
        cout << array[i] << "\t";
    }
    return 0;
}

void quickSort(int* array, int size) {
    int left = 0, right = size;
    int pivot = array[size / 2];
    do {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;
        if (left <= right) {
            swap(array[left], array[right]);
            left++; right--;
        }
    } while (left <= right);
    if (right > 0) quickSort(array, right);
    if (size > left) quickSort(array + left, size - left);
}

void swap(int& first, int& second) {
    int temp;
    temp = first;
    first = second;
    second = temp;
}
*/