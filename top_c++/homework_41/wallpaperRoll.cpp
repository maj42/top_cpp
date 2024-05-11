#pragma once

#include <string>

class WallpaperRoll {
    std::string name;
    float width;
    float length;
    float price;

public:

    WallpaperRoll(float w, float l, float pr) : name("Roll"), width(w), length(l), price(pr) {}

    float getPrice() const {
        return price;
    }

    float getRollSize() const {
        return length * width;
    }
};
