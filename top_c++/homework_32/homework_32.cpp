#include <iostream>

using namespace std;

struct List {
    int size;
    int* arr = new int[size];
};

void fillList(List);
void printList(List);
void copyElem(List, List, int, int);

int main()
{
    List list1{ 20 };
    List list2{ 15 };

    fillList(list1);
    fillList(list2);
    printList(list1);
    printList(list2);
    copyElem(list1, list2, 1, 10);
    printList(list2);
}

void fillList(List list) {
    for (int i = 0; i < list.size; ++i) {
        list.arr[i] = i;
    }
}

void printList(List list) {
    for (int i = 0; i < list.size; ++i) {
        cout << list.arr[i] << " ";
    }
    cout << endl;
}

void copyElem(List listFr, List listTo, int indFr, int indTo) {
    if ((indFr - 1 < listFr.size) && (indTo - 1 < listTo.size)) listTo.arr[indTo] = listFr.arr[indFr];
    else cout << "Index out of range" << endl;
}