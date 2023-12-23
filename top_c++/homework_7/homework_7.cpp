#include <iostream>

using namespace std;

void task1DoubleDigits();
void task2UniqueDigits();
void task3Delete3and6();
void task4Dividers();
void task5CubeSumAndSquare();
void task6AllDividers();
void task7CommonDividers();

int main()
{
	//task1DoubleDigits();
	//task2UniqueDigits();
	//task3Delete3and6();
	task4Dividers();
	//task5CubeSumAndSquare();
	//task6AllDividers();
	//task7CommonDividers();
}

void task1DoubleDigits() {
	int doubleNumsQty = 0;
	for (int hundreds = 1; hundreds < 10; hundreds++) {
		for (int tens = 0; tens < 10; tens++) {
			for (int singles = 0; singles < 10; singles++) {
				if ((hundreds == tens) || (tens == singles) || (hundreds == singles)) doubleNumsQty++;
			}
		}
	}
	cout << "Quantity of numbers with double digits between 100 and 999: " << doubleNumsQty;
}

void task2UniqueDigits() {
	int uniqueNumsQty = 0;
	for (int hundreds = 1; hundreds < 10; hundreds++) {
		for (int tens = 0; tens < 10; tens++) {
			for (int singles = 0; singles < 10; singles++) {
				if ((hundreds != tens) && (tens != singles) && (hundreds != singles)) uniqueNumsQty++;
			}
		}
	}
	cout << "Quantity of numbers with unique digits between 100 and 999: " << uniqueNumsQty << endl;
}

void task3Delete3and6() {
	int inputNumber, outputNumber = 0, digit, power = 0;
	cout << "Enter number to delete 3 and 6 from it: ";
	cin >> inputNumber;
	do {
		digit = inputNumber % 10;
		if ((digit == 3) || (digit == 6)) {
			inputNumber /= 10;
			continue;
		}
		outputNumber += digit * pow(10, power++);
		inputNumber /= 10;
	} while (inputNumber > 0);
	cout << "Number without 3 and 6: " << outputNumber << endl;
}

void task4Dividers() {
	int num;
	cout << "Enter number to find dividers: ";
	cin >> num;
	cout << "Number " << num << " has numbers, for which the following is true: number^2 is a divider, number^3 is not:\n";

	for (int i = 2; i < num / 2; i++) {
		if (not(num % (i * i)) && (num % (i * i * i))) cout << i << endl;
	}
		
}

void task5CubeSumAndSquare() {
	int num, numCopy, digit, digitsSum = 0;
	cout << "Enter number to find if cube of sum of its digits equals numbers's square: ";
	cin >> num;
	numCopy = num;
	do {
		digit = numCopy % 10;
		digitsSum += digit;
		numCopy /= 10;
	} while (numCopy > 0);
	cout << "Cube of digits: " << pow(digitsSum, 3) << "\nSquare of number: " << pow(num, 2) << endl;
	(pow(digitsSum, 3) == (pow(num, 2)) ? (cout << "They're equal" << endl) : (cout << "They're not equal" << endl));
}

void task6AllDividers() {
	int num;
	cout << "Enter number to find all dividers: ";
	cin >> num;
	cout << "Number " << num << " dividers:\n";
	for (int i = 2; i <= num / 2; i++) {
		if (not(num % i)) cout << i << endl;
	}
}

void task7CommonDividers() {
	int num1, num2;
	cout << "Enter 2 numbers to find all dividers of both:\n";
	cin >> num1 >> num2;
	cout << "Common dividers:\n";
	for (int i = 2; i <= num1 / 2; i++) {
		if (not(num1 % i) && not(num2 % i)) cout << i << endl;
	}
}