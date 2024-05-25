#include <iostream>

class Flower {
    std::string type;
    int qty;
public:
    Flower(std::string type, int qty) : type(type), qty(qty) {}
    Flower() : Flower("", 0) {}

    Flower& operator+=(int incrQty) {
        qty += incrQty;
        return (*this);
    }

    int operator()() const {
        return qty;
    }

    std::string getType() const {
        return type;
    }
    friend std::ostream;
};

std::ostream& operator<<(Flower& fl, std::ostream& stream) {
    stream << fl.getType() << std::endl;
    return stream;
}

class Bouquet {
    static const size_t maxQty = 21;
    size_t curQty;
    Flower bouqFl[maxQty];
public:
    Bouquet& operator+=(Flower fl) {
        if (curQty + fl() > maxQty) {
            std::cout << "Can't add flowers to this bouquet." << std::endl;
            return *this;
        }
        else {
            int ind = findFlowerType(fl.getType());
            if (ind != -1) bouqFl[ind] += fl();
            std::cout << "Added flowers" << std::endl;
        }
    }

    Flower& operator[](int ind) {
        return bouqFl[ind];
    }

    int getCurQty() const {
        return curQty;
    }

    int findFlowerType(std::string type) {
        for (int i = 0; i < maxQty; ++i) {
            if (bouqFl[i].getType() == type) return i;
        }
        return -1;
    }
    friend std::ostream;
};

std::ostream& operator<<(Bouquet& bq, std::ostream& stream) {
    stream << "There are flowers in the bouquet:" << std::endl;
    for (int i = 0; i < bq.getCurQty(); ++i) {
        stream << bq[i].getType() << "\tQty: " << bq[i]() << std::endl;
    }
    return stream;
}

class FlowerShop {
    static const size_t maxTypes = 10;
    size_t flCntr;
    Flower flowers[maxTypes];
public:
    FlowerShop() {
        flCntr = 0;
        for (int i = 0; i < maxTypes; ++i) {
            flowers[i] = Flower();
        }
    }

};

int main()
{
    FlowerShop shop;

}