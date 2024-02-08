#include <iostream>

using namespace std;

size_t strSize(const char*);

int main()
{
    const char* str1{""};
    const char* str2{ "Hello world" };
    const char* str3{ "                " };
    const char* str4{ "Hell\0o unreachable world" };
    cout << strSize(str1) << "\n" << strSize(str2) << "\n" << strSize(str3) << "\n" << strSize(str4) << endl;
}

size_t strSize(const char* str) {
    if (*str == '\0') return 0;
    return 1 + strSize(str + 1);
}