//
//  Board.cpp
//  chessproj
//
//  Created by Oskar Kaluziak on 27/05/2023.
//

#include <stdio.h>
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
