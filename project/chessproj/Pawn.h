//
//  Pawn.h
//  chessproj
//
//  Created by Oskar Kaluziak on 27/05/2023.
//

#ifndef Pawn_h
#define Pawnh
#include "Color.h"
#include "Square.h"
#include "ChessPiece.h"
class Pawn : public ChessPiece {
public:
    Pawn(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override;
    void capture(ChessPiece* piece) override;

    char getSymbol() const override;
};

#endif /* Pawn_h */
