//
//  main.cpp
//  bioproject
//
//  Created by Oskar Kaluziak on 24/04/2023.
//


#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

#include <iostream>
#include <vector>

using namespace std;

enum class Color { White, Black };

class Piece {
public:
    Piece(Color color, int row, int col) : color(color), row(row), col(col) {}

    virtual bool isValidMove(int newRow, int newCol) const = 0;

    Color getColor() const {
        return color;
    }

    int getRow() const {
        return row;
    }

    int getCol() const {
        return col;
    }

protected:
    Color color;
    int row, col;
};

class Pawn : public Piece {
public:
    Pawn(Color color, int row, int col) : Piece(color, row, col) {}

    bool isValidMove(int newRow, int newCol) const override {
        if (newCol != col) {
            // can only move diagonally to capture
            return newRow == row + (color == Color::White ? -1 : 1) && abs(newCol - col) == 1;
        } else {
            // can move one or two squares forward on first move, one square forward on subsequent moves
            int distance = newRow - row;
            if (color == Color::White) {
                return (distance == -1 || (distance == -2 && row == 6)) && col == newCol;
            } else {
                return (distance == 1 || (distance == 2 && row == 1)) && col == newCol;
            }
        }
    }
};

class Knight : public Piece {
public:
    Knight(Color color, int row, int col) : Piece(color, row, col) {}

    bool isValidMove(int newRow, int newCol) const override {
        int dr = abs(newRow - row);
        int dc = abs(newCol - col);
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
    }
};

    class Bishop : public Piece {
    public:
        Bishop(Color color, int row, int col) : Piece(color, row, col) {}

        bool isValidMove(int newRow, int newCol) const override {
            int dr = newRow - row;
            int dc = newCol - col;
            return abs(dr) == abs(dc);
        }
    };

    class Rook : public Piece {
    public:
        Rook(Color color, int row, int col) : Piece(color, row, col) {}

        bool isValidMove(int newRow, int newCol) const override {
            int dr = newRow - row;
            int dc = newCol - col;
            return dr == 0 || dc == 0;
        }
    };

    class Queen : public Piece {
    public:
        Queen(Color color, int row, int col) : Piece(color, row, col) {}

        bool isValidMove(int newRow, int newCol) const override {
            int dr = newRow - row;
            int dc = newCol - col;
            return dr == 0 || dc == 0 || abs(dr) == abs(dc);
        }
    };

    class King : public Piece {
    public:
        King(Color color, int row, int col) : Piece(color, row, col) {}

        bool isValidMove(int newRow, int newCol) const override {
            int dr = abs(newRow - row);
            int dc = abs(newCol - col);
            return (dr == 1 && dc <= 1) || (dc == 1 && dr <= 1);
        }
    };

    class Board {
    public:
        Board() {
            // initialize pieces
            for (int row = 0; row < 8; ++row
