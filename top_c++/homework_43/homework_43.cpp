#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class String {
    char* str;
    size_t len;
    
    static int counter;

public:
    String(int len) : str(new char[len] {}), len(len) {
        String::counter++;
    }
    
    String() : String(80) {}
    
    String(const char* input, int len) {
        this->len = strlen(input);
        str = new char[len];
        strcpy(str, input);
        String::counter++;
    }

    String(const char* input) : String(input, 80) {}

    ~String() {
        String::counter--;
        delete[] str;
    }

    static int count() {
        return String::counter;
    }

    void edit(const char* newStr, int size) {
        delete[] str;
        str = new char[size];
        strcpy(str, newStr);
    }

    void edit(const char* newStr) {
        delete[] str;
        str = new char[80];
        strcpy(str, newStr);
    }

    void print() const{
        char* strP = str;
        while (*strP) std::cout << *(strP++);
        std::cout << std::endl;
    }
};
int String::counter = 0;

int main()
{
    {
        String empty;
        String hello{ "hello", 6 };
        String sizeless{ "There's no size here" };
        std::cout << String::count() << std::endl;
        empty.print();
        hello.print();
        hello.edit("goodbye");
        hello.print();
        sizeless.print();
    }
    std::cout << String::count() << std::endl;
}