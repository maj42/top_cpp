#include <iostream>
#include <string> //stoi
#include <sstream> //stringstream
#include <stdio.h> //atoi

using namespace std;

void task1STOI();
void task2UpperCase();

int level1(string);
int level2(string);
int level3(string);
int level4(string);
int level5(string);
int level6(string);
int level7(string);
string moveUpperCase(string&);

int main()
{
    //task1STOI();
    task2UpperCase();
}

void task1STOI() {
    int choice = 0;
    cout << "Choose the amount of vsratost for your string to ingeger function from 1 to 7. 0 for exit:\n";
    cin >> choice;
    switch (choice){
    case 0: 
        cout << "Exit\n";
        break;
    case 1:
        cout << level1("42");
        break;
    case 2:
        cout << level2("42");
        break;
    case 3:
        cout << level3("42");
        break;
    case 4:
        cout << level4("42");
        break;
    case 5:
        cout << level5("42");
        break;
    case 6:
        cout << level6("42");
        break;
    case 7:
        cout << level7("42");
        break;
    }
    cout << endl;
}

void task2UpperCase() {
    string comp = "ComPUteR", jir = "JIRAFFE", hyp = "hyppopotamus", newComp, newJir, newHyp;
    newComp = moveUpperCase(comp);
    newJir = moveUpperCase(jir);
    newHyp = moveUpperCase(hyp);
    cout << comp << "\t" << newComp << endl;
    cout << jir << "\t" << newJir << endl;
    cout << hyp << "\t" << newHyp << endl;
}

int level1(string str) {
    return stoi(str);
}

int level2(string str) {
    stringstream stream;
    stream << str;
    int intFromStream;
    stream >> intFromStream;
    return intFromStream;
}

int level3(string str) {
    char* arr = new char[str.length() + 1];
    int i = 0;
    for (char ch : str) arr[i++] = ch;
    arr[str.length()] = '\0';
    return atoi(arr);
}

int level4(string str) {
    int result = 0, num = 0, i = 0;
    while (!str.empty()) {
        num = str.at(str.length() - 1);
        str.pop_back();
        i++ ? result += (num - '0') * i * 10 : result += num - '0';
    }
    return result;
}

int level5(string str) {
    int result = 0, ord = 0;
    for (char ch : str) {
        if (ch >= '0' && ch <= '9') {
            result *= 10;
            result += ch - '0';
        }
    }
    return result;
}

int level6(string str) {
    srand(time(NULL));
    int num, result = 0;
    char numAsCh;
    for (char ch : str) {
        while (true) {
            num = rand() % 10;
            numAsCh = num + '0';
            if (ch == numAsCh) break;
        }
        result *= 10;
        result += num;
    }
    return result;
}

int level7(string str) {
    srand(time(NULL));
    int num;
    string numAsStr;
    while (true) {
        num = rand() % (stoi(str) * 2);
        numAsStr = to_string(num);
        if (str == numAsStr) break;
    }
    return num;
}

string moveUpperCase(string &str) {
    string oldStr, newStr;
    oldStr = str.substr(0);
    for (char ch : str) {
        if (ch >= 'A' && ch <= 'Z') {
            newStr.append(1, ch);
            if (!oldStr.empty()) oldStr.erase(oldStr.find(ch));
        }
    }
    str = oldStr.substr(0);
    return newStr;
}