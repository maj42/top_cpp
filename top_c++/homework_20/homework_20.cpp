#include <iostream>

using namespace std;

bool IsDigit(unsigned char);
unsigned char ToUpper(unsigned char);
string getLongestWord(string);

int main()
{
    cout << boolalpha << IsDigit('f') << endl;
    cout << boolalpha << IsDigit('4') << endl;

    cout << ToUpper('f') << endl;

    string lWord = getLongestWord("Never gonna longestword give you up");
    cout << "Longest word: " << lWord << "\nLength: " << lWord.size();
}

bool IsDigit(unsigned char c) {
    return (c >= '0' && c <= '9');
}

unsigned char ToUpper(unsigned char c) {
    return (c + ('A' - 'a'));
}

string getLongestWord(string inputStr) {
    string word, longestWord;
    int len = 0, maxLen = 0;
    for (char c : inputStr) {
        if (c != ' ') {
            word += c;
            len++;
        }
        else {
            if (len > maxLen) {
                longestWord = word;
                maxLen = len;
            }
            word.clear();
            len = 0;
        }
    }
    if (len > maxLen) word = longestWord;
    return longestWord;
}