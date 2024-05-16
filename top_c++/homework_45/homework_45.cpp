#include <iostream>

class Airplane {
    std::string model;
    unsigned maxPass;
    unsigned pass;
public:
    Airplane(std::string model, unsigned maxPass) : model(model), maxPass(maxPass), pass(0) {}

    Airplane(const Airplane&& other) noexcept : model(other.model), maxPass(other.maxPass), pass(other.pass) {}

    bool operator==(const Airplane& other) const {
        return model == other.model;
    }

    Airplane& operator++() {
        if (pass == maxPass) {
            std::cout << "No more passengers!" << std::endl;
            return *this;
        }
        pass++;
        return *this;
    }

    Airplane& operator++(int) {
        if (pass == maxPass) {
            std::cout << "No more passengers!" << std::endl;
            return *this;
        }
        pass++;
        return *this;
    }

    Airplane& operator--() {
        if (pass == 0) {
            std::cout << "No passengers left!" << std::endl;
            return *this;
        }
        pass--;
        return *this;
    }

    Airplane& operator--(int) {
        if (pass == 0) {
            std::cout << "No passengers left!" << std::endl;
            return *this;
        }
        pass--;
        return *this;
    }

    bool operator>(const Airplane& other) const {
        return maxPass > other.maxPass;
    }

    unsigned getPass() const{
        return pass;
    }
};

int main()
{
    Airplane boeing1("boeing", 100);
    Airplane boeing2("boeing", 200);
    Airplane notBoeing("some_other", 50);

    std::cout << std::boolalpha << (boeing1 == boeing2) << std::endl;
    std::cout << std::boolalpha << (boeing1 == notBoeing) << std::endl;

    std::cout << boeing1.getPass() << std::endl;
    std::cout << (boeing1++).getPass() << std::endl;
    --boeing1;
    boeing1--;

    std::cout << std::boolalpha << (boeing1 > notBoeing) << std::endl;
}
