#pragma once

#include <list>
#include "room.cpp"

class Flat {
    std::list<Room> roomsList;

public:
    float calculateSize() const {
        float totalSize{ 0 };
        for (const Room& room : roomsList) {
            totalSize += room.getWallsSize();
        }
        return totalSize;
    }

    std::list<Room>& getList() {
        return roomsList;
    }
};