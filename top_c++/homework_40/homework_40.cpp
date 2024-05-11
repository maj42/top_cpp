#include <iostream>

class Lift {
    int lowFloor{};
    int highFloor{};
    bool powerOn{ false };
    int currentFloor{};

public:
    Lift(int low, int high) {
        if (low > high) {
            lowFloor = high;
            highFloor = low;
        }
        else {
            lowFloor = low;
            highFloor = high;
        }
        currentFloor = lowFloor;
    }

    bool powered() {
        return powerOn;
    }

    int where() {
        return currentFloor;
    }

    void pressPowerButton() {
        powerOn ? powerOn = false : powerOn = true;
    }

    void go(int destFloor) {
        if (!powerOn) {
            std::cout << "Lift is not powered" << std::endl;
            return;
        }
        if (destFloor < lowFloor) destFloor = lowFloor;
        if (destFloor > highFloor) destFloor = highFloor;
        std::cout << "Going to " << destFloor << " floor..." << std::endl;
        currentFloor = destFloor;
    }
};

int main()
{
    Lift lift1(1, 10);
    Lift lift2(8, 2);
    std::cout << std::boolalpha << "First lift: powered: " << lift1.powered() << "\tCurrent floor: " << lift1.where() << std::endl;
    std::cout << std::boolalpha << "Second lift: powered: " << lift2.powered() << "\tCurrent floor: " << lift2.where() << std::endl;
    lift1.pressPowerButton();
    lift1.go(8);
    lift2.go(232);
    std::cout << std::boolalpha << "First lift: powered: " << lift1.powered() << "\tCurrent floor: " << lift1.where() << std::endl;
    std::cout << std::boolalpha << "Second lift: powered: " << lift2.powered() << "\tCurrent floor: " << lift2.where() << std::endl;

    return 0;
}