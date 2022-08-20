#pragma once

#include <iostream>
#include <istream>
#include "Board.h"
#include "Piece.h"
#include <set>



const int BOARD_SIZE = 8;

class Chess{

public:

Chess(){
    for (auto color : {WHITE, BLACK}){
        int row = (color == WHITE) ? 1 : 8;

        int column = 1;
        for (auto name : {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}){
            board.placePiece(pieceFactory(name, color), row, column);
            column++;
        }

        for (int column = 1; column <= BOARD_SIZE; column++){
            int pawnRow = color == WHITE ? 2 : 7;
            board.placePiece(pieceFactory(PAWN, color), pawnRow, column);
        }
    }
}

// Maybe a validate move and a make move? Actually first let's make a constructor

private: 

friend std::ostream& operator<<(std::ostream& os, const Chess& board);
std::set<Piece*> movedPieces;
Board<Piece, BOARD_SIZE> board;
std::string turnColor = "white";
Piece* whiteKing = nullptr;
Piece* blackKing = nullptr;

};


inline void printPiece(Piece* ptr, std::ostream& os){
    
    // Will print red
    os << "\033[1;31m";

    // If white then print cyan
    if (ptr->getColor() == WHITE){
        os << "\033[1;36m";
    }

    if (ptr->getName() == QUEEN){
        os << " ♛  ";
    }
    else if (ptr->getName() == KING){
        os << " ♚  ";
    }
    else if (ptr->getName() == PAWN){
        os << " ♟  ";
    }
    else if (ptr->getName() == BISHOP){
        os << " ♝  ";
    }
    else if (ptr->getName() == KNIGHT){
        os << " ♞  ";
    }
    else if (ptr->getName() == ROOK){
        os << " ♜  ";
    }

    os << "\033[0m";
    return;
}

inline std::ostream& operator<<(std::ostream& os, const Chess& chess){

    // Starting at top row
    for (int row = BOARD_SIZE; row >= 1; row--){
        
        os << "\n \033[1;37m" << row << " \033[1;40m \033[0m";

        // Now iterating through each row
        for (int col = 1; col <= BOARD_SIZE; col++){
            
            if (chess.board(row, col)){
                printPiece(chess.board(row, col), os);
            }
            else {
                os << "  ";
            }

        }

        if (row != 1) os << "\n   \033[1;40m \033[0m";
    }

    os << "\n    ";

    for (int col = 1; col <= BOARD_SIZE; col++){
        os << "__";
    }
    
    os << std::endl;
    os << "    ";

    for (int col = 1; col <= BOARD_SIZE; col++){
        os << " " << col << "  ";
    }

    return os;



}