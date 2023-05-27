//
//  ChessPiece.cpp
//  chessproj
//
//  Created by Oskar Kaluziak on 27/05/2023.
//

#include <stdio.h>
#include "ChessPiece.h"

ChessPiece::ChessPiece(Color color, Square position) : color_(color), position_(position) {}

ChessPiece::~ChessPiece() {}
