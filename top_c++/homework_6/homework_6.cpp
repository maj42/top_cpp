//TODO
#include <iostream>

using namespace std;

void task1Phonebook();

void bubbleSortToOrder(long long* arraySort, int* arrayOrder, int count);

int main()
{
    task1Phonebook();
}

void task1Phonebook() {
    const int arraySize = 5;
    long long arrayMobile[arraySize] = { 89991234567, 89999876543, 89001234567, 89009876543, 89123456789 };
    int arrayLandline[arraySize] = { 567891, 123456, 987654, 345678, 234567 };
    string arrayNames[arraySize] = { "Vasya", "Jack", "Mary", "Katya", "Mike" };
    int arrayOrder[arraySize] = { 0, 1, 2, 3, 4 };

    int choice = 3;
    while (choice <= 3 && choice >= 1) {
        cout << "Enter your choice:\n1 - Sort by mobile\n2 - Sort by landline\n3 - Print phonebook\n4 - Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            bubbleSortToOrder(arrayMobile, arrayOrder, arraySize);
            cout << arrayOrder[0] << arrayOrder[1] << arrayOrder[2] << arrayOrder[3] << arrayOrder[4];
            break;
        case 2:
            bubbleSortToOrder(arrayLandline, arrayOrder, arraySize);
            cout << arrayOrder[0] << arrayOrder[1] << arrayOrder[2] << arrayOrder[3] << arrayOrder[4];
            break;
        case 3:
            break;
        case 4:
            break;
        }
    }
    
    

    for (int i = 0; i < arraySize; i++) cout << arrayNames[i] << "\t" << arrayMobile[i] << "\t" << arrayLandline[i] << endl;
}

template<class T>
void bubbleSortToOrder(T* arraySort, int* arrayOrder, int count) {
    for (auto i = 0; i < count - 1; i++)
    {
        for (auto j = i + 1; j < count; j++)
        {
            if (arraySort[i] > arraySort[j]) {
                int temp = arrayOrder[i];
                arrayOrder[i] = arrayOrder[j];
                arrayOrder[j] = temp;
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