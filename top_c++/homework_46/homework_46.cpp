#include <iostream>

class DynArray {
    int* arr;
    int size;

public:
    DynArray(int sizeP) : arr(new int[sizeP] {}), size{ sizeP } {
        std::cout << "DynArray was constructed for " << size
            << "elements, for" << this << "\n";
    }

    DynArray() : DynArray(5) {}

    DynArray(const DynArray& object) : arr(new int[object.size]),
        size{ object.size } {
        std::cout << "DynArray copy constructor for " << size
            << "elements, for" << this << "\n";
    }

    DynArray(DynArray&& object) noexcept : arr{ object.arr }, size{ object.size } {
        object.arr = nullptr;
        object.size = 0;
        std::cout << "DynArray move constructor for " << size
            << "elements, for" << this << "\n";
    }

    DynArray& operator=(const DynArray& object) {
        if (!(this == &object)) {
            if (size != object.size) {
                delete arr;
                arr = new int[object.size];
            }
            size = object.size;
            int* dest{ arr };
            int* src{ object.arr };
            int* const end{ arr + size };
            while (dest < end) {
                *dest++ = *src++;
            }

        }
        std::cout << "DynArray copy assigned for " << size
            << "elements, for " << this << "\n";
        return *this;
    }
    DynArray& operator=(DynArray&& object) noexcept {
        if (!(this == &object))
        {
            delete[] arr;
            arr = object.arr;
            size = object.size;
            object.arr = nullptr;
            object.size = 0;
        }
        std::cout << "DynArray move assigned for " << size
            << "elements, for " << this << "\n";
        return *this;
    }


    int operator[](int ind) const {
        return arr[ind];
    }

    DynArray& operator()(int incr) {
        for (int i = 0; i < size; ++i) arr[i] += incr;
        return *this;
    }

    operator int() const {
        int sum = 0;
        for (int i = 0; i < size; ++i) sum += arr[i];
        return sum;
    }

    operator std::string() const {
        std::string str;
        for (int i = 0; i < size; ++i) {
            str += arr[i];
        }
        return str;
    }

    void setElem(int idx, int value) { arr[idx] = value; };

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    DynArray& randomize() {
        srand(time(0));
        for (int i = 0; i < size; ++i) arr[i] = rand() % 50;
        return *this;
    }


    ~DynArray() {
        std::cout << "Try to free memory from DynArray for " << arr << "pointer\n";
        delete[]arr;

        std::cout << "DynArray deconstructed for " << size
            << "elements, for " << this << "\n";
    }
};


int main()
{
    DynArray arr;
    arr.randomize().print();
    arr(10);
    arr.print();
    std::cout << int(arr) << std::endl;
    std::cout << std::string(arr) << std::endl;

}