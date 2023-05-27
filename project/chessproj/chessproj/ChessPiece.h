//
//  ChessPiece.h
//  chessproj
//
//  Created by Oskar Kaluziak on 27/05/2023.
//

#ifndef ChessPiece_h
#define ChessPiece_h
class ChessPiece {
public:
    ChessPiece(Color color, Square position) : color_(color), position_(position) {}
    
    virtual void move(Square newPosition) = 0;
    
    virtual void capture(ChessPiece* piece) = 0;
    
    virtual char getSymbol() const = 0;
    
protected:
    Color color_;
    Square position_;
};

#endif /* ChessPiece_h */
