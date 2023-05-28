
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <fstream>
#include "Color.h"
#include "Square.h"
#include "ChessPiece.h"
#include "Pawn.hpp"

class Rook : public ChessPiece{
public:
    Rook(Color color, Square position) : ChessPiece(color, position) {}
    void move(Square newPosition) override{
        int chnX = newPosition.x() - position_.x();
        int chnY = newPosition.y() - position_.y();
        if ((chnX == 0 && chnY != 0) || (chnX != 0 && chnY == 0)){
            position_ = newPosition;
        }
        else{
            std::cout << "Referee: Invalid rook move! Undo the move." << std::endl;
            return;
        }
    }
    bool isValidMove(Square newPosition) const override{
        int chnX = newPosition.x() - position_.x();
        int chnY = newPosition.y() - position_.y();
        if ((chnX == 0 && chnY != 0) || (chnX != 0 && chnY == 0)){
            return true;
        }
        return false;
    }
    char Symbol() const override{
        return (color_ == Color::White) ? 'R' : 'r';
    }
    void testRookIsValidMove()
    {
        Rook rook(Color::White, Square(0, 0));
        assert(rook.isValidMove(Square(4, 0)) == true);
        assert(rook.isValidMove(Square(0, 4)) == true);
        assert(rook.isValidMove(Square(1, 1)) == false);
        assert(rook.isValidMove(Square(4, 4)) == false);
        assert(rook.isValidMove(Square(1, 0)) == false);
        assert(rook.isValidMove(Square(0, 0)) == false);
        assert(rook.isValidMove(Square(2, 2)) == false);
        assert(rook.isValidMove(Square(-1, 0)) == false);
        assert(rook.isValidMove(Square(0, -1)) == false);
        assert(rook.isValidMove(Square(5, 0)) == false);
        assert(rook.isValidMove(Square(0, 5)) == false);
        std::cout << "All tests passed for Rook::isValidMove()." << std::endl;
    }
};

class Knight : public ChessPiece{
public:
    Knight(Color color, Square position) : ChessPiece(color, position) {}
    void move(Square newPosition) override{
        int chnX = std::abs(newPosition.x() - position_.x());
        int chnY = std::abs(newPosition.y() - position_.y());
        if ((chnX == 2 && chnY == 1) || (chnX == 1 && chnY == 2)){
            position_ = newPosition;
        }
        else{
            std::cout << "Referee: Invalid knight move! Undo the move." << std::endl;
            return;
        }
    }
    bool isValidMove(Square newPosition) const override{
        int chnX = std::abs(newPosition.x() - position_.x());
        int chnY = std::abs(newPosition.y() - position_.y());
        if ((chnX == 2 && chnY == 2) || (chnX == 2 && chnY == 1)){
            return true;
        }
        return false;
    }
    char Symbol() const override{
        return (color_ == Color::White) ? 'H' : 'h';
    }
};

class Bishop : public ChessPiece{
public:
    Bishop(Color color, Square position) : ChessPiece(color, position) {}
    void move(Square newPosition) override{
        int chnX = abs(newPosition.x() - position_.x());
        int chnY = abs(newPosition.y() - position_.y());
        if (chnX == chnY){
            position_ = newPosition;
        }
        else{
            std::cout << "Referee: Invalid bishop move! Undo the move." << std::endl;
            return;
        }
    }
    bool isValidMove(Square newPosition) const override {
        int chnX = std::abs(newPosition.x() - position_.x());
        int chnY = std::abs(newPosition.y() - position_.y());
        if (chnX == chnY){
            return true;
        }
        return false;
    }
    char Symbol() const override{
        return (color_ == Color::White) ? 'B' : 'b';
    }
};

class King : public ChessPiece{
public:
    King(Color color, Square position) : ChessPiece(color, position) {}
    void move(Square newPosition) override{
        int chnX = abs(newPosition.x() - position_.x());
        int chnY = abs(newPosition.y() - position_.y());
        if ((chnX <= 1 && chnY <= 1) && (chnX != 0 || chnY != 0)){
            position_ = newPosition;
        }
        else{
            std::cout << "Referee: Invalid king move! Undo the move." << std::endl;
            return;
        }
    }
    bool isValidMove(Square newPosition) const override{
        int chnX = std::abs(newPosition.x() - position_.x());
        int chnY = std::abs(newPosition.y() - position_.y());
        if ((chnX <= 1 && chnY <= 1) && (chnX != 0 || chnY != 0)){
               return true;
        }
        return false;
    }
    char Symbol() const override{
        return (color_ == Color::White) ? 'K' : 'k';
    }
};


class Queen : public ChessPiece{
public:
    Queen(Color color, Square position) : ChessPiece(color, position) {}
    void move(Square newPosition) override{
        if (isPathClear(newPosition)){
            position_ = newPosition;
        }
        else{
            std::cout << "Referee: Invalid queen move! Undo the move." << std::endl;
            return;
        }
    }
    bool isValidMove(Square newPosition) const override{
        int chnX = std::abs(newPosition.x() - position_.x());
        int chnY = std::abs(newPosition.y() - position_.y());
        if (chnX == 0 || chnY == 0 || chnX == chnY){
            return true;
        }
        return false;
    }
    char Symbol() const override{
        return (color_ == Color::White) ? 'Q' : 'q';
    }
private:
    bool isPathClear(Square newPosition){
        int chnX = std::abs(newPosition.x() - position_.x());
        int chnY = std::abs(newPosition.y() - position_.y());
        if (chnX == 0 || chnY == 0 || chnX == chnY){
            return true;
        }
        return false;
    }
};

class Board{
public:
    Board(){
        initializeBoard();
    }
    void print() const{
        std::cout << "  a b c d e f g h" << std::endl;
        for (int y = 7; y >= 0; --y){
            std::cout << y + 1 << " ";
            for (int x = 0; x < 8; ++x){
                ChessPiece* piece = board_[x][y];
                if (piece){
                    std::cout << piece->Symbol() << " ";
                }
                else{
                    std::cout << "- ";
                }
            }
            std::cout << y + 1 << std::endl;
        }
        std::cout << "  a b c d e f g h" << std::endl;
    }
    ChessPiece* receivePieceAtPosition(Square position){
        if (isValidPosition(position)){
            return board_[position.x()][position.y()];
        }
        return nullptr;
    }
    void removePieceAtPosition(Square position){
        if (isValidPosition(position)){
            board_[position.x()][position.y()] = nullptr;
        }
    }
    void movePiece(Square from, Square to){
        ChessPiece* piece = receivePieceAtPosition(from);
        if (piece){
            try{
                piece->move(to);
                board_[to.x()][to.y()] = piece;
                board_[from.x()][from.y()] = nullptr;
            }
            catch (const std::exception& e){
                std::cout << "Referee: " << e.what() << " Undo the move." << std::endl;
                return;
            }
        }
        else{
            std::cout << "There is no piece at the specified position. Please try again." << std::endl;
            return;
        }
}

private:
    ChessPiece* board_[8][8];
    void initializeBoard(){
        // White
        board_[0][0] = new Rook(Color::White, Square(0, 0));
        board_[1][0] = new Knight(Color::White, Square(1, 0));
        board_[2][0] = new Bishop(Color::White, Square(2, 0));
        board_[3][0] = new Queen(Color::White, Square(3, 0));
        board_[4][0] = new King(Color::White, Square(4, 0));
        board_[5][0] = new Bishop(Color::White, Square(5, 0));
        board_[6][0] = new Knight(Color::White, Square(6, 0));
        board_[7][0] = new Rook(Color::White, Square(7, 0));
        // White pawns
        for (int x = 0; x < 8; ++x){
            board_[x][1] = new Pawn(Color::White, Square(x, 1));
            }

        // Black
        board_[0][7] = new Rook(Color::Black, Square(0, 7));
        board_[1][7] = new Knight(Color::Black, Square(1, 7));
        board_[2][7] = new Bishop(Color::Black, Square(2, 7));
        board_[3][7] = new Queen(Color::Black, Square(3, 7));
        board_[4][7] = new King(Color::Black, Square(4, 7));
        board_[5][7] = new Bishop(Color::Black, Square(5, 7));
        board_[6][7] = new Knight(Color::Black, Square(6, 7));
        board_[7][7] = new Rook(Color::Black, Square(7, 7));
        // Black pawns
        for (int x = 0; x < 8; ++x){
            board_[x][6] = new Pawn(Color::Black, Square(x, 6));
        }
        // Filling empty spaces
        for (int x = 0; x < 8; ++x){
            for (int y = 2; y < 6; ++y){
                board_[x][y] = nullptr;
            }
        }
    }
    bool isValidPosition(Square position){
        int x = position.x();
        int y = position.y();
        return (x >= 0 && x < 8 && y >= 0 && y < 8);
    }
};

int main() {
    std::cout << "Chess Game\n" << "Remember about fair-play, don't start the game without a referee\n\n";
    Board board;
    board.print();
    std::string input;
    while (true){
        std::cout << "Enter your move (for example: a2-a4), 'load' to load a game from a file, or 'quit' to exit: ";
        std::cin >> input;
        if (input == "quit" || input == "exit"){
            break;
        }
        else if (input == "load"){
            std::cout << "Enter the name of the file to load: ";
            std::string fileName;
            std::cin >> fileName;
            std::ifstream inputFile(fileName);
            if (inputFile.is_open()){
                // File example: "R a4", "P d4", "p d6", etc.
                std::string pieceCode, positionCode;
                while (inputFile >> pieceCode >> positionCode){
                    char symbol = pieceCode[0];
                    Color color = (pieceCode[1] == 'w') ? Color::White : Color::Black;
                    int x = positionCode[0] - 'a';
                    int y = positionCode[1] - '1';
                    Square position(x, y);
                    ChessPiece* piece = nullptr;
                    switch (symbol){
                        case 'R':
                        case 'r':
                            piece = new Rook(color, position);
                            break;
                        case 'H':
                        case 'h':
                            piece = new Knight(color, position);
                            break;
                        case 'B':
                        case 'b':
                            piece = new Bishop(color, position);
                            break;
                        case 'Q':
                        case 'q':
                            piece = new Queen(color, position);
                            break;
                        case 'K':
                        case 'k':
                            piece = new King(color, position);
                            break;
                        case 'P':
                        case 'p':
                            piece = new Pawn(color, position);
                            break;
                    }
                    if (piece){
                        board.removePieceAtPosition(position);
                        board.receivePieceAtPosition(position);
                    }
                }
                inputFile.close();
                board.print();
            }
            else{
                std::cout << "Unable to open the file. Please try again." << std::endl;
            }
            continue;
        }
        if (input.size() != 5 || input[2] != '-'){
            std::cout << "Invalid move format. Please try again." << std::endl;
            continue;
        }
        Square from(input[0] - 'a', input[1] - '1');
        Square to(input[3] - 'a', input[4] - '1');
        ChessPiece* piece = board.receivePieceAtPosition(from);
        if (piece == nullptr){
            std::cout << "There is no piece at the specified position. Please try again." << std::endl;
            continue;
        }
        board.movePiece(from, to);
        board.print();
    }
    return 0;
}
