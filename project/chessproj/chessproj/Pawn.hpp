//
//  Pawn.hpp
//  chessproj
//
//  Created by Oskar Kaluziak on 24/05/2023.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include <stdio.h>
#include "Color.h"
#include "Square.h"
#include "ChessPiece.h"

class Pawn : public ChessPiece {
public:
    Pawn(Color color, Square position);

    void move(Square newPosition) override;
    bool isValidMove(Square newPosition) const override;
    char Symbol() const override;
};

#endif /* Pawn_hpp */
