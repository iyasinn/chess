#pragma once

#include <iostream>
#include <istream>
#include "Board.h"
#include "Piece.h"
#include <set>
#include <map>

const std::string reset("\033[0m");
const std::string red("\033[1;31m");
const std::string cyan("\033[1;36m");
const std::string whiteLow("\033[0;37m");
const std::string blackLow("\033[0;30m");
const std::string whiteHigh("\033[1;37m");
const std::string blackHigh("\033[1;30m");
const std::string blackBackground("\033[1;40m");

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

void movePiece(std::ostream& os){
    os << "\nPlease enter your move\n";
    int startRow, endRow = 1;
    char startCol, endCol = 'a';

    std::cin >> startCol >> startRow >> endCol >> endRow;

    board.movePiece(startRow, startCol - 96, endRow, endCol - 96);



}

// Maybe a validate move and a make move? A)ctually first let's make a constructor

private: 

friend std::ostream& operator<<(std::ostream& os, const Chess& board);
std::set<Piece*> movedPieces;
Board<Piece, BOARD_SIZE> board;
std::string turnColor = WHITE;
Piece* whiteKing = nullptr;
Piece* blackKing = nullptr;

};


inline void switchColor(std::string color, std::ostream& os){
    os << color;
}

inline std::ostream& operator<<(std::ostream& os, const Chess& chess){

    const Board<Piece, BOARD_SIZE>& board = chess.board;

    // std::map<std::string, std::string> outputs = {{KING, " ♔  "}, {QUEEN, " ♕  "}, 
    //                                            {PAWN, " ♙  "}, {ROOK, " ♖  "}, 
    //                                            {BISHOP, " ♗  "}, {KNIGHT, " ♘  "}};

    std::map<std::string, std::string> outputs = {{KING, "♔"}, {QUEEN, "♕"}, 
                                               {PAWN, "♙"}, {ROOK, "♖"}, 
                                               {BISHOP, "♗"}, {KNIGHT, "♘"}};

    // Starting at top row
    for (int row = BOARD_SIZE; row >= 1; row--){

        // Centering with 7 spaces and remove it if you don't want to center
        os << "\n " << "       ";
        switchColor(whiteHigh, os);
        os << row << " \033[1;40m ";
        switchColor(reset, os);

        std::string squareColor = row % 2 == 0 ? "white" : "black";

        for (int col = 1; col <= BOARD_SIZE; col++){

            if (squareColor == "white") switchColor(whiteLow, os);
            else switchColor(blackLow, os);
            os << "[";

            if (board(row, col)){
                if (board(row, col)->getColor() == WHITE) switchColor(cyan, os);
                else switchColor(red, os);

                os << outputs[chess.board(row, col)->getName()];
            }
            else {
                os << " ";
            }

            if (squareColor == "white") switchColor(whiteLow, os);
            else switchColor(blackLow, os);
            os << " ] ";
            switchColor(reset, os);

            if (squareColor == "white") squareColor = "black";
            else squareColor = "white";
        }

        // Adds another row for better spacing
        if (row == 1) break; 

        os << "\n          ";
        switchColor(blackBackground, os);
        os << " ";
        switchColor(reset, os);
    }

    // Remove 7 spaces to remove it
    os << "\n          ";
    switchColor(blackBackground, os);
    os << " "; 
    switchColor(reset, os);

    for (int col = 1; col <= BOARD_SIZE; col++){
        switchColor(blackLow, os);
        os << "▆▆▆▆";
        switchColor(reset, os);
    }

    os << blackLow << "▆▆▆▆▆▆▆" << reset;

    os << "\n    ";
    // Centering
    os << "       ";
    switchColor(whiteHigh, os);

    for (char col = 'a'; col < 'a' + BOARD_SIZE; col++){
        os << " " << col << "   ";
    }
    
    switchColor(reset, os);

    return os;
}