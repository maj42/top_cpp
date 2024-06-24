#include <iostream>
#include <vector>
#include <string>

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

    friend std::ostream& operator<<(std::ostream& stream, const Flower& fl);
};

std::ostream& operator<<(std::ostream& stream, const Flower& fl) {
    stream << fl.getType() << " (Qty: " << fl.qty << ")";
    return stream;
}

class Bouquet {
    static const size_t maxQty = 21;
    size_t curQty;
    Flower bouqFl[maxQty];
public:
    Bouquet() : curQty(0) {}

    Bouquet& operator+=(const Flower& fl) {
        if (curQty + fl() > maxQty) {
            std::cout << "Can't add flowers to this bouquet." << std::endl;
            return *this;
        }
        int ind = findFlowerType(fl.getType());
        if (ind != -1) bouqFl[ind] += fl();
        else bouqFl[curQty++] = fl;
        std::cout << "Added flowers" << std::endl;
        return *this;
    }

    Flower& operator[](size_t ind) {
        return bouqFl[ind];
    }

    size_t getCurQty() const {
        return curQty;
    }

    int findFlowerType(const std::string& type) const {
        for (size_t i = 0; i < curQty; ++i) {
            if (bouqFl[i].getType() == type) return i;
        }
        return -1;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Bouquet& bq);
};

std::ostream& operator<<(std::ostream& stream, const Bouquet& bq) {
    stream << "There are flowers in the bouquet:" << std::endl;
    for (size_t i = 0; i < bq.getCurQty(); ++i) {
        stream << bq.bouqFl[i] << std::endl;
    }
    return stream;
}

class FlowerShop {
    static const size_t maxTypes = 10;
    size_t flCntr;
    Flower flowers[maxTypes];

    int findFlowerType(const std::string& type) const {
        for (size_t i = 0; i < flCntr; ++i) {
            if (flowers[i].getType() == type) return i;
        }
        return -1;
    }
public:
    FlowerShop() : flCntr(0) {}

    void addFlowerToInventory(const Flower& flower) {
        int ind = findFlowerType(flower.getType());
        if (ind != -1) {
            flowers[ind] += flower();
        }
        else {
            if (flCntr < maxTypes) {
                flowers[flCntr++] = flower;
            }
            else {
                std::cout << "No space for new flower types in inventory." << std::endl;
            }
        }
    }

    void displayInventory() const {
        std::cout << "Current Inventory:" << std::endl;
        for (size_t i = 0; i < flCntr; ++i) {
            std::cout << flowers[i] << std::endl;
        }
    }

    Bouquet createBouquet(const std::vector<Flower>& bouquetFlowers) {
        Bouquet bouquet;
        for (const auto& flower : bouquetFlowers) {
            int ind = findFlowerType(flower.getType());
            if (ind != -1 && flowers[ind]() >= flower()) {
                flowers[ind] += -flower();
                bouquet += flower;
            }
            else {
                std::cerr << "Insufficient quantity for flower type: " << flower.getType() << "\n";
            }
        }
        return bouquet;
    }

    void orderFlowers(const Flower& flower) {
        int ind = findFlowerType(flower.getType());
        if (ind != -1) {
            flowers[ind] += flower();
        }
        else {
            if (flCntr < maxTypes) {
                flowers[flCntr++] = flower;
            }
            else {
                std::cout << "No space for new flower types in inventory." << std::endl;
            }
        }
    }
};

int main() {
    Flower rose("Rose", 10);
    Flower tulip("Tulip", 5);
    Flower lily("Lily", 7);

    FlowerShop shop;
    shop.addFlowerToInventory(rose);
    shop.addFlowerToInventory(tulip);
    shop.addFlowerToInventory(lily);

    shop.displayInventory();

    std::vector<Flower> bouquetFlowers = { Flower("Rose", 5), Flower("Tulip", 3) };
    Bouquet bouquet = shop.createBouquet(bouquetFlowers);

    std::cout << bouquet;

    shop.orderFlowers(Flower("Rose", 20));
    shop.orderFlowers(Flower("Tulip", 15));

    shop.displayInventory();

    return 0;
}
