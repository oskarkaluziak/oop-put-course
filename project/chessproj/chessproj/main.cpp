#include <iostream>
#include <vector>
#include <cmath>
#include "Color.h"
#include "Square.h"
#include "ChessPiece.h"
class Pawn : public ChessPiece {
public:
    Pawn(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override {
        int deltaX = newPosition.getX() - position_.getX();
        int deltaY = newPosition.getY() - position_.getY();

        if (color_ == Color::White) {
            if (deltaX == 0 && deltaY == 1) {
                position_ = newPosition;
            } else if (deltaX == 0 && deltaY == 2 && position_.getY() == 1) {
                position_ = newPosition;
            } else {
                std::cout << "Invalid pawn move!" << std::endl;
            }
        } else {
            if (deltaX == 0 && deltaY == -1) {
                position_ = newPosition;
            } else if (deltaX == 0 && deltaY == -2 && position_.getY() == 6) {
                position_ = newPosition;
            } else {
                std::cout << "Invalid pawn move!" << std::endl;
            }
        }
    }
    void capture(ChessPiece* piece) override {
    }
    
    char getSymbol() const override {
        return (color_ == Color::White) ? 'P' : 'p';
    }
};

class Rook : public ChessPiece {
public:
    Rook(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override {
        int deltaX = newPosition.getX() - position_.getX();
        int deltaY = newPosition.getY() - position_.getY();
        if (deltaX == 0 && deltaY != 0) {
              int step = (deltaY > 0) ? 1 : -1;
              for (int y = position_.getY() + step; y != newPosition.getY(); y += step) {
                  //if (board_->getPieceAtPosition(Square(position_.getX(), y)) != nullptr) {
                     // std::cout << "Rook cannot jump over other pieces." << std::endl;
                    //  return;
                 // }
              }
              position_ = newPosition;
          } else if (deltaX != 0 && deltaY == 0) {
              int step = (deltaX > 0) ? 1 : -1;
              for (int x = position_.getX() + step; x != newPosition.getX(); x += step) {
                  //if (board_->getPieceAtPosition(Square(x, position_.getY())) != nullptr) {
                     // std::cout << "Rook cannot jump over other pieces." << std::endl;
                    //  return;
                  //}
              }
              position_ = newPosition;
          } else {
              std::cout << "Invalid rook move!" << std::endl;
          }
      }

    void capture(ChessPiece* piece) override {
    }

    char getSymbol() const override {
        return (color_ == Color::White) ? 'R' : 'r';
    }
};
class Knight : public ChessPiece {
public:
    Knight(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override {
        int deltaX = abs(newPosition.getX() - position_.getX());
        int deltaY = abs(newPosition.getY() - position_.getY());

        if ((deltaX == 1 && deltaY == 2) || (deltaX == 2 && deltaY == 1)) {
            position_ = newPosition;
        } else {
            std::cout << "Invalid knight move!" << std::endl;
        }
    }

    void capture(ChessPiece* piece) override {
    }

    char getSymbol() const override {
        return (color_ == Color::White) ? 'H' : 'h';
    }
};

class Bishop : public ChessPiece {
public:
    Bishop(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override {
        int deltaX = abs(newPosition.getX() - position_.getX());
        int deltaY = abs(newPosition.getY() - position_.getY());

        if (deltaX == deltaY) {
            position_ = newPosition;
        } else {
            std::cout << "Invalid bishop move!" << std::endl;
        }
    }

    void capture(ChessPiece* piece) override {
    }

    char getSymbol() const override {
        return (color_ == Color::White) ? 'B' : 'b';
    }
};

class King : public ChessPiece {
public:
    King(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override {
        int deltaX = abs(newPosition.getX() - position_.getX());
        int deltaY = abs(newPosition.getY() - position_.getY());

        if ((deltaX <= 1 && deltaY <= 1) && (deltaX != 0 || deltaY != 0)) {
            position_ = newPosition;
        } else {
            std::cout << "Invalid king move!" << std::endl;
        }
    }

    void capture(ChessPiece* piece) override {
    }

    char getSymbol() const override {
        return (color_ == Color::White) ? 'K' : 'k';
    }
};


class Queen : public ChessPiece {
public:
    Queen(Color color, Square position) : ChessPiece(color, position) {}

    void move(Square newPosition) override {
        if (isPathClear(newPosition)) {
            position_ = newPosition;
        } else {
            std::cout << "Invalid queen move!" << std::endl;
        }
    }

    void capture(ChessPiece* piece) override {
    }

    char getSymbol() const override {
        return (color_ == Color::White) ? 'Q' : 'q';
    }

private:
    bool isPathClear(Square newPosition) {
        int deltaX = std::abs(newPosition.getX() - position_.getX());
        int deltaY = std::abs(newPosition.getY() - position_.getY());

        if (deltaX == 0 || deltaY == 0 || deltaX == deltaY) {
            return true;
        }

        return false;
    }
};

class Board {
public:
    Board() {
        initializeBoard();
    }

    void print() const {
        std::cout << "  a b c d e f g h" << std::endl;
        for (int y = 7; y >= 0; --y) {
            std::cout << y + 1 << " ";
            for (int x = 0; x < 8; ++x) {
                ChessPiece* piece = board_[x][y];
                if (piece) {
                    std::cout << piece->getSymbol() << " ";
                } else {
                    std::cout << "- ";
                }
            }
            std::cout << y + 1 << std::endl;
        }
        std::cout << "  a b c d e f g h" << std::endl;
    }

    ChessPiece* getPieceAtPosition(Square position) {
        if (isValidPosition(position)) {
            return board_[position.getX()][position.getY()];
        }
        return nullptr;
    }

    void removePieceAtPosition(Square position) {
        if (isValidPosition(position)) {
            board_[position.getX()][position.getY()] = nullptr;
        }
    }
    void movePiece(Square from, Square to) {
            ChessPiece* piece = getPieceAtPosition(from);
            if (piece) {
                piece->move(to);
                board_[to.getX()][to.getY()] = piece;
                board_[from.getX()][from.getY()] = nullptr;
            }
    }

private:
    ChessPiece* board_[8][8];
    std::vector<std::string> moves_;

    void initializeBoard() {
        // White
        board_[0][0] = new Rook(Color::White, Square(0, 0));
        board_[1][0] = new Knight(Color::White, Square(1, 0));
        board_[2][0] = new Bishop(Color::White, Square(2, 0));
        board_[3][0] = new Queen(Color::White, Square(3, 0));
        board_[4][0] = new King(Color::White, Square(4, 0));
        board_[5][0] = new Bishop(Color::White, Square(5, 0));
        board_[6][0] = new Knight(Color::White, Square(6, 0));
        board_[7][0] = new Rook(Color::White, Square(7, 0));

        for (int x = 0; x < 8; ++x) {
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

        for (int x = 0; x < 8; ++x) {
            board_[x][6] = new Pawn(Color::Black, Square(x, 6));
            }
        
        for (int x = 0; x < 8; ++x) {
                for (int y = 2; y < 6; ++y) {
                    board_[x][y] = nullptr;
                }
            }
    }

    bool isValidPosition(Square position) {
        int x = position.getX();
        int y = position.getY();
        return (x >= 0 && x < 8 && y >= 0 && y < 8);
    }
    void recordMove(const std::string& move) {
            moves_.push_back(move);
        }

    void displayMoves() const {
            std::cout << "Moves: ";
            for (const auto& move : moves_) {
                std::cout << move << " ";
            }
            std::cout << std::endl;
        }
};

int main() {
    std::cout << "Chess Game\n" <<"The game should be officiated in full chess rules.\n\n";
    Board board;
    board.print();

    std::string input;
    while (true) {
        std::cout << "Enter your move (for example: a2-a4): ";
        std::getline(std::cin, input);

        if (input == "quit" || input == "exit")
            break;

        if (input.size() != 5 || input[2] != '-') {
            std::cout << "Invalid move format. Please try again." << std::endl;
            continue;
        }

        Square from(input[0] - 'a', input[1] - '1');
        Square to(input[3] - 'a', input[4] - '1');

        ChessPiece* piece = board.getPieceAtPosition(from);
        if (piece == nullptr) {
            std::cout << "There is no piece at the specified position. Please try again." << std::endl;
            continue;
        }

        board.movePiece(from, to);
        board.print();
    }

    return 0;
}
