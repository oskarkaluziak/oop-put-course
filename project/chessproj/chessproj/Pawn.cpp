//
//  Pawn.cpp
//  chessproj
//
//  Created by Oskar Kaluziak on 27/05/2023.
//

#include "Pawn.h"

void Pawn::move(Square newPosition) {
    int deltaX = newPosition.getX() - position.getX();
        int deltaY = newPosition.getY() - position.getY();

        if (color == Color::White) {
            if (deltaX == 0 && deltaY == 1) {
                position = newPosition;
            } else if (deltaX == 0 && deltaY == 2 && position.getY() == 1) {
                position = newPosition;
            } else {
                std::cout << "Invalid pawn move!" << std::endl;
            }
        } else {
            if (deltaX == 0 && deltaY == -1) {
                position = newPosition;
            } else if (deltaX == 0 && deltaY == -2 && position.getY() == 6) {
                position = newPosition;
            } else {
                std::cout << "Invalid pawn move!" << std::endl;
            }
        }
}

char Pawn::getSymbol() {
    return (color_ == Color::White) ? 'P' : 'p';
}
