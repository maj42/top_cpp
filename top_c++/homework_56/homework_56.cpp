#include <iostream>

class Transport {
public:
    Transport() : dailyMaintCost(0), dailyFuelCost(0) {}
    double dailyFuelCost;
    double dailyMaintCost;
    virtual double calculateDailyCost() = 0;
};

class Auto : public Transport {
    double dailyMileage;
public:
    Auto(int dailyMileage) : Transport(), dailyMileage(dailyMileage) {
        dailyFuelCost = 52;
        dailyMaintCost = 100;
    }
    double calculateDailyCost() {
        return dailyMileage * dailyFuelCost + dailyMaintCost;
    }
};

class Moto : public Transport {
    int dailyRides;
public:
    Moto(int dailyRides) : Transport(), dailyRides(dailyRides) {
        dailyFuelCost = 52;
        dailyMaintCost = 30;
    }
    double calculateDailyCost() {
        return dailyRides * dailyFuelCost * 10;
    }
};

class Bike : public Transport {
public:
    Bike() : Transport() {
        dailyMaintCost = 5;
    }

    double calculateDailyCost() {
        return dailyMaintCost;
    }
};

std::ostream& operator<< (std::ostream& os, Transport& vehicle) {
    os << vehicle.calculateDailyCost();
    return os;
}

int main()
{
    Auto car{100};
    Moto moto{ 3 };
    Bike bike{};

    std::cout << "Daily cost:\n\tCar: " << car << "\n\tMoto: " << moto << "\n\tBike: " << bike << std::endl;
}