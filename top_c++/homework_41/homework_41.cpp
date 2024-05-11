#include <iostream>
#include <list>
#include "Header.h"

int main()
{
    int rooms;
    std::cout << "Enter the number of rooms: ";
    std::cin >> rooms;

    Flat flat;
    float temp;
    char key;

    // Fill flat with rooms
    for (int i = 0; i < rooms; ++i) {
        Room* curRoom = new Room();
        std::cout << "Room " << i + 1 << std::endl;
        std::cout << "Enter room's heigth: ";
        std::cin >> temp;
        curRoom->setHeight(temp);
        std::cout << "Enter room's width: ";
        std::cin >> temp;
        curRoom->setWidth(temp);
        std::cout << "Enter room's length: ";
        std::cin >> temp;
        curRoom->setLength(temp);
        std::cout << "Do you need wallpapers on ceiling? y/n ";
        std::cin >> key;
        (key == 'y' || key == 'Y') ? curRoom->setCeil(true) : curRoom->setCeil(false);
        flat.getList().push_back(*curRoom);
        delete curRoom;
    }
    // Create wallpaper
    WallpaperRoll roll{ 1, 5, 500 };

    // Calculate rolls quantity
    float rolls = flat.calculateSize() / roll.getRollSize();
    
    // Make rolls an integer
    int rollsInt;
    (rolls == (int)rolls) ? rollsInt = rolls : rollsInt = rolls + 1;

    std::cout << "You'll need " << rollsInt << " wallpaper rolls. Total price is " << rollsInt * roll.getPrice();
}
