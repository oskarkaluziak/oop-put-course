//
//  Square.cpp
//  chessproj
//
//  Created by Oskar Kaluziak on 27/05/2023.
//

#include "Square.hpp"
#include "Square.h"

Square::Square(int x, int y) : x_(x), y_(y) {}

int Square::getX() const {
    return x_;
}

int Square::getY() const {
    return y_;
}
