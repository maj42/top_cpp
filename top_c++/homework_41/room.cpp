#pragma once

#include <string>

class Room {
    std::string name;
    float height;
    float width;
    float length;
    bool coverCeiling;

public:
    void setHeight(float hgt) {
        height = hgt;
    }

    void setWidth(float wd) {
        width = wd;
    }

    void setLength(float ln) {
        length = ln;
    }

    void setCeil(bool bl) {
        coverCeiling = bl;
    }

    float getWallsSize() const {
        return 2 * height * width + 2 * length * height + (coverCeiling ? 2 : 1) * width * length;
    }
};
