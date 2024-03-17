#include <iostream>

using namespace std;

void task1DelInd();
void task2DelSym();
void task3InsSym();
void task4Replace();
void task5Count();
void task6CountEvrth();

int main()
{
    cout << "Task 1: Delete ind 1\n";
    task1DelInd();
    cout << "\n\nTask 2: Delete all sym 'l'\n";
    task2DelSym();
    cout << "\n\nTask 3: Insert '!' in 0 ind\n";
    task3InsSym();
    cout << "\n\nTask 4: Replace '.' with '!'\n";
    task4Replace();
    cout << "\n\nTask 5: Count symbols 'l'\n";
    task5Count();
    cout << "\n\nTask 6: Count everything\n";
    task6CountEvrth();
}

void task1DelInd() {
    char str[] = { "hello" };
    int strSize = sizeof(str) / sizeof(char);
    cout << str << endl;
    int ind = 1;

    for (int i = 0, j = 0; i < strSize; ++i) {
        if (i == ind) continue;
        str[j++] = str[i];
    }

    cout << str;
}

void task2DelSym() {
    char str[] = { "hello" };
    int strSize = sizeof(str) / sizeof(char);
    cout << str << endl;
    char ch = 'l';

    for (int i = 0, j = 0; i < strSize; ++i) {
        if (str[i] == ch) continue;
        str[j++] = str[i];
    }
    
    cout << str;
}

void task3InsSym() {
    char str[] = { "hello" };
    const int strSize = sizeof(str) / sizeof(char);
    cout << str << endl;
    int ind = 0;
    char sym = '!';
    char newStr[strSize + 1];

    for (int i = 0, j = 0; i < strSize; ++i) {
        if (i == ind) newStr[j++] = sym;
        newStr[j++] = str[i];
    }
    
    cout << newStr;
}

void task4Replace() {
    char str[] = { "h.llo." };
    const int strSize = sizeof(str) / sizeof(char);
    cout << str << endl;

    for (int i = 0; i < strSize; ++i) {
        if (str[i] == '.') str[i] = '!';
    }

    cout << str;
}

void task5Count() {
    char str[] = { "hello" };
    const int strSize = sizeof(str) / sizeof(char);
    cout << str << endl;
    char charCnt = 'l';
    int cntr = 0;

    for (int i = 0; i < strSize; ++i) {
        if (str[i] == charCnt) cntr++;
    }

    cout << cntr;
}

void task6CountEvrth() {
    char str[] = { "hello 123 !&@^%#" };
    const int strSize = sizeof(str) / sizeof(char);
    cout << str << endl;
    int numsCntr = 0, charsCntr = 0, symsCntr = 0;

    for (int i = 0; i < strSize; ++i) {
        if (isdigit(str[i])) numsCntr++;
        else if (isalpha(str[i])) charsCntr++;
        else symsCntr++;
    }

    cout << "Numbers: " << numsCntr << "\nChars: " << charsCntr << "\nSymbols (with spaces and \\0): " << symsCntr << endl;
}