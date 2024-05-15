#include <iostream>

class IntegerSet {
    int* set;
    size_t size;
public:
    IntegerSet(int* newSet, size_t newSize) : size(newSize) {
        int* tempSet = new int[newSize];
        tempSet[0] = newSet[0];
        for (int i = 0; i < newSize; ++i) {
            for (int j = 0; j < i; ++j) {
                if (newSet[j] == newSet[i]) {
                    size--;
                    continue;
                };
                tempSet[i] = newSet[i];
            }
        }
        set = new int[size];
        for (int i = 0; i < size; ++i) set[i] = tempSet[i];
        delete[] tempSet;
    }

    IntegerSet() {
        size = 1;
        set = new int[size] {0};
    }

    IntegerSet(const IntegerSet& other) {
        size = other.size;
        set = new int[size] {};
        for (int i = 0; i < size; ++i) set[i] = other.set[i];
    }

    ~IntegerSet() { if (set != nullptr) delete[] set; }

    size_t getSize() { return size; }

    int getElem(int ind) { return set[ind]; }

    bool contains(int element) const {
        for (int i = 0; i < size; ++i) {
            if (set[i] == element) return true;
        }
        return false;
    }

    void operator+=(int element) {
        if (this->contains(element)) {
            return;
        }
        int* newSet = new int[size + 1];
        for (int i = 0; i < size; ++i) newSet[i] = set[i];
        newSet[size++] = element;
        delete[] set;
        set = newSet;
    }

    IntegerSet operator+(const IntegerSet& other) {
        int newSize = size + other.size;
        int* newSet = new int[newSize];
        for (int i = 0; i < size; ++i) {
            newSet[i] = set[i];
        }
        for (int i = 0; i < other.size; ++i) {
            newSet[size + i] = other.set[i];
        }
        IntegerSet newIntSet(newSet, newSize);
        delete[] newSet;
        return newIntSet;
    }

    void operator-(int element) {
        if (this->contains(element) && size > 0) {
            int* newSet = new int[size - 1];
            for (int i = 0, j = 0; i < size; ++i) {
                if (set[i] == element) { continue; }
                newSet[j++] = set[i];
            }
            delete[] set;
            set = new int[--size];
            for (int i = 0; i < size; ++i) set[i] = newSet[i];
            delete[] newSet;
        }
    }

    IntegerSet operator-(const IntegerSet& other) {
        int newSize = size;
        int* newSet = new int[size];
        bool unique;
        for (int i = 0, k = 0; i < size; ++i) {
            unique = true;
            for (int j = 0; j < other.size; ++j) {
                if (set[i] == other.set[j]) {
                    unique = false;
                }
            }
            if (unique) newSet[k++] = set[i];
            else newSize--;
        }
        IntegerSet newIntSet(newSet, newSize);
        delete[] newSet;
        return newIntSet;
    }

    IntegerSet operator*(const IntegerSet& other) {
        int newSize = size;
        int* newSet = new int[size];
        bool unique;
        for (int i = 0, k = 0; i < size; ++i) {
            unique = true;
            for (int j = 0; j < other.size; ++j) {
                if (set[i] == other.set[j]) {
                    unique = false;
                }
            }
            if (!unique) newSet[k++] = set[i];
            else newSize--;
        }
        IntegerSet newIntSet(newSet, newSize);
        delete[] newSet;
        return newIntSet;
    }

    void operator=(const IntegerSet& other) {
        delete[] set;
        size = other.size;
        set = new int[size];
        for (int i = 0; i < size; ++i) set[i] = other.set[i];
    }

    bool operator==(const IntegerSet& other) {
        if (size != other.size) return false;
        for (int i = 0; i < size; ++i) {
            if (!this->contains(other.set[i])) return false;
        }
        return true;
    }
};

int main()
{
    IntegerSet set1;
    int temp[6]{1, 2, 3, 1, 2, 3};
    IntegerSet set2(temp, 3);
    for (int i = 0; i < set2.getSize(); ++i) std::cout << set2.getElem(i) << "\t";
    std::cout << std::endl;

    // contains
    std::cout << std::boolalpha << set2.contains(3) << std::endl;

    // +=
    set1 += 10;
    for (int i = 0; i < set1.getSize(); ++i) std::cout << set1.getElem(i) << "\t";
    std::cout << std::endl;

    // +
    IntegerSet setUnion = set1 + set2;
    for (int i = 0; i < setUnion.getSize(); ++i) std::cout << setUnion.getElem(i) << "\t";
    std::cout << std::endl;

    // - element
    set1 - 10;
    for (int i = 0; i < set1.getSize(); ++i) std::cout << set1.getElem(i) << "\t";
    std::cout << std::endl;
    
    set1 += 10;
    set1 += 2;
    set1 += 3;

    // - set difference
    IntegerSet setDiff = set1 - set2;
    for (int i = 0; i < setDiff.getSize(); ++i) std::cout << setDiff.getElem(i) << "\t";
    std::cout << std::endl;

    // *
    IntegerSet setInter = set1 * set2;
    for (int i = 0; i < setInter.getSize(); ++i) std::cout << setInter.getElem(i) << "\t";
    std::cout << std::endl;

    // =
    set1 = set2;
    std::cout << "set1\tset2" << std::endl;
    for (int i = 0; i < set1.getSize(); ++i) std::cout << set1.getElem(i) << "\t" << set2.getElem(i) << std::endl;
    std::cout << std::endl;

    // ==
    std::cout << std::boolalpha << (set1 == set2) << std::endl;
}
