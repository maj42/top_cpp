#include <iostream>

using namespace std;

void task1();
void task2();
void task3();
void task4();

int main()
{
    srand(time(0));
    //task1();
    //task2();
    //task3();
    task4();
}

void task1() {
    const int entrs = 4, floors = 5, apmts = 2;
    int residents[entrs][floors][apmts];

    for (int entr = 0; entr < entrs; ++entr) {
        for (int floor = 0; floor < floors; ++floor) {
            for (int apmt = 0; apmt < apmts; ++apmt) residents[entr][floor][apmt] = rand() % 8;
        }
    }

    //1.1 residents and neighbours in 2nd entrance, 4th floor, 2nd appartment
    int floorResidents = 0;
    for (int apmt = 0; apmt < apmts; ++apmt) floorResidents += residents[1][3][apmt];
    cout << "In 2nd entrance, 4th floor, 2nd appartment " << residents[1][3][1] << " residents. They have " << floorResidents - residents[1][3][1] << " neighbours." << endl;

    //1.2 residents for every entrance
    int entranceResidents = 0;
    for (int entr = 0; entr < entrs; ++entr) {
        int entranceResidents = 0;
        for (int floor = 0; floor < floors; ++floor) {
            for (int apmt = 0; apmt < apmts; ++apmt) entranceResidents += residents[entr][floor][apmt];
        }
        cout << "Entrance " << entr << ": " << entranceResidents << " residents" << endl;
    }

    //1.3 large families
    int largeFamilies = 0;
    cout << "Appartments with large families: " << endl;
    for (int entr = 0; entr < entrs; ++entr) {
        for (int floor = 0; floor < floors; ++floor) {
            for (int apmt = 0; apmt < apmts; ++apmt) {
                if (residents[entr][floor][apmt] > 5) cout << entr << '.' << floor << '.' << apmt << "\t";
            }
        }
    }
}

void task2() {
    float temp[31];
    for (int i = 0; i < 31; ++i) temp[i] = (rand() % 200 - 400) / 10.0;
    
    //2.1
    int averTemp = 0;
    for (int i = 0; i < 31; ++i) averTemp += temp[i];
    averTemp /= 31;
    cout << "Average temperature is " << averTemp << endl;

    //2.2 below -35
    int tempBelow = 0;
    for (int i = 0; i < 31; ++i) {
        if (temp[i] < -35) tempBelow++;
    }
    cout << "Temperature below -35 was " << tempBelow << " times" << endl;

}

void task3() {
    int cars[10];
    for (int i = 0; i < 10; ++i) cars[i] = ((rand() % 10) + 1) * 100000;

    int highestPrice = 0, highestInd = 0, lastHighest = 0;
    for (int i = 0; i < 10; ++i) {
        if (cars[i] > highestPrice) {
            highestPrice = cars[i];
            highestInd = i;
            lastHighest = 0;
        }
        else if (cars[i] == highestPrice) {
            lastHighest = i;
        }
    }

    lastHighest ? cout << "First most expencive car - " << highestInd << ", last - " << lastHighest << endl : cout << "Most expencive car - " << highestInd << endl;
}

void task4() {
    int arr[20];
    for (int i = 0; i < 20; ++i) arr[i] = rand() % 10;

    int duplArr[20]{ 0 };
    cout << "Duplicate values:\n";
    for (int i = 0; i < 20; ++i) {
        if (duplArr[i] > 0) continue;
        for (int j = i + 1; j < 20; ++j) {
            if (arr[i] == arr[j]) {
                ++duplArr[i];
            }
        }
    }

    for (int i = 0; i < 20; ++i) {
        if (duplArr[i] == 1) cout << arr[i] << " ";
    }
}
