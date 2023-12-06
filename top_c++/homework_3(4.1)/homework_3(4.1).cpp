#include <iostream>
#include <cmath>

using namespace std;

int getNumber(int digits);
void luckyNumber();
void numbersSwap();
void getMaxNumber();
void fuelCalc();

int main()
{
    //luckyNumber();
    //numbersSwap();
    //getMaxNumber();
    fuelCalc();
}

int getNumber(int digits) {
    int number;
    do {
        cout << "Please enter a number. Number must consist of " << digits << " digits: ";
        cin >> number;
    } while (number < pow(10, digits - 1) || number > pow(10, digits));
    return number;
}

int getConsequtiveNumber() {
    int number;
    do {
        cout << "\nPlease enter a number: ";
        cin >> number;
    } while (number < 0 || number > 9);
    return number;
    
}

void luckyNumber() {
    int number, first, second, third, fourth, fifth, sixth;
    number = getNumber(6);
    
    sixth = number % 10;
    fifth = number % 100 / 10;
    fourth = number % 1000 / 100;
    third = number % 10000 / 1000;
    second = number % 100000 / 10000;
    first = number / 100000;

    if ((first + second + third) == (fourth + fifth + sixth)) {
        cout << "The number is lucky!" << endl;
    }
    else {
        cout << "The number is not lucky." << endl;
    }
}  

void numbersSwap() {
    int number, swappedNumber, first, second, third, fourth;
    number = getNumber(4);

    fourth = number % 10;
    third = number % 100 / 10;
    second = number % 1000 / 100;
    first = number / 1000;

    swappedNumber = second * 1000 + first * 100 + fourth * 10 + third;
    cout << "Number is " << number << ". Swapped number is " << swappedNumber << endl;
}

void getMaxNumber() {
    int currentMax = 0;
    int number;
    cout << "Enter 7 consecutive numbers." << endl;
    for (int i = 0; i < 7; i++) {
        number = getConsequtiveNumber();
        (number > currentMax) ? (currentMax = number) : 1;
        cout << "Number " << i + 1 << " is " << number << endl;
    }
    cout << "\nMax number is " << currentMax << endl;
}

void fuelCalc() {
    int distAB, distBC, loadWeight, fuelConsumption, fuelCurrent = 300, fuelAdd;
    cout << "Enter distance from A to B in km: ";
    cin >> distAB;
    cout << "Enter distance from B to C in km: ";
    cin >> distBC;
    cout << "Enter plane load weight in kg: ";
    cin >> loadWeight;

    if (loadWeight < 500) {
        fuelConsumption = 1;
    }
    else if (loadWeight < 1000) {
        fuelConsumption = 4;
    }
    else if (loadWeight < 1500) {
        fuelConsumption = 7;
    }
    else if (loadWeight < 2000) {
        fuelConsumption = 9;
    }
    else {
        cout << "The plane is overloaded." << endl;
        return;
    }

    if ((fuelCurrent / fuelConsumption) < distAB || (fuelCurrent / fuelConsumption) < distBC) {
        cout << "Not enough fuel to fly this distance with this load." << endl;
        return;
    }
   
    int fuelConsumedAB, fuelConsumedBC;
    fuelConsumedAB = distAB * fuelConsumption;
    fuelConsumedBC = distBC * fuelConsumption;

    if ((fuelCurrent - fuelConsumedAB) > fuelConsumedBC) {
        cout << "You don't have to add fuel, it's enough." << endl;
        }
    else {
        fuelAdd = fuelConsumedBC - (fuelCurrent - fuelConsumedAB);
        cout << "You have to add at least " << fuelAdd << "L of fuel in point B." << endl;
    }
}