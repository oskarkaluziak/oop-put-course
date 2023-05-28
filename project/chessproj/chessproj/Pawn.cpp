//
//  Pawn.cpp
//  chessproj
//
//  Created by Oskar Kaluziak on 24/05/2023.
//

#include "Pawn.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
Pawn::Pawn(Color color, Square position) : ChessPiece(color, position) {}

void Pawn::move(Square newPosition) {
    int chnX = newPosition.x() - position_.x();
    int chnY = newPosition.y() - position_.y();

    if (color_ == Color::White) {
        if (chnX == 0 && chnY == 1) {
            position_ = newPosition;
        } else if (chnX == 0 && chnY == 2 && position_.y() == 1) {
            position_ = newPosition;
        } else {
            std::cout << "Referee: Invalid pawn move! Undo the move." << std::endl;
            return;
        }
    } else {
        if (chnX == 0 && chnY == -1) {
            position_ = newPosition;
        } else if (chnX == 0 && chnY == -2 && position_.y() == 6) {
            position_ = newPosition;
        } else {
            std::cout << "Referee: Invalid pawn move! Undo the move." << std::endl;
            return;
        }
    }
}

bool Pawn::isValidMove(Square newPosition) const {
    int chnX = newPosition.x() - position_.x();
    int chnY = newPosition.y() - position_.y();

    if (color_ == Color::White) {
        if (chnX == 0 && (chnY == 1 || (chnY == 2 && position_.y() == 1))) {
            return true;
        }
    } else {
        if (chnX == 0 && (chnY == -1 || (chnY == -2 && position_.y() == 6))) {
            return true;
        }
    }

    return false;
}

char Pawn::Symbol() const {
    return (color_ == Color::White) ? 'P' : 'p';
}
