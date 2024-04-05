#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string acceptAnyStr();
int acceptNumStr();
void addSubStr(string&, string);
void printEdgeSyms(string);
void remSyms(string&);
void compareStr(string);
void diff2024(int);

int main()
{
    string anyStr = acceptAnyStr();
    cout << "Starting string: " << anyStr << endl;
    addSubStr(anyStr, "C++");
    cout << "Add C++: " << anyStr << endl;
    printEdgeSyms(anyStr);
    remSyms(anyStr);
    cout << "Removed all symbols: " << anyStr << endl;
    compareStr(anyStr);
    int num = acceptNumStr();
    diff2024(num);
}

string acceptAnyStr() {
    string anyStr;
    while (true) {
        cout << "Enter string, string must not be empty:\n";
        getline(cin, anyStr);
        if (!anyStr.empty() && anyStr.compare((string(anyStr.length(), ' ')))) break;
    }
    return anyStr;
}

int acceptNumStr() {
    string numStr;
    while (true) {
        cout << "Enter numeric string, all symbols must be numbers, also string must not be empty:\n";
        getline(cin, numStr);
        if (!numStr.empty() && numStr.compare((string(numStr.length(), ' '))) &&
            all_of(numStr.begin(), numStr.end(), [](char ch) {return isdigit(ch); })) break;
    }
    return stoi(numStr);
}

void addSubStr(string& anyStr, string addStr) {
    anyStr += addStr;
}

void printEdgeSyms(string anyStr) {
    cout << "First and last symbols: " << anyStr.front() << " and " << anyStr.back() << endl;
}

void remSyms(string& anyStr) {
    string corrStr;
    for (char ch : anyStr) corrStr.append(1, ch);
    for (char ch : anyStr) {
        if (ispunct(ch)) corrStr.replace(corrStr.find(ch), 1, "");
    }
    anyStr = corrStr;
}

void compareStr(string anyStr) {
    string newStr;
    cout << "Accepting new string: " << endl;
    newStr = acceptAnyStr();
    if (anyStr == newStr) cout << "Strings are equal" << endl;
    else if (anyStr > newStr) cout << "Old string is greater" << endl;
    else cout << "Old string is less" << endl;
}

void diff2024(int num) {
    cout << "Difference between 2024 and number is " << 2024 - num << endl;
}