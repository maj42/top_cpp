#include <iostream>

using namespace std;

size_t strSize(const char*);

int main()
{
    const char* str1{""};
    const char* str2{ "Hello world" };
    const char* str3{ "                " };
    cout << strSize(str1) << "\n" << strSize(str2) << "\n" << strSize(str3) << "\n" << endl;
}

size_t strSize(const char* str) {
    if (*str == '\0') return 0;
    return 1 + strSize(str + 1);
}