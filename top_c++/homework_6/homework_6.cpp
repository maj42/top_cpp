#include <iostream>

using namespace std;

int main()
{
    
}
/*
#include <iostream>

using namespace std;

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