#include <iostream>

using namespace std;

void myMemCpy(void* dest, void* src, size_t count);

int main()
{
    char source[] { "Hello World" };
    char* destination{};
    void* srcPtr = source;
    void* dstPtr = destination;
    myMemCpy(dstPtr, srcPtr, sizeof(source));
    
    for (int i = 0; i < sizeof(source); i++) {
        cout << *((char*)destination + i);
    } 
}

// Не знаю как выделить память чтоб доступ к ней сохранялся вне функции. Этот код выдаст Access Violation
void myMemCpy(void* dest, void* src, size_t count) {
    dest = malloc(count);
    for (int i = 0; i < count; i++) {
        *((char*)dest + i) = *((char*)src + i);
    }
}
