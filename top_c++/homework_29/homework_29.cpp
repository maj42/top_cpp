#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string getStrNum();

int main()
{
	string num1, num2;
	cout << "Enter num1: " << endl;
	num1 = getStrNum();
	cout << "Enter num2: " << endl;
	num2 = getStrNum();
	cout << "Product of this numbers: " << stoi(num1) * stoi(num2) << endl;
}

string getStrNum() {
	string num;
	while (true) {
		cout << "Enter a number. Size >= 1 and <= 200 digits. Only digits. No leading zeroes." << endl;
		getline(cin, num);
		if (num.length() < 1 || num.length() > 200) continue;
		if (!all_of(num.begin(), num.end(), [](char ch) {return isdigit(ch); })) continue;
		if (num.length() > 1 && num[0] == '0') continue;
		break;
	}
	cout << "Got a valid number" << endl;
	return num;
}
